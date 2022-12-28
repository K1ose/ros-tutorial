#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "second_node");

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("topic_name_2", 10);

    ros::Rate loop_rate(5); /* 一秒钟执行5次 */

    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "no";
        pub.publish(msg);
    }
    loop_rate.sleep();

    return 0;
}
