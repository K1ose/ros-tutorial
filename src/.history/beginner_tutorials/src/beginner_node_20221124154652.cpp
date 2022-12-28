#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "beginner_node");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("hello") while (ros::ok())
    {
    }
    return 0;
}
