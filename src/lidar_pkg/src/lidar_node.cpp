#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

ros::Publisher vel_pub;

void lidar_callback(sensor_msgs::LaserScan msg)
{
    /* 已知包中的ranges数组排列顺序是从起始角度到终止角度，每旋转一度得到一个测距值，则前方为+180° */
    float dis;
    bool isCloseOb;
    for (int i = 0; i < 50; i++)
    {
        float dis = msg.ranges[155 + i]; // 155~205°之内的物体检测，即正前方左右各25°

        if (dis < 1.5)
        {
            isCloseOb = true; // 一旦检测出范围内有物体，且物体距离小于1.5m，将标志设为true，并且break掉
            break;
        }
        else
            isCloseOb = false;
        ROS_INFO("%d° distance: %f m", 155 + i, dis);
    }
    // float frontDis = msg.ranges[180];

    geometry_msgs::Twist vel_cmd;

    /* 前方障碍物距离小于1.5m时，设置z轴正方向角速度，即左转 */
    if (isCloseOb)
        vel_cmd.angular.z = 0.3;
    else
        vel_cmd.linear.x = 0.1;

    vel_pub.publish(vel_cmd);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "zh_CN.UTF-8");
    ros::init(argc, argv, "lidar_node");

    ros::NodeHandle nh;

    ros::Subscriber scan_sub = nh.subscribe<sensor_msgs::LaserScan>("/scan", 10, lidar_callback);

    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    while (ros::ok())
    {
        ros::spinOnce();
    }
    // ros::spin();
    return 0;
}