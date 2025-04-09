import functools
import hashlib
import time

# 从项目中引入相关的模型和工具类，用于数据查询与API响应
from problem.models import Problem  # 题目模型，用于权限检测中的对象归属判断
from contest.models import Contest, ContestType, ContestStatus, ContestRuleType  # 比赛相关模型及状态/规则类型常量
from utils.api import JSONResponse, APIError  # 用于生成 JSON 响应及抛出接口错误
from utils.constants import CONTEST_PASSWORD_SESSION_KEY  # Session中存储比赛密码的键名常量
from .models import ProblemPermission  # 问题管理权限常量


########################################################################
# 基础权限装饰器：所有权限检查装饰器都继承自此类
########################################################################

class BasePermissionDecorator(object):
    """
    基础权限装饰器基类，用于统一处理权限检测逻辑，
    并对结果进行统一反馈（允许则调用原逻辑，不允许则返回错误 JSON）。

    工作流程:
      1. 从参数中提取 request 对象（约定为第二个位置参数）。
      2. 调用子类实现的 check_permission() 方法判断权限。
      3. 若权限检查通过，再检查用户是否被禁用（is_disabled）。
      4. 若以上两个条件都满足，则调用被装饰的函数；否则返回错误响应。
    """

    def __init__(self, func):
        # 保存被装饰的函数到实例变量 self.func
        self.func = func

    def __get__(self, obj, obj_type):
        """
        实现描述符协议，使得装饰器可以正常绑定到类的方法上，
        返回一个偏函数，把所属对象 obj（通常为 view 实例）绑定到 __call__ 方法上。
        """
        return functools.partial(self.__call__, obj)

    def error(self, data):
        """
        快速生成统一格式的 JSON 错误响应。

        参数:
          data: 错误的详细描述

        返回:
          包含 "error" 和 "data" 字段的 JSON 响应
        """
        return JSONResponse.response({"error": "permission-denied", "data": data})

    def __call__(self, *args, **kwargs):
        """
        装饰器的入口方法。当请求到达此处：

          1. 从参数列表中提取 request 对象（假设它为位置参数 args[1]）。
          2. 调用子类重写的 check_permission() 判断请求是否具有执行权限。
          3. 如果权限检查通过，同时用户账户未被禁用，则调用原函数，返回结果。
          4. 如果权限检查失败，则返回统一的错误响应。
        """
        # 约定第二个参数为 request 对象（例如在基于类的视图中：self, request, ...）
        self.request = args[1]

        # 调用子类的权限检查方法
        if self.check_permission():
            # 额外检查：用户账户是否被禁用
            if self.request.user.is_disabled:
                return self.error("Your account is disabled")
            # 权限通过，调用原有业务逻辑
            return self.func(*args, **kwargs)
        else:
            # 权限检查未通过时，返回提示登录的错误信息
            return self.error("Please login first")

    def check_permission(self):
        """
        抽象方法，由子类实现具体的权限判断逻辑。
        必须返回 True（有权限）或 False（无权限）。
        """
        raise NotImplementedError()


########################################################################
# 具体权限装饰器
########################################################################

class login_required(BasePermissionDecorator):
    """
    登录权限装饰器：
      - 功能：校验当前请求的用户是否已经登录
      - 使用场景：保证接口只有登录用户可访问
    """

    def check_permission(self):
        # 检查 request.user 是否已通过认证
        return self.request.user.is_authenticated


class super_admin_required(BasePermissionDecorator):
    """
    超级管理员权限装饰器：
      - 功能：校验当前请求的用户是否是超级管理员
      - 使用场景：涉及最高权限、系统管理操作时使用
    """

    def check_permission(self):
        user = self.request.user
        # 用户必须已经登录，并且具有超级管理员权限
        return user.is_authenticated and user.is_super_admin()


class admin_role_required(BasePermissionDecorator):
    """
    管理员角色权限装饰器：
      - 功能：校验当前请求的用户是否具备管理员角色
      - 使用场景：需要一般管理员权限的管理操作
    """

    def check_permission(self):
        user = self.request.user
        # 用户必须已经登录，并且是管理员角色
        return user.is_authenticated and user.is_admin_role()


