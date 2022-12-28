#include "ros/ros.h"
#include "std_msgs/String.h"

void sub_1_callback(std_msgs::String msg)
{
    ROS_INFO("sub_1 recieve: %s", msg.data.c_str());
}
void sub_2_callback(std_msgs::String msg)
{
    ROS_WARN("sub_2 recieve: %s", msg.data.c_str());
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "beginner_tutorials_listener_node");
    ros::NodeHandle nh;
    ros::Subscriber sub_1 = nh.subscribe("/topic_name_1", 10, sub_1_callback);
    ros::Subscriber sub_2 = nh.subscribe("/topic_name_2", 10, sub_2_callback);
    ros::spin();
}
