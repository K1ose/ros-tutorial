#include "ros/ros.h"
#include "std_msgs/String.h"
#include "flora_msgs/FloraMsg.h"

int main(int argc, char **argv){
	ros::init(argc, argv, "flora_talker");
	ros::NodeHandle node;
	ros::Publisher flora_pub = node.advertise<flora_msgs::FloraMsg>("/flora_topic", 10);
	ros::Rate loop_rate(10);
	
	while(ros::ok()){

		std::string param_detail;
		node.param<std::string>("param_detail", param_detail, "default detail: hahaha~");

		flora_msgs::FloraMsg flora_msg;
		flora_msg.id = rand();
		flora_msg.detail = param_detail;

		flora_pub.publish(flora_msg);

		loop_rate.sleep();
	}
}
