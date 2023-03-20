#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from std_msgs.msg import String

#data即chatter带来的所有内容()
def callback(data):
    rospy.loginfo("publisher is " + rospy.get_caller_id() + ' I subscribe %s', data.data)

def listener():
#节点名
    rospy.init_node('listener')
#这里的chatter是在talker.py定义的publish的话题名，区分节点名和话题名
    rospy.Subscriber('chatter', String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()

