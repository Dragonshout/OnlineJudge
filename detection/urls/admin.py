from django.urls import path
from ..views.admin import DetectionAPI, DetectionDetailAPI, DetectionCompareAPI

urlpatterns = [
    path('contest/<str:contest_id>/detection/', DetectionAPI.as_view(), name='detection_list'),
    path('contest/<str:contest_id>/detection/<str:detection_id>/', DetectionDetailAPI.as_view(),
         name='detection_detail'),
    path('problem/<str:contest_id>/detection/<str:detection_id>/compare/', DetectionCompareAPI.as_view(),
         name='detection_compare'),
]
