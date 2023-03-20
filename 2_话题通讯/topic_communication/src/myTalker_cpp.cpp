#include "ros/ros.h"
// 添加自定义的头文件
#include "topic_communication/Person.h"
using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");

    //1.初始化 ROS 节点
    ros::init(argc,argv,"talker_person");

    //2.创建 ROS 句柄
    ros::NodeHandle nh;

    //3.创建发布者对象
    ros::Publisher pub = nh.advertise<topic_communication::Person>("chatter_person",1000);

    //4.组织被发布的消息，编写发布逻辑并发布消息
    topic_communication::Person p;
    p.name = "zhangsan";
    p.sex = "man";
    p.age = 18;

    ros::Rate r(1);
    while (ros::ok())
    {
        pub.publish(p);
        p.age += 1;
        ROS_INFO("我叫:%s,性别:%s，年龄:%d", p.name.c_str(), p.sex.c_str(), p.age);

        r.sleep();
        ros::spinOnce();
    }



    return 0;
}
