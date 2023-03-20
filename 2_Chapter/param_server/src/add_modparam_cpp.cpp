#include "ros/ros.h"
using namespace std;

/*
两套API对参数的增加或者修改的操作是类似的，主要采用set函数进行
    ros::NodeHandle
        setParam("键",值)
    ros::param
        set("键","值")
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"add_modparam_cpp");

    // API1---使用NodeHandle-------------------------------------------------
    ros::NodeHandle nh;
    nh.setParam("nh_int",10); //整型
    nh.setParam("nh_double",3.14); //浮点型
    // 修改演示替换掉键的值
    nh.setParam("nh_int",10000);

    // API2---使用param--------------------------------------------------------
    ros::param::set("param_int",20);
    ros::param::set("param_double",3.14);
    // 修改演示替换掉键的值
    ros::param::set("param_int",20000);


    // 增加可视化 打印输出--------------------------------------------------------
    ROS_INFO("参数设置成功，采用命令rosparam list 查看param 列表");
    ROS_INFO("自定义参数只有四个：nh_int，nh_double，param_int，param_double");
    ROS_INFO("查看参数值采用rosparam get 参数名，如rosparam get /nh_int");


    return 0;
}
