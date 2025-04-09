from django.db import models
from utils.models import JSONField
from problem.models import Problem
from account.models import User
from submission.models import Submission  # 确保正确引用Submission模型

from django.db import models
# 导入 Django 的模型模块，用于定义数据模型

from utils.models import JSONField
# 导入自定义的 JSONField 字段，用于存储结构化 JSON 数据；
# 这里用于存储代码匹配的行号信息

from problem.models import Problem
# 引入题目模型，查重任务需要关联到具体的题目

from account.models import User
# 引入用户模型，用于记录查重任务创建者

from submission.models import Submission  # 确保正确引用Submission模型
# 引入提交模型，因查重对比需要涉及两次代码提交的信息

from utils.shortcuts import rand_str  # 导入生成随机字符串的辅助函数，用于生成任务的唯一 ID


class DetectionStatus:
    """
    查重任务状态常量定义

    定义了查重任务的几种状态：
      - pending: 表示任务已创建，但还未开始处理
      - running: 任务正在运行中
      - finished: 任务已完成所有比对工作
      - failed: 任务在执行过程中发生错误或异常，未能完成

    STATUS_CHOICES 元组用于配置 Django 模型字段的 choices 参数，
    这样在界面上显示时可以提供描述性的中文标签。
    """
    PENDING = '待处理'  # 等待查重
    RUNNING = '处理中'  # 查重进行中
    FINISHED = '完成'  # 查重完成
    FAILED = '失败'  # 查重失败

    STATUS_CHOICES = (
        (PENDING, '待处理'),
        (RUNNING, '处理中'),
        (FINISHED, '完成'),
        (FAILED, '失败'),
    )


class Detection(models.Model):
    """
    代码查重任务模型

    存储一个查重任务的所有配置、状态及统计信息，
    每个任务都关联到具体的题目以及任务的发起人，
    并包含查重配置参数（如语言、相似度阈值）以及任务状态信息。
    """
    # 任务唯一标识，使用32位随机字符串生成
    id = models.TextField(
        max_length=32,
        default=rand_str,  # 每次创建任务时用 rand_str() 生成唯一 ID
        primary_key=True,  # 设为主键，确保每个任务有唯一标识
        db_index=True
    )

    # 关联竞赛信息：指定当前查重任务属于哪个竞赛（可选）
    contest = models.ForeignKey(
        'contest.Contest',  # 假设 Contest 模型在 contest app 中
        on_delete=models.SET_NULL,  # 如果竞赛被删除，将 contest 字段设为 NULL
        null=True,  # 允许为空
        blank=True,  # 在表单中可选
        default=None,  # 默认为 None 表示没有关联竞赛
        related_name='detections',  # 反向关联名称
    )

    # 关联题目信息：指定当前查重任务对应的是哪一道题
    problem = models.ForeignKey(
        Problem,
        null=True,  # 允许为空
        blank=True,  # 在表单中可选
        default=None,  # 默认为 None 表示没有关联竞赛
        on_delete=models.CASCADE,  # 级联删除：若题目删除，则对应的任务也会被一并删除
        related_name='detections',  # 反向关联名称：可以通过 Problem 对象来访问其所有查重任务
    )

    # 标题
    title = models.TextField()

    # 创建时间
    created_at = models.DateTimeField(auto_now_add=True)

    # 查重语言
    language = models.TextField()

    # 相似度阈值
    similarity_threshold = models.FloatField()

    # 运行状态信息
    status = models.TextField(
        choices=DetectionStatus.STATUS_CHOICES,
        default=DetectionStatus.PENDING,
        db_index=True,
    )

    # 文件数量
    file_count = models.PositiveIntegerField(default=0)

    # 创建人
    created_by = models.ForeignKey(User, on_delete=models.CASCADE, related_name='detections')

    # 查重
    submissions = models.ManyToManyField('submission.Submission', blank=True, related_name="detection_tasks")

    class Meta:
        db_table = "detection"
        # 指定数据库中表的名称为 detection
        ordering = ("-created_at",)
        # 默认按照任务创建时间降序排列，新任务会更靠前

    def __str__(self):
        # 返回一个格式化字符串，包含任务状态和标题，用于日志和管理界面显示
        return self.id


class DetectionComparison(models.Model):
    """
    支持多段行号比对的查重结果模型
    存储格式示例：
    lines_a = "2-22;5-10" (表示2-22行和5-10行两个匹配段)
    """
    detection = models.ForeignKey(
        Detection,
        on_delete=models.CASCADE,
        related_name='comparisons',
    )

    problem = models.ForeignKey(
        Problem,
        on_delete=models.CASCADE,
        related_name='detection_comparisons',
        null=True,
        blank=True,
    )

    language = models.TextField(null=True)

    # 用户信息
    user_a_id = models.IntegerField(db_index=True, default=0)
    user_a_code = models.TextField(default="")
    user_b_id = models.IntegerField(db_index=True, default=0)
    user_b_code = models.TextField(default="")

    # 匹配行号（多段用分号分隔）
    lines_a = models.TextField(default="")
    lines_b = models.TextField(default="")

    # 比对结果
    similarity = models.FloatField()
    created_at = models.DateTimeField(auto_now_add=True)

    class Meta:
        db_table = "detection_comparison"
        ordering = ("-created_at",)
        unique_together = [
            ['detection', 'user_a_id', 'user_b_id', 'lines_a', 'lines_b']
        ]

    def __str__(self):
        return f"{self.user_a_id}[{self.lines_a}] ↔ {self.user_b_id}[{self.lines_b}]"

    def save(self, *args, **kwargs):
        if self.user_a_id > self.user_b_id:
            self._swap_users()
        super().save(*args, **kwargs)

    def _swap_users(self):
        self.user_a_id, self.user_b_id = self.user_b_id, self.user_a_id
        self.user_a_code, self.user_b_code = self.user_b_code, self.user_a_code
        self.lines_a, self.lines_b = self.lines_b, self.lines_a

    def get_line_sections(self, user='a'):
        """
        获取指定用户的行号段列表
        返回: [{'start':2, 'end':22}, {'start':5, 'end':10}]
        """
        line_str = self.lines_a if user.lower() == 'a' else self.lines_b
        sections = []
        for part in line_str.split(';'):
            if '-' in part:
                start, end = map(int, part.split('-'))
                sections.append({'start': start, 'end': end})
        return sections

    def get_merged_lines(self, user='a'):
        """
        获取指定用户的合并行号列表
        返回: [2,3,...,22,5,6,...,10]
        """
        sections = self.get_line_sections(user)
        merged = []
        for sec in sections:
            merged.extend(range(sec['start'], sec['end'] + 1))
        return merged

    def get_formatted_ranges(self):
        """获取格式化的匹配信息"""
        return (
            f"user{self.user_a_id} {self.lines_a.replace(';', ',')} "
            f"↔ user{self.user_b_id} {self.lines_b.replace(';', ',')}"
        )

    def get_code_snippets(self):
        return {
            'a': {'code': self.user_a_code, 'language': self.language},
            'b': {'code': self.user_b_code, 'language': self.language}
        }
