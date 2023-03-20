#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "action_communication/DoDishesAction.h"

typedef actionlib::SimpleActionServer<action_communication::DoDishesAction> Server;

// 收到action的goal后调用该回调函数
void callback(const action_communication::DoDishesGoalConstPtr& goal, Server* server)
{
    ros::Rate r(1);
    action_communication::DoDishesFeedback feedback;
    ROS_INFO("收到客户端的goal,洗碗工 %d 开始洗盘子.", goal->dishwasher_id);
    // 假设洗盘子的进度，并且按照1hz的频率发布进度feedback
    for(int i=1; i<=10; i++)
    {
        feedback.percent_complete = i * 10;
        server->publishFeedback(feedback);
        ROS_INFO("feedback ing ...");
        r.sleep();
    }

    // 当action完成后，向客户端返回结果
    ROS_INFO("洗碗工完成了工作，发送result(100个)给客户端.");
    action_communication::DoDishesResult res;
    res.total_dishes_cleaned = 100;
    server->setSucceeded(res);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "do_dishes_server");
    ros::NodeHandle nh;
    // 定义一个服务器
    Server server(nh, "do_dishes", boost::bind(&callback, _1, &server), false);
    // 服务器开始运行
    ROS_INFO("action服务端启动,等待指令");
    server.start();
    ros::spin();
    return 0;
}
