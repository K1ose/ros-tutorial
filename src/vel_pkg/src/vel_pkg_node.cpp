#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "vel_pkg_node");
    ros::NodeHandle nh;

    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    geometry_msgs::Twist vel_msgs;
    vel_msgs.linear.x = 0.1;
    vel_msgs.linear.y = 0;
    vel_msgs.linear.z = 0.2;
    vel_msgs.angular.x = 0;
    vel_msgs.angular.y = 0;
    vel_msgs.angular.z = 1;

    ros::Rate r(30);
    while (ros::ok())
    {
        vel_pub.publish(vel_msgs);
        r.sleep();
    }

    return 0;
}
