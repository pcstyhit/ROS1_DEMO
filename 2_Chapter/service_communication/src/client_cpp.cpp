/**
 * AddTwoInt Client
 */
#include <cstdlib>
#include "ros/ros.h"
#include "service_communication/AddTwoInt.h"

int main(int argc, char **argv)
{
  setlocale(LC_ALL,"");
  // ROS节点初始化
  ros::init(argc, argv, "add_two_ints_client");
  
  // 从终端命令行获取两个加数
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }
  // 创建节点句柄
  ros::NodeHandle n;
    // 创建一个client，请求add_two_int service，service消息类型是service_communication::AddTwoInt
  ros::ServiceClient client = n.serviceClient<service_communication::AddTwoInt>("add_two_ints");
   // 创建service_communication::AddTwoInt类型的service消息
  service_communication::AddTwoInt srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
    // 发布service请求，等待加法运算的应答结果
    // 等待客户端启动
  client.waitForExistence();
    // 也可以采用代码ros::service::waitForService("AddTwoInt");

  if (client.call(srv))
  {
    ROS_INFO("c: %ld", (long int)srv.response.c);
  }
  else
  {
    ROS_ERROR("客户端没有启动");
    return 1;
  }

  return 0;
}

