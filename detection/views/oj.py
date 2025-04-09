# detection/views/oj.py
from django.db.models import Max, F

from account.decorators import login_required, detection_detail_permission_required
from account.models import User
from detection.models import DetectionComparison
from utils.api import APIView
from rest_framework.permissions import IsAuthenticated
from problem.models import Problem
from detection.serializers import DetectionSerializer
from submission.models import Submission, JudgeStatus  # 导入提交模型
from detection.tasks import do_detection


class DetectionAPI(APIView):
    permission_classes = [IsAuthenticated]

    @login_required
    @detection_detail_permission_required
    def get(self, request, problem_id, *args, **kwargs):
        """
        根据题目 id 获取该题目的所有查重任务。
        前端请求 URL 示例： /api/problem/<str:id>/detection/
        返回格式为 { "data": [...] }
        """
        # 根据题目 id 查询对应的题目对象
        try:
            # 注意此处使用 pk，根据你的模型确定，如果题目的主键为字符串，则用 get(pk=id)
            problem = Problem.objects.get(_id=problem_id)
        except Problem.DoesNotExist:
            return self.error("题目不存在")

        # 获取该题目下的所有查重任务，通过 related_name 'detections' （在 Detection 模型中定义）
        detections = problem.detections.all().order_by("-created_at")
        # 序列化数据，many=True 表示序列化多个对象
        serializer = DetectionSerializer(detections, many=True)
        # 返回数据放在 data 键下，这样前端可以通过 res.data.data 获取到查重列表

        return self.success(serializer.data)

    @login_required
    @detection_detail_permission_required
    def post(self, request, problem_id, *args, **kwargs):
        try:
            # 这里假设 Problem 模型的 pk 是字符串类型
            problem = Problem.objects.get(_id=problem_id)
        except Problem.DoesNotExist:
            return self.error("题目不存在")

        # 根据 problem 查询关联提交数量，且只统计 result==0 的提交
        check_language = request.data.get("checkLanguage")
        if check_language != "全部":
            submissions = Submission.objects.filter(problem=problem, result=JudgeStatus.ACCEPTED,
                                                    language=check_language)
        else:
            submissions = Submission.objects.filter(problem=problem, result=JudgeStatus.ACCEPTED)

        submissions = submissions.order_by('user_id', 'create_time').distinct('user_id')
        submission_count = submissions.count()

        data = request.data.copy()

        data["problem"] = problem.pk  # 外键字段
        data["language"] = data.pop("checkLanguage", None)
        data["similarity_threshold"] = data.pop("similarityThreshold", None)
        data["title"] = data.pop("problemID", None)
        data["file_count"] = submission_count  # 设置提交数量，只统计 result==0 的记录

        serializer = DetectionSerializer(data=data)

        if serializer.is_valid():
            if submission_count > 0:
                # 保存检测记录
                detection = serializer.save(created_by=request.user)
                detection.submissions.set(submissions)
                # 异步触发查重任务，传入 detection 对象的 pk
                do_detection.send(detection.id)
                return self.success("已提交查重")
            else:
                return self.success("没有需要查重的代码")

        return self.error("题目不存在")


class DetectionDetailAPI(APIView):
    permission_classes = [IsAuthenticated]

    @login_required
    @detection_detail_permission_required
    def get(self, request, problem_id, detection_id):
        try:
            # 1. 获取所有查重记录
            comparisons = DetectionComparison.objects.filter(
                detection_id=detection_id
            )
            if not comparisons.exists():
                return self.error("未找到查重记录")

            # 2. 获取所有涉及的用户ID（包括user_a和user_b）
            all_user_ids = set(
                list(comparisons.values_list('user_a_id', flat=True)) +
                list(comparisons.values_list('user_b_id', flat=True))
            )

            # 3. 批量查询所有用户名
            users_map = {
                user.id: user.username
                for user in User.objects.filter(id__in=all_user_ids)
            }

            # 4. 为每个用户构建查重记录（包含作为user_a和user_b的记录）
            result_users = []
            for user_id in all_user_ids:
                # 作为user_a的记录（A->B）
                as_user_a = comparisons.filter(user_a_id=user_id)
                # 作为user_b的记录（B->A）
                as_user_b = comparisons.filter(user_b_id=user_id)

                # 合并所有相关记录
                all_records = []
                for comp in as_user_a:
                    all_records.append({
                        'other_user_id': comp.user_b_id,
                        'similarity': comp.similarity,
                        'lines': comp.lines_a,
                        'other_lines': comp.lines_b,
                    })

                for comp in as_user_b:
                    all_records.append({
                        'other_user_id': comp.user_a_id,
                        'similarity': comp.similarity,
                        'lines': comp.lines_b,
                        'other_lines': comp.lines_a,
                    })

                # 按相似度排序
                all_records.sort(key=lambda x: x['similarity'], reverse=True)

                # 构建details列表
                details = []
                for record in all_records:
                    details.append({
                        "id": record['other_user_id'],
                        "name": users_map.get(record['other_user_id'], f"用户{record['other_user_id']}"),
                        "similarity": round(record['similarity'] * 100, 2),
                    })

                # 计算该用户的最高相似度
                max_similarity = max(
                    [rec['similarity'] for rec in all_records] or [0]
                )

                result_users.append({
                    "id": user_id,
                    "name": users_map.get(user_id, f"用户{user_id}"),
                    "similarity": round(max_similarity * 100, 2),
                    "details": details,
                })

            # 按最高相似度排序用户列表
            result_users.sort(key=lambda x: x['similarity'], reverse=True)

            return self.success({
                "users": result_users
            })

        except Exception as e:
            return self.error(f"查询失败: {str(e)}")


class DetectionCompareAPI(APIView):
    permission_classes = [IsAuthenticated]

    @login_required
    @detection_detail_permission_required
    def get(self, request, problem_id, detection_id):
        """
        对应前端的 getComparisonDetail 方法
        参数: user1, user2 (来自query_params)
        返回格式: { "data": { comparison: {...} } }
        """
        try:
            user1 = request.GET.get('user1')
            user2 = request.GET.get('user2')

            if not all([user1, user2]):
                return self.error("需要提供两个用户ID")

            try:
                user1_id = int(user1)
                user2_id = int(user2)
            except ValueError:
                return self.error("用户ID必须为整数")

            # 获取具体的比对记录
            comparison = DetectionComparison.objects.filter(
                detection_id=detection_id,
                user_a_id=min(user1_id, user2_id),
                user_b_id=max(user1_id, user2_id)
            ).first()

            if not comparison:
                return self.error("未找到比对记录")

            from account.models import User
            user_ids = {comparison.user_a_id, comparison.user_b_id}
            users = User.objects.filter(id__in=user_ids)
            user_map = {user.id: user for user in users}

            result = {
                'user1': {
                    'id': comparison.user_a_id,
                    'name': user_map.get(comparison.user_a_id, f"用户{comparison.user_a_id}").username,
                    'code': comparison.user_a_code,
                    'matched_lines': comparison.lines_a,
                    'date': comparison.created_at.strftime("%Y-%m-%d %H:%M"),
                },
                'user2': {
                    'id': comparison.user_b_id,
                    'name': user_map.get(comparison.user_b_id, f"用户{comparison.user_b_id}").username,
                    'code': comparison.user_b_code,
                    'matched_lines': comparison.lines_b,
                    'date': comparison.created_at.strftime("%Y-%m-%d %H:%M"),
                },
                'similarity': round(comparison.similarity * 100, 2),  # 转为百分比
                'language': comparison.language
            }

            return self.success({"comparison": result})

        except Exception as e:
            return self.error(str(e))
