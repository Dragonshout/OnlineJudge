from django.conf.urls import include, url

urlpatterns = [
    url(r"^api/", include("account.urls.oj")),  # 账户
    url(r"^api/admin/", include("account.urls.admin")),
    url(r"^api/", include("announcement.urls.oj")),  # 公告
    url(r"^api/admin/", include("announcement.urls.admin")),
    url(r"^api/", include("conf.urls.oj")),  # 配置
    url(r"^api/admin/", include("conf.urls.admin")),
    url(r"^api/", include("detection.urls.oj")),  # 查重
    url(r"^api/admin/", include("detection.urls.admin")),
    url(r"^api/", include("problem.urls.oj")),  # 编程题目
    url(r"^api/admin/", include("problem.urls.admin")),
    url(r"^api/", include("contest.urls.oj")),  # 比赛
    url(r"^api/admin/", include("contest.urls.admin")),
    url(r"^api/", include("submission.urls.oj")),  # 提交
    url(r"^api/admin/", include("submission.urls.admin")),
    url(r"^api/admin/", include("utils.urls")),  # 工具
]
