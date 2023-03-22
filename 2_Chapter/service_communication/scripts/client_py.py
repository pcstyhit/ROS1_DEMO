#!/usr/bin/env python
# -*- coding: utf-8 -*-

#1.导包
import rospy
from service_communication.srv import *
import sys

if __name__ == "__main__":

    #优化实现
    if len(sys.argv) != 3:
        rospy.logerr("请正确提交参数")
        sys.exit(1)


    # 2.初始化 ROS 节点
    rospy.init_node("AddTwoInt_Client_p")
    # 3.创建请求对象
    client = rospy.ServiceProxy("AddTwoInt",AddTwoInt)
    # 请求前，等待服务已经就绪

    client.wait_for_service()
    # 4.发送请求,接收并处理响应

    req = AddTwoIntRequest()
    req.a = int(sys.argv[1])
    req.b = int(sys.argv[2]) 

    resp = client.call(req)
    rospy.loginfo("响应结果:%d",resp.c)
