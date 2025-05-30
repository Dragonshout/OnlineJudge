import os
import re
import time
from collections import defaultdict

import dramatiq
from django.db import transaction

from detection.aigc import check_code_origin
from detection.models import Detection, DetectionComparison, AIGCDetectionResult
from oj import settings
from problem.models import Problem
from sim.runSIM import run_sim
from submission.models import Submission
from utils.shortcuts import DRAMATIQ_WORKER_ARGS

def prepare_detection_files(detection):
    """
    准备检测文件结构
    返回: (language_dirs, detection_dir)
    """
    detection.status = "运行中"
    detection.save()

    DETECTION_DATA_DIR = os.path.join(settings.DATA_DIR, "detection")
    detection_dir = os.path.join(DETECTION_DATA_DIR, f"detection_{detection.id}")
    os.makedirs(detection_dir, exist_ok=True)

    # 使用字典记录每种语言对应的所有问题目录
    language_info = defaultdict(lambda: {
        'language_dir': "",
        'problem_dirs': set()  # 明确指定为集合类型
    })

    submissions = detection.submissions.all()

    for submission in submissions:
        if submission.language == "Python3":
            continue

        # 按照语言创建主目录
        language_dir = os.path.join(detection_dir, submission.language)
        os.makedirs(language_dir, exist_ok=True)

        # 按照问题ID创建子目录
        problem_dir = os.path.join(language_dir, str(submission.problem_id))
        os.makedirs(problem_dir, exist_ok=True)

        # 记录语言和问题目录信息
        language_info[submission.language]['language_dir'] = language_dir
        language_info[submission.language]['problem_dirs'].add(problem_dir)  # 现在可以正确添加

        # 创建用户代码文件
        ext = get_file_extension(submission.language)
        filename = f"{submission.user_id}-{submission.problem_id}.{ext}"
        filepath = os.path.join(problem_dir, filename)

        with open(filepath, "w", encoding="utf-8") as f:
            f.write(submission.code)

    # 转换为列表格式返回
    language_dirs = [
        (lang, info['language_dir'], list(info['problem_dirs']))
        for lang, info in language_info.items()
    ]

    return language_dirs, detection_dir


def run_and_analyze_detection(detection, language_dirs):
    """
    执行查重并分析结果（轮流在每个问题子目录中执行）
    """
    try:
        for lang_name, lang_dir, problem_dirs in language_dirs:
            # 在每个问题子目录中执行查重
            for problem_dir in problem_dirs:
                # 执行查重
                run_sim(problem_dir, lang_name, detection.similarity_threshold)

                # 定义结果文件路径（现在位于问题子目录下）
                simple_path = os.path.join(problem_dir, "sim_res.txt")
                all_path = os.path.join(problem_dir, "sim_res_all.txt")

                try:
                    with open(simple_path, "r", encoding="utf-8") as f1, \
                            open(all_path, "r", encoding="utf-8") as f2:
                        res_simple = f1.read()
                        res_all = f2.read()

                    # 更新正则表达式以匹配新文件名格式 user_id-problem_id.ext
                    similarity_pattern = r"(\d+)-(\d+)\.\w+ consists for (\d+) % of (\d+)-(\d+)\.\w+"
                    similarity_matches = re.findall(similarity_pattern, res_simple)

                    line_match_pattern = r"""
                        (?P<user1>\d+)-(?P<problem1>\d+)\.\w+:\sline\s(?P<lines1>\d+-\d+)\s*\|
                        (?P<user2>\d+)-(?P<problem2>\d+)\.\w+:\sline\s(?P<lines2>\d+-\d+)
                    """

                    line_matches = list(re.finditer(line_match_pattern, res_all, re.VERBOSE))
                    line_match_dict = defaultdict(lambda: {'lines_a': [], 'lines_b': []})

                    for m in line_matches:
                        user1 = int(m.group('user1'))
                        user2 = int(m.group('user2'))

                        key = (user1, user2) if user1 < user2 else (user2, user1)

                        if user1 < user2:
                            line_match_dict[key]['lines_a'].append(m.group('lines1'))
                            line_match_dict[key]['lines_b'].append(m.group('lines2'))
                        else:
                            line_match_dict[key]['lines_a'].append(m.group('lines2'))
                            line_match_dict[key]['lines_b'].append(m.group('lines1'))

                    final_result = {
                        users: {
                            'lines_a': ';'.join(data['lines_a']),
                            'lines_b': ';'.join(data['lines_b'])
                        }
                        for users, data in line_match_dict.items()
                    }

                    for match in similarity_matches:
                        user1_id, problem1_id, similarity, user2_id, problem2_id = match  # 修正这里，提取similarity
                        try:
                            user1_id = int(user1_id)
                            user2_id = int(user2_id)
                            similarity = int(similarity)  # 将similarity转换为整数

                            # 获取当前检测任务的所有提交
                            detection_submissions = detection.submissions.all()

                            # 查找符合条件的提交（增加problem_id过滤）
                            submission_a = detection_submissions.get(
                                user_id=user1_id,
                                problem_id=problem1_id,  # 添加problem_id过滤
                                language=lang_name,
                            )
                            submission_b = detection_submissions.get(
                                user_id=user2_id,
                                problem_id=problem2_id,  # 添加problem_id过滤
                                language=lang_name,
                            )

                            # 获取对应的行号信息
                            match_key = (user1_id, user2_id) if user1_id < user2_id else (user2_id, user1_id)
                            lines_info = final_result.get(match_key, {'lines_a': '', 'lines_b': ''})

                            # 创建比较记录
                            DetectionComparison.objects.create(
                                detection=detection,
                                problem=submission_a.problem,
                                language=lang_name,
                                user_a_id=min(user1_id, user2_id),
                                user_b_id=max(user1_id, user2_id),
                                user_a_code=submission_a.code,
                                user_b_code=submission_b.code,
                                lines_a=lines_info['lines_a'] if user1_id < user2_id else lines_info['lines_b'],
                                lines_b=lines_info['lines_b'] if user1_id < user2_id else lines_info['lines_a'],
                                similarity=float(similarity) / 100,  # 将百分比转换为小数
                            )

                        except Submission.DoesNotExist:
                            print(
                                f"找不到匹配的提交: user1={user1_id}, problem1={problem1_id}, user2={user2_id}, problem2={problem2_id}")
                            continue
                        except Exception as e:
                            print(f"创建比较记录失败: {e}")
                            continue

                except FileNotFoundError:
                    print(f"警告：未找到结果文件（检查 {simple_path} 或 {all_path}）")
                    continue
                except Exception as e:
                    print(f"处理 {problem_dir} 时出错：{e}")
                    continue

    except Exception as e:
        print(f"查重发生错误！:{e}")
        return "error"
    finally:
        detection.status = "已完成"
        detection.save()
        return "success"



