#! /usr/bin/env python
# -*- coding: utf-8 -*-

""" 
        get_param
        get_param_cached
        get_param_names
        has_param
        search_param
"""

import rospy

if __name__ == "__main__":
    rospy.init_node("getparam_py")

    #获取参数
    int_value = rospy.get_param("p_int",10000)
    rospy.loginfo("获取的数据:%d",int_value)

