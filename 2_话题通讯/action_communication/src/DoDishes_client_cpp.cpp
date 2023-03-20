#include <actionlib/client/simple_action_client.h>
#include "action_communication/DoDishesAction.h"

typedef actionlib::SimpleActionClient<action_communication::DoDishesAction> Client;

// 当action完成后会调用该回调函数一次
void doneCb(const actionlib::SimpleClientGoalState& state,
        const action_communication::DoDishesResultConstPtr& result){
    ROS_INFO("result:洗碗工把盘子已经洗完啦!洗了%d个",result->total_dishes_cleaned);
    ros::shutdown();
}

// 当action激活后会调用该回调函数一次
void activeCb(){
    ROS_INFO("服务器已经打开，可以执行任务");
}

// 收到feedback后调用该回调函数
void feedbackCb(const action_communication::DoDishesFeedbackConstPtr& feedback)
{
    ROS_INFO("feedback:洗盘子的进度:%f", feedback->percent_complete);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "do_dishes_client");
    // 定义一个客户端
    Client client("do_dishes", true);

    // 等待服务器端
    client.waitForServer();
    ROS_INFO("goal:选择员工1洗盘子:");
    // 创建一个action的goal
    action_communication::DoDishesGoal goal;
    goal.dishwasher_id = 1;
    // 发送action的goal给服务器端，并且设置回调函数
    client.sendGoal(goal,  &doneCb, &activeCb, &feedbackCb);

    ros::spin();
    return 0;
}
