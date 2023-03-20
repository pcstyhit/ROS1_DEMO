#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rospy

if __name__ == "__main__":
    rospy.init_node("set_update_paramter_p")

    # 设置各种类型参数
    rospy.set_param("p_int",10)
    rospy.set_param("p_double",3.14)
    # 修改
    rospy.set_param("p_int",100)
    rospy.loginfo("参数设置成功，采用命令rosparam list 查看param 列表")
    rospy.loginfo("自定义参数只有：p_int，p_double")
    rospy.loginfo("查看参数值采用rosparam get 参数名，如rosparam get /p_int")


    
