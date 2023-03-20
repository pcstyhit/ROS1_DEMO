#include "ros/ros.h"

/*
    ros::NodeHandle-------------------------------------
        param(键,默认值) 
            存在，返回对应结果，否则返回默认值

        getParam(键,存储结果的变量)
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamCached键,存储结果的变量)--提高变量获取效率
            存在,返回 true,且将值赋值给参数2
            若果键不存在，那么返回值为 false，且不为参数2赋值

        getParamNames(std::vector<std::string>)
            获取所有的键,并存储在参数 vector 中 

        hasParam(键)
            是否包含某个键，存在返回 true，否则返回 false

        searchParam(参数1，参数2)
            搜索键，参数1是被搜索的键，参数2存储搜索结果的变量

*/



int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param_cpp");

    // ros::NodeHandle--------------------------------------------------------
    ros::NodeHandle nh;
    // param 函数,其余函数操作查看API
    int get1 = nh.param("nh_int",100); // 键存在
    ROS_INFO("获取param参数nh_int的值:%d",get1);

    // ros::param--------------------------------------------------------
    int get2 = ros::param::param("param_int",20); //存在
    ROS_INFO("获取param参数param_int的值:%d",get2);

    return 0;
}
