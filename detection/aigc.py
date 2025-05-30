import ssl
from typing import Tuple, Any

import requests
import json
import urllib3
from requests.adapters import HTTPAdapter
from urllib3.util.ssl_ import create_urllib3_context

# 禁用SSL警告（生产环境建议保持开启）
urllib3.disable_warnings()


class SecureHTTPAdapter(HTTPAdapter):
    """强制使用安全协议的自定义适配器"""

    def init_poolmanager(self, *args, **kwargs):
        context = create_urllib3_context()
        # 配置安全选项
        context.options |= (
                0x4 |  # OP_LEGACY_SERVER_CONNECT
                0x1000000  # OP_ENABLE_MIDDLEBOX_COMPAT
        )
        context.minimum_version = ssl.TLSVersion.TLSv1_2
        kwargs['ssl_context'] = context
        return super().init_poolmanager(*args, **kwargs)


def initialize_session() -> requests.Session:
    """初始化预配置的安全会话"""
    session = requests.Session()
    adapter = SecureHTTPAdapter(max_retries=3)
    session.mount("https://", adapter)
    session.mount("http://", adapter)
    return session


def check_code_origin(text: str) -> tuple[float, str] | tuple[Any, str]:
    api_key = "5605d78d723f44ebaf34825505c15abe"
    url = "https://api.gptzero.me/v2/predict/text"
    headers = {"x-api-key": api_key, "Content-Type": "application/json"}
    payload = {
        "document": text,
    }

    session = initialize_session()

    try:
        response = session.post(
            url,
            headers=headers,
            json=payload,
            verify=True,  # 生产环境应保持True
            timeout=(10, 30) ) # 连接超时10秒，读取超时30秒

        response.raise_for_status()

        result = response.json()
        if not result.get("documents"):
            return 0.0, "error: No documents in response"

        doc = result["documents"][0]
        class_probs = doc.get("class_probabilities", {})
        ai_prob = class_probs.get("ai", 0.0)

        return round(ai_prob * 100, 2), "success"

    except requests.exceptions.RequestException as e:
        error_msg = f"error,API请求失败: {type(e).__name__}: {str(e)}"
        return 0.0, error_msg
    except (json.JSONDecodeError, KeyError) as e:
        error_msg = f"error,响应解析失败: {type(e).__name__}: {str(e)}"
        return 0.0, error_msg
    except Exception as e:
        error_msg = f"error,未知错误: {type(e).__name__}: {str(e)}"
        return 0.0, error_msg
