#include "ros/ros.h"
// 添加自定义的头文件
#include "topic_communication/Person.h"

using namespace std;

void doPerson(const topic_communication::Person::ConstPtr& person_p){
    ROS_INFO("订阅信息:%s, %s, %d", person_p->name.c_str(), person_p->sex.c_str(), person_p->age);
}

int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"");

    //1.初始化 ROS 节点
    ros::init(argc,argv,"listener_person");
    //2.创建 ROS 句柄
    ros::NodeHandle nh;
    //3.创建订阅对象
    ros::Subscriber sub = nh.subscribe<topic_communication::Person>("chatter_person",10,doPerson);

    //4.回调函数中处理 person

    //5.ros::spin();
    ros::spin();    
    return 0;
}
