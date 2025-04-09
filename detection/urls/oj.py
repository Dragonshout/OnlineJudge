from django.urls import path
from detection.views.oj import DetectionAPI, DetectionDetailAPI, DetectionCompareAPI

urlpatterns = [
    path('problem/<str:problem_id>/detection/', DetectionAPI.as_view(), name='detection_list'),
    path('problem/<str:problem_id>/detection/<str:detection_id>/', DetectionDetailAPI.as_view(),
         name='detection_detail'),
    path('problem/<str:problem_id>/detection/<str:detection_id>/compare/', DetectionCompareAPI.as_view(),
         name='detection_compare'),
]
