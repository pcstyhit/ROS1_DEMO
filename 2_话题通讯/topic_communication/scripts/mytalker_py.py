#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from topic_communication.msg import Person


if __name__ == "__main__":
    #1.初始化 ROS 节点
    rospy.init_node("talker_person_p")
    #2.创建发布者对象
    pub = rospy.Publisher("chatter_person",Person,queue_size=10)
    #3.组织消息
    p = Person()
    p.name = "zhangsan"
    p.sex = "man"
    p.age = 18

    #4.编写消息发布逻辑
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        pub.publish(p)  #发布消息
        p.age = p.age+1
        rate.sleep()  #休眠
        rospy.loginfo("我叫:%s,性别:%s，年龄:%d", p.name, p.sex, p.age)
