# coding=utf-8
import os
from utils.shortcuts import get_env

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.postgresql_psycopg2',
        'HOST': get_env("POSTGRES_HOST", "127.0.0.1"),
        'PORT': get_env("POSTGRES_PORT", "5432"),  # 确保端口为 5432
        'NAME': get_env("POSTGRES_DB", "onlinejudge"),      # 数据库名称
        'USER': get_env("POSTGRES_USER", "onlinejudge"),    # 用户名
        'PASSWORD': get_env("POSTGRES_PASSWORD", "onlinejudge")  # 密码
    }
}

REDIS_CONF = {
    'host': get_env('REDIS_HOST', '127.0.0.1'),
    'port': get_env('REDIS_PORT', '6379')
}


DEBUG = True

ALLOWED_HOSTS = ["*"]

DATA_DIR = f"{BASE_DIR}/data"
