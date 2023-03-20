#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import actionlib
from action_communication.msg import *

def result_cb(state,result):
    if state == actionlib.GoalStatus.SUCCEEDED:
        rospy.loginfo("result:洗碗工把盘子已经洗完啦!洗了%d个",result.total_dishes_cleaned)

def active_cb():
    rospy.loginfo("服务被激活....")

def feedback_cb(f):
    rospy.loginfo("当前进度:%.2f",f.percent_complete)

if __name__ == "__main__":
    # 2.初始化 ROS 节点
    rospy.init_node("action_client_py")
    # 3.创建 action Client 对象
    client = actionlib.SimpleActionClient("dodishes",DoDishesAction)
    # 4.等待服务
    client.wait_for_server()
    # 5.组织目标对象并发送
    goal_obj = DoDishesGoal()
    goal_obj.dishwasher_id = 1
    rospy.loginfo("goal:选择员工1洗盘子:")
    client.send_goal(goal_obj,result_cb,active_cb,feedback_cb)
    # 6.编写回调, 激活、连续反馈、最终响应
    # 7.spin
    rospy.spin()