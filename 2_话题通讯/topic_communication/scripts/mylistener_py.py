#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from topic_communication.msg import Person

def doPerson(p):
    rospy.loginfo("接收信息:%s, %s, %d",p.name, p.sex, p.age)


if __name__ == "__main__":
    #1.初始化节点
    rospy.init_node("listener_person_p")
    #2.创建订阅者对象
    sub = rospy.Subscriber("chatter_person",Person,doPerson,queue_size=10)
    rospy.spin() #4.循环