@dramatiq.actor(**DRAMATIQ_WORKER_ARGS())
def do_detection(detection_id):
    try:
        detection = Detection.objects.get(pk=detection_id)
    except Detection.DoesNotExist:
        print(f"Detection实例（ID: {detection_id}）不存在。")
        return "error"

    try:
        # 第一步：准备文件
        language_dirs, detection_dir = prepare_detection_files(detection)

        result = run_and_analyze_detection(detection, language_dirs)
        if result == "error":
            raise Exception("查重过程中发生错误")


    except Exception as e:
        detection.status = "失败"
        detection.error_message = str(e)
        detection.save()
        print(f"检测任务 {detection_id} 执行失败，错误信息：{str(e)}")
        raise


class AIGCDetectionDataPreparer:
    def __init__(self, detection):
        self.detection = detection
        self.detection.status = "运行中"
        self.detection.save()
        self.submissions = self.detection.submissions.all()

    def prepare_data(self):
        grouped_data = {}
        for submission in self.submissions:
            prob_id = str(submission.problem_id)
            if prob_id not in grouped_data:
                grouped_data[prob_id] = []
            record = {
                "submission_id": submission.id,
                "user_id": submission.user_id,
                "problem_id": submission.problem_id,
                "code": submission.code,
                "language": submission.language,
            }
            grouped_data[prob_id].append(record)
        return grouped_data


def do_aigc_detection(detection):
    preparer = AIGCDetectionDataPreparer(detection)
    grouped_data = preparer.prepare_data()

    # 计数器初始化
    request_count = 0
    sleep_interval = 30  # 每30次休息30秒
    sleep_duration = 30

    for prob_id, records in grouped_data.items():
        try:
            problem_instance = Problem.objects.get(pk=prob_id)
        except Problem.DoesNotExist:
            problem_instance = None

        for record in records:
            if record.get("language", "") != detection.language and detection.language != "全部":
                continue

            code = record.get("code", "")

            # 每30次请求后休息
            if request_count > 0 and request_count % sleep_interval == 0:
                time.sleep(sleep_duration)

            # 调用检测API
            similarity, result = check_code_origin(code)
            request_count += 1  # 增加计数器

            if result != "success":
                return "error"

            # 使用事务确保数据一致性
            with transaction.atomic():
                if similarity >= detection.similarity_threshold * 100:
                    AIGCDetectionResult.objects.create(
                        detection=detection,
                        problem=problem_instance,
                        user_id=record.get("user_id", ""),
                        user_code=record.get("code", ""),
                        language=record.get("language"),
                        similarity=similarity
                    )

    return "success"

@dramatiq.actor(**DRAMATIQ_WORKER_ARGS())
def aigc_detection(detection_id):
    try:
        detection = Detection.objects.get(pk=detection_id)
    except Detection.DoesNotExist:
        print(f"Detection实例（ID: {detection_id}）不存在。")
        return "error"

    try:
        result = do_aigc_detection(detection)

        if result == "error":
            detection.status = "失败"
        else:
            detection.status = "已完成"
        detection.save()
        print(f"检测任务 {detection_id} 执行成功,结果为:{detection.status}")

    except Exception as e:
        detection.status = "失败"
        detection.error_message = str(e)
        detection.save()
        print(f"检测任务 {detection_id} 执行失败，错误信息：{str(e)}")
        raise


def get_file_extension(language):
    """根据编程语言返回合适的文件扩展名"""
    extension_map = {
        "C++": "cpp",
        "Java": "java",
        "C": "c",
    }
    return extension_map.get(language, "txt")  # 默认使用txt扩展名
