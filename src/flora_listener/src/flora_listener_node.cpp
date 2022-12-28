/************************************************************************
File Name: flora_listener_node.cpp
Author: Klose
E-mail: klose@jk404.cn
Created Time: 2022-11-20 15:16:52
************************************************************************/
#include "ros/ros.h"
#include "flora_msgs/FloraMsg.h"

void floraCallback(const flora_msgs::FloraMsg::ConstPtr& msg){
	ROS_INFO("I heard %s", msg->detail.c_str());
	ROS_INFO("I heard %d", msg->id);
}

int main(int argc, char **argv){
	setlocale(LC_ALL, "zh_CN.UTF-8");
	ros::init(argc, argv, "flora_listener");
	ros::NodeHandle node;
	ros::Subscriber sub = node.subscribe("/flora_topic", 10, floraCallback);
	ros::spin();	// 接收消息

	return 0;
}
