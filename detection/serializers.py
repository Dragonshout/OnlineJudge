# serializers.py

from rest_framework import serializers
from detection.models import Detection, DetectionComparison, AIGCDetectionResult
from problem.models import Problem
from account.models import User
from submission.models import Submission


class DetectionSerializer(serializers.ModelSerializer):
    created_by = serializers.PrimaryKeyRelatedField(read_only=True)
    created_at = serializers.DateTimeField(format="%Y-%m-%d %H:%M:%S", read_only=True)

    class Meta:
        model = Detection
        fields = [
            "id",
            "problem",
            "contest",
            "title",
            "created_at",
            "language",
            "similarity_threshold",
            "status",
            "file_count",
            "created_by",
            "algorithm_params"
        ]
        read_only_fields = ["id", "created_at", "created_by"]


class DetectionComparisonSerializer(serializers.ModelSerializer):
    # 调用模型自定义的方法用 SerializerMethodField 暴露代码片段
    code_snippets = serializers.SerializerMethodField()

    class Meta:
        model = DetectionComparison
        fields = [
            "id",
            "detection",  # 外键可以直接显示 pk，也可以用嵌套序列化类
            "submission_a",
            "submission_b",
            "similarity",
            "matched_lines",  # JSONField 可以直接被 DRF 处理为字典
            "created_at",
            "code_snippets",  # 通过方法获得代码对比片段
        ]
        read_only_fields = ["id", "created_at", "code_snippets"]

    def get_code_snippets(self, obj):
        return obj.get_code_snippets()


class AIGCDetectionResultSerializer(serializers.ModelSerializer):
    # 调用模型自定义的方法用 SerializerMethodField 暴露代码片段
    code_snippets = serializers.SerializerMethodField()

    class Meta:
        model = AIGCDetectionResult
        fields = [
            "id",
            "detection",  # 外键可以直接显示 pk，也可以用嵌套序列化类
            "user_id",
            "user_code",
            "similarity",
            "created_at",
        ]
        read_only_fields = ["id", "created_at"]
