#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <dy_reconfigure/myDyCfgConfig.h>

void callback(dy_reconfigure::myDyCfgConfig &config, uint32_t level) {
    ROS_INFO("终端打印输出,整型数值是 %d，下拉条层级是 %d",config.myint,config.mylist);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "dy_configure");

    dynamic_reconfigure::Server<dy_reconfigure::myDyCfgConfig> server;
    dynamic_reconfigure::Server<dy_reconfigure::myDyCfgConfig>::CallbackType f;

    f = boost::bind(&callback, _1, _2);
    server.setCallback(f);
    ros::spin();
    return 0;
}