from django.urls import path
from detection.views.oj import DetectionAPI, DetectionDetailAPI, DetectionCompareAPI,DetectionAIGCDetailAPI




urlpatterns = [
    path('problem/<str:problem_id>/detection/', DetectionAPI.as_view(), name='detection_list'),
    path('problem/<str:problem_id>/detection/<str:detection_id>/', DetectionDetailAPI.as_view(),
         name='detection_detail'),
    path('problem/<str:problem_id>/detection/<str:detection_id>/compare/', DetectionCompareAPI.as_view(),
         name='detection_compare'),
    path('problem/<str:problem_id>/detectionAIGC/<str:detection_id>/', DetectionAIGCDetailAPI.as_view(),
         name='detection_aigc_detail')
]
