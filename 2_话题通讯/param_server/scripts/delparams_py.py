#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""
    rospy.delete_param("键")
    键存在时，可以删除成功，键不存在时，会抛出异常
"""
import rospy

if __name__ == "__main__":
    rospy.init_node("delete_param_py")
    rospy.loginfo("尝试删除p_int，删除成功返回数值，删除失败提示输出")

    try:
        rospy.delete_param("p_int")
    except Exception as e:
        rospy.loginfo("删除失败")
