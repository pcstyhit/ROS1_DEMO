#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from std_msgs.msg import String

def talker():
#话题名，rostopic list查看
    pub = rospy.Publisher('chatter', String, queue_size=10)
#节点名，rosnode list 查看
    rospy.init_node('talker')
    rate = rospy.Rate(1) # 1hz
    i = 1
    while not rospy.is_shutdown():
        hello_str = "number: %d" % i
        rospy.loginfo(hello_str)
#在listener.py里的data即是hello_str所有的内容
        pub.publish(hello_str)
        i += 1
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

