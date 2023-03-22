#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from dynamic_reconfigure.server import Server
from dy_reconfigure.cfg import myDyCfgConfig

def callback(config, level):
    rospy.loginfo("终端打印输出,整型数值是 %d，下拉条层级是 %d",config.myint,config.mylist)
    return config

if __name__ == "__main__":
    rospy.init_node("dynamic_myDyCfg", anonymous = False)

    srv = Server(myDyCfgConfig, callback)
    rospy.spin()