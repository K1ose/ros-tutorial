#include "ros/ros.h"
#include "nav_msgs/OccupancyGrid.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "map_node");
    ros::NodeHandle nh;
    ros::Publisher map_pub = nh.advertise<nav_msgs::OccupancyGrid>("/map", 10);

    ros::Rate r(1); // 消息发送频率为1hz

    while (ros::ok())
    {
        nav_msgs::OccupancyGrid map_msg;
        map_msg.header.frame_id = "map";
        map_msg.header.stamp = ros::Time::now();

        map_msg.info.origin.position.x = 0;
        map_msg.info.origin.position.y = 0;
        map_msg.info.resolution = 1.0;
        map_msg.info.width = 50;
        map_msg.info.height = 40;

        map_msg.data.resize(50 * 40);
        for (int i = 0; i < 2000; i += 15)
        {
            map_msg.data[i] = 100;
            map_msg.data[i + 1] = -1;
        }
        map_pub.publish(map_msg);
        r.sleep();
    }
    return 0;
}
