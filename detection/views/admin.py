from collections import defaultdict


from account.decorators import login_required, detection_detail_permission_required
from account.models import User
from contest.models import Contest
from submission.models import Submission, JudgeStatus
from ..models import  DetectionComparison
from utils.api import APIView
from ..serializers import DetectionSerializer
from rest_framework.permissions import IsAuthenticated
from detection.tasks import do_detection


class DetectionAPI(APIView):
    permission_classes = [IsAuthenticated]

    @login_required
    @detection_detail_permission_required
    def get(self, request, contest_id, *args, **kwargs):
        try:
            contest = Contest.objects.get(id=contest_id)
        except Contest.DoesNotExist:
            return self.error("竞赛不存在")

        detections = contest.detections.all().order_by("-created_at")
        serializer = DetectionSerializer(detections, many=True)

        return self.success(serializer.data)

    @login_required
    @detection_detail_permission_required
    def post(self, request, contest_id, *args, **kwargs):
        try:
            contest = Contest.objects.get(id=contest_id)
        except Contest.DoesNotExist:
            return self.error("竞赛不存在")

        check_language = request.data.get("language")

        # 根据语言筛选提交记录
        if check_language != "全部":
            submissions = Submission.objects.filter(
                contest=contest,
                result=JudgeStatus.ACCEPTED,  # 假设 result=0 表示 ACCEPTED
                language=check_language
            )
        else:
            submissions = Submission.objects.filter(
                contest=contest,
                result=JudgeStatus.ACCEPTED
            )

        # 必须先把 user_id 放在 ORDER BY 的第一位才能使用 DISTINCT ON
        submissions = submissions.order_by('user_id', 'problem_id', '-create_time').distinct('user_id', 'problem_id')

        submission_count = submissions.count()

        data = request.data.copy()

        data["contest"] = contest.pk  # 外键字段
        data["title"] = data.pop("contestId", None)
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

        return self.error("查重失败")


class DetectionDetailAPI(APIView):
    permission_classes = [IsAuthenticated]

    @login_required
    @detection_detail_permission_required
    def get(self, request, contest_id, detection_id):
        try:
            # 1. 获取所有查重比较记录，并按问题分组
            comparisons = DetectionComparison.objects.filter(
                detection_id=detection_id
            ).select_related('detection', 'problem')  # 预取detection和problem信息

            if not comparisons:
                return self.error("未找到查重记录")

            # 2. 按问题ID分组比较记录
            problem_comparisons = defaultdict(list)
            for comp in comparisons:
                problem_comparisons[comp.problem_id].append(comp)

            # 3. 收集所有涉及的用户ID
            all_user_ids = set()
            for comp in comparisons:
                all_user_ids.add(comp.user_a_id)
                all_user_ids.add(comp.user_b_id)

            # 4. 批量查询用户信息
            users_map = {
                user.id: user.username
                for user in User.objects.filter(id__in=all_user_ids)
            }

            # 5. 获取detection关联的所有submissions（用于获取题目信息）
            detection = comparisons[0].detection
            submissions = detection.submissions.select_related('problem').all()

            # 6. 构建按问题分组的结果
            final_result = []

            for problem_id, comps in problem_comparisons.items():
                # 获取该问题的第一个submission作为代表（用于获取题目信息）
                problem_submission = next(
                    (sub for sub in submissions if sub.problem_id == problem_id),
                    None
                )

                if not problem_submission:
                    continue

                # 按用户分组该问题的比较结果
                user_results = defaultdict(list)
                for comp in comps:
                    # 用户A的信息
                    user_a_info = {
                        'id': comp.user_a_id,
                        'name': users_map.get(comp.user_a_id, f'用户{comp.user_a_id}'),
                        'similarity': round(comp.similarity * 100, 2),
                        'lines': comp.lines_a,
                        'code': comp.user_a_code
                    }

                    # 用户B的信息
                    user_b_info = {
                        'id': comp.user_b_id,
                        'name': users_map.get(comp.user_b_id, f'用户{comp.user_b_id}'),
                        'similarity': round(comp.similarity * 100, 2),
                        'lines': comp.lines_b,
                        'code': comp.user_b_code
                    }

                    user_results[comp.user_a_id].append(user_b_info)
                    user_results[comp.user_b_id].append(user_a_info)

                # 构建该问题的结果
                problem_result = {
                    'problem': {
                        'id': problem_submission.problem.id,
                        'title': problem_submission.problem.title
                    },
                    'users': []
                }

                # 添加该问题的用户比较结果
                for user_id, comparisons in user_results.items():
                    problem_result['users'].append({
                        'user': {
                            'id': user_id,
                            'name': users_map.get(user_id, f'用户{user_id}')
                        },
                        'comparisons': sorted(comparisons, key=lambda x: x['similarity'], reverse=True)
                    })

                final_result.append(problem_result)

            # 按问题ID排序
            final_result.sort(key=lambda x: x['problem']['id'])

            return self.success({
                "detection_id": detection_id,
                "results": final_result
            })

        except Exception as e:
            return self.error(f"查询失败: {str(e)}")


class DetectionCompareAPI(APIView):
    permission_classes = [IsAuthenticated]

    @login_required
    @detection_detail_permission_required
    def get(self, request, contest_id, detection_id):
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

