#!/usr/bin/env python
# -*- coding: utf-8 -*-


import rospy
import actionlib
from action_communication.msg import *


class myActionServer:
    def __init__(self):
        # 1.创建服务器,执行服务器回调函数
        self.server = actionlib.SimpleActionServer("dodishes", DoDishesAction, self.serverCb, False)
        self.server.start()
        rospy.loginfo("服务端启动")

    def serverCb(self,goal):
        id = goal.dishwasher_id
        rospy.loginfo("收到来自客户端的goal，洗碗工 %d 开始工作",id)
        rate = rospy.Rate(1)

        for i in range(1, 10):
            rospy.loginfo("feedback ing...")
            feedBack_obj = DoDishesFeedback()
            feedBack_obj.percent_complete = i
            self.server.publish_feedback(feedBack_obj)
            rate.sleep()

        res = DoDishesResult()
        res.total_dishes_cleaned = 100
        rospy.loginfo("洗碗工完成了工作，发送result(100个)给客户端.")
        self.server.set_succeeded(res)


if __name__ == "__main__":
    rospy.init_node("action_server_py")
    server = myActionServer()
    rospy.spin()
