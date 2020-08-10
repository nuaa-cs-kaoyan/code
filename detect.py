# -*- coding: utf-8 -*-
"""
Created on Sun Mar 18 16:02:25 2018
用来自动检测 复试名单 的脚本
当监测到官网发布复试名单后，会发送短信通知
@author: 南航大计算机考研 QQ 321556185
"""
import time
import re
import json
from urllib.request import urlopen
from urllib.request import Request
from urllib.parse import urlencode
from bs4 import BeautifulSoup
import logging

logging.basicConfig(level=logging.ERROR,
                    format='%(asctime)s-%(filename)s-[line:%(lineno)d] %(levelname)s %(message)s',
                    filename='err.log',
                    filemode='a')


def get_content(url):
    """
    获取指定网站的网页显示内容
    :param url:
    :return: 网页显示内容
    """
    headers = {
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
        'Accept-Language': 'zh-CN,zh;q=0.9',
        'Cache-Control': 'max-age=0',
        'Connection': 'keep-alive',
        'Cookie': "Coremail=77ae47ade376bbb3975aef83e104d2f0; JSESSIONID=F2AB37F5A44E4CC5B9CDB8BDBFF4D173",
        'Host': 'cs.nuaa.edu.cn',
        'Upgrade-Insecure-Requests': '1',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/63.0.3239.132 Safari/537.36'
    }
    req = Request(url=url, headers=headers)
    html_str = "hehe"
    try:
        html_str = urlopen(req).read().decode('utf-8')
    except Exception as e:
        logging.error(e)
        exit(0)
    soup = BeautifulSoup(html_str, 'html.parser', from_encoding="gb18030")
    content = soup.get_text()
    return content


def call():
    """
    打电话通知，还有两次短信通知机会
    :return:
    """
    appkey = "xxx"
    url = "http://op.juhe.cn/yuntongxun/voice"
    params = {
        "valicode": "123456",  # 验证码内容，字母、数字 4-8位
        "to": "1885187xxx",  # 接收手机号码
        "playtimes": "",  # 验证码播放次数，默认3
        "key": appkey,  # 应用APPKEY(应用详细页查询)
        "dtype": "",  # 返回数据的格式,xml或json，默认json

    }
    params = urlencode(params)
    f = urlopen("%s?%s" % (url, params))
    content = f.read()
    res = json.loads(content)
    if res:
        error_code = res["error_code"]
        if error_code == 0:
            # 成功请求
            print(res["result"])
        else:
            print("%s:%s" % (res["error_code"], res["reason"]))
    else:
        print("request api error")


def detect(url, pattern):
    """
    监控特定网站，判断是否有指定内容的更新
    :param url: 监控的网站
    :param pattern: 要监控的内容
    :return: 是否有更新，true or false
    """
    old_content = get_content(url)
    while(True):
        new_content = get_content(url)
        if (old_content != new_content) and bool(re.findall(pattern, new_content)):
            notification_str = "有和 “" + pattern + "” 相关的内容更新，详情请登陆 " + url + " 查看"
            print(notification_str)
            call()
        else:
            old_content = new_content
            print("no related update")

        time.sleep(10)


if __name__ == "__main__":
    pattern = "硕士生招生复试及录取细则" # 支持正则
    url = "http://cs.nuaa.edu.cn/1993/list.htm"
    detect(url, pattern)