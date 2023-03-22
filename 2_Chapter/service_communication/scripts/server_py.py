#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 1.导包
import rospy
from service_communication.srv import *
# 回调函数的参数是请求对象，返回值是响应对象
def doReq(req):
    # 解析提交的数据
    c = req.a + req.b
    rospy.loginfo("提交的数据:a = %d, b = %d, c = %d",req.a, req.b, c)

    # 创建响应对象，赋值并返回
    # resp = AddTwoIntResponse()
    # resp.c = c
    resp = AddTwoIntResponse(c)
    return resp


if __name__ == "__main__":
    # 2.初始化 ROS 节点
    rospy.init_node("AddTwoInt_server_p")
    # 3.创建服务对象
    server = rospy.Service("AddTwoInt",AddTwoInt,doReq)
    # 4.回调函数处理请求并产生响应
    # 5.spin 函数
    rospy.spin()