class problem_permission_required(admin_role_required):
    """
    题目管理权限装饰器：
      - 功能：在保证用户具备管理员角色的基础上，进一步检查其是否有操作题目的权限
      - 使用场景：用于管理题目、编辑题目时的权限判断
    """

    def check_permission(self):
        # 先调用父类 (admin_role_required) 的权限检查，确认用户是管理员
        if not super(problem_permission_required, self).check_permission():
            return False
        # 进一步判断用户的题目权限。若为 ProblemPermission.NONE 则用户无题目操作权限
        if self.request.user.problem_permission == ProblemPermission.NONE:
            return False
        # 如果上面两项都通过，则通过权限检测
        return True


########################################################################
# 辅助函数：密码及比赛权限判断
########################################################################

def check_contest_password(password, contest_password):
    """
    检查用户提供的密码是否有效，支持两种形式：
      1. 直接明文密码比对
      2. 支持 "sig#timestamp" 格式密码的签名验证，
         其中 sig 表示 contest_password 加上 timestamp 后经过 SHA256
         哈希后取前8位，timestamp 为有效期结束的 Unix 时间戳。

    参数:
      password: 用户提交的密码，可能为明文或 "sig#timestamp" 格式
      contest_password: 竞赛的正确密码

    返回:
      True  - 密码匹配或签名验证通过
      False - 密码错误或者格式不正确或已经过期
    """
    # 如果任一密码值为空，直接返回 False
    if not (password and contest_password):
        return False
    # 直接进行明文密码对比
    if password == contest_password:
        return True
    else:
        # 处理 "sig#timestamp" 格式：
        if "#" in password:
            # 按 "#" 分割成签名和时间戳
            s = password.split("#")
            if len(s) != 2:
                return False  # 格式错误：分割后不等于两个部分
            sig, ts = s[0], s[1]

            # 计算期望的签名：contest_password + ts 经 SHA256 哈希后截取前 8 位
            expected_sig = hashlib.sha256((contest_password + ts).encode("utf-8")).hexdigest()[:8]
            if sig == expected_sig:
                try:
                    # 尝试转换时间戳为整数
                    ts = int(ts)
                except Exception:
                    return False  # 时间戳不合法
                # 比较当前时间与时间戳：确保密码未过期
                return int(time.time()) < ts
            else:
                return False  # 签名计算不匹配
        else:
            # 不支持其他格式，直接返回 False
            return False


def check_contest_permission(check_type="details"):
    """
    装饰器：用于基于类视图的方法上，验证用户对特定比赛（contest）的访问权限。

    参数:
      check_type: 表示访问类型，支持的类型包括：
                  - "details": 比赛详情，可以允许用户查看基本信息
                  - "problems": 题目列表
                  - "ranks": 排行榜
                  - "submissions": 提交记录

    装饰器内部逻辑:
      1. 从请求中获取 contest_id：
         - 优先检查请求体中的 data（适用于 POST 请求）
         - 否则检查 GET 参数
      2. 若 contest_id 缺失则返回参数错误
      3. 使用 contest_id 查询数据库中可见的比赛对象，同时使用 select_related 提前加载关联字段 (created_by)
         - 如果找不到，返回对应的错误信息
      4. 检查用户是否已登录，否则返回"请先登录"的错误
      5. 如果用户是比赛管理员（例如比赛创建者或具有相应管理权限），直接允许访问
      6. 若比赛为密码保护型，则：
         - 从 session 中读取存储的密码（使用 CONTEST_PASSWORD_SESSION_KEY）
         - 调用 check_contest_password() 验证密码正确性
      7. 对于普通用户，当比赛未开始（CONTEST_NOT_START）且访问类型不只为"details"时，禁止访问题目、排行榜等信息
      8. 对于正在进行的 OI 比赛，若比赛设置不允许实时查看排名或提交信息，
         在访问 "ranks" 或 "submissions" 时直接拒绝

    若所有检查均通过，则调用被装饰的视图方法，否则返回对应的 JSON 错误响应。
    """

    def decorator(func):
        def _check_permission(*args, **kwargs):
            # 获取类视图实例（self）、request 对象与当前用户
            self = args[0]
            request = args[1]
            user = request.user

            # 优先尝试从 POST 请求中的 data 提取 contest_id，否则从 GET 参数提取
            if request.data.get("contest_id"):
                contest_id = request.data["contest_id"]
            else:
                contest_id = request.GET.get("contest_id")

            # contest_id 为必填参数，若为空返回错误信息
            if not contest_id:
                return self.error("Parameter error, contest_id is required")

            try:
                # 根据 contest_id 查询该比赛， 并确保比赛是可见的（visible=True）
                # 使用 select_related 优化查询，同时加载 created_by 字段，减少后续查询次数
                self.contest = Contest.objects.select_related("created_by").get(id=contest_id, visible=True)
            except Contest.DoesNotExist:
                return self.error("Contest %s doesn't exist" % contest_id)

            # 未登录用户不允许继续操作，返回登录提示
            if not user.is_authenticated:
                return self.error("Please login first.")

            # 检查是否为比赛的创建者或管理员，若是则直接允许访问，不进行后续限制
            if user.is_contest_admin(self.contest):
                return func(*args, **kwargs)

            # 如果比赛为密码保护类型，则必须在 session 中存有正确的密码信息
            if self.contest.contest_type == ContestType.PASSWORD_PROTECTED_CONTEST:
                session_data = request.session.get(CONTEST_PASSWORD_SESSION_KEY, {})
                contest_password_in_session = session_data.get(self.contest.id)
                if not check_contest_password(contest_password_in_session, self.contest.password):
                    return self.error("Wrong password or password expired")

            # 如果比赛尚未开始 (CONTEST_NOT_START) 且请求类型不是 "details"，
            # 阻止访问试题、排行榜或提交记录等敏感信息
            if self.contest.status == ContestStatus.CONTEST_NOT_START and check_type != "details":
                return self.error("Contest has not started yet.")

            # 特殊检测：对于正在进行（CONTEST_UNDERWAY）且规则为 OI 的比赛
            # 当比赛不允许实时排行榜时，禁止访问 "ranks" 或 "submissions" 数据
            if self.contest.status == ContestStatus.CONTEST_UNDERWAY and self.contest.rule_type == ContestRuleType.OI:
                if not self.contest.real_time_rank and (check_type == "ranks" or check_type == "submissions"):
                    return self.error(f"No permission to get {check_type}")

            # 若所有权限检查通过，则执行实际的视图方法
            return func(*args, **kwargs)

        return _check_permission

    return decorator


########################################################################
# 辅助函数：对象创建人权限验证
########################################################################

def ensure_created_by(obj, user):
    """
    验证当前用户是否具有管理或修改指定对象的权限，其依据是对象的创建者是谁。

    参数:
      obj: 被操作的对象，通常要求有 created_by 属性标识创建者
      user: 当前进行操作的用户对象

    检查逻辑:
      1. 如果用户不具备管理员角色，则直接抛出 APIError 异常
      2. 超级管理员拥有所有权限，直接通过验证
      3. 如果对象是 Problem 类型：
         - 若用户不具备管理所有题目的权限，并且该题目不是由当前用户创建，则抛出异常
      4. 对于非 Problem 类型的对象，如果 created_by 字段与当前用户不匹配，则抛出异常

    异常:
      APIError - 当用户不满足对象操作权限要求时抛出
    """
    # 定义一个错误对象，用于抛出权限不足时的异常信息
    e = APIError(msg=f"{obj.__class__.__name__} does not exist")

    # 如果当前用户没有管理员角色，则不允许操作，直接抛出异常
    if not user.is_admin_role():
        raise e
    # 超级管理员具有所有权限，不需要后续检查
    if user.is_super_admin():
        return
    # 如果操作对象为 Problem 类型，则进行专门的权限检查
    if isinstance(obj, Problem):
        # 若用户没有全局管理所有题目的权限，并且该题目不是由当前用户创建，则抛出异常
        if not user.can_mgmt_all_problem() and obj.created_by != user:
            raise e
    # 针对其他类型对象，仅检查对象的创建者是否与当前用户一致
    elif obj.created_by != user:
        raise e


class detection_detail_permission_required(problem_permission_required):

    def check_permission(self):
        user = self.request.user
        # 用户必须已经登录
        if not user.is_authenticated:
            return False

        # 如果是超级管理员，直接通过
        if user.is_super_admin():
            return True

        # 如果不是管理员角色，拒绝
        if not user.is_admin_role():
            return False

        # 检查题目管理权限
        return user.problem_permission != ProblemPermission.NONE