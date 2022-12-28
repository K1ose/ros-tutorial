#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "geometry_msgs/Twist.h"
#include "tf/tf.h"

ros::Publisher vel_pub;

void imu_callback(sensor_msgs::Imu imu_data)
{
    /* 四元数的值不存在 */
    if (imu_data.orientation_covariance[0] < 0)
        return;

    /* tf工具将四元数转换成欧拉角数值 */
    tf::Quaternion quaternion(
        imu_data.orientation.x,
        imu_data.orientation.y,
        imu_data.orientation.z,
        imu_data.orientation.w);

    double roll, pitch, yaw;                            /* 保存欧拉角数值 */
    tf::Matrix3x3(quaternion).getRPY(roll, pitch, yaw); /* 转换 */

    /* 弧度转为度数 */
    roll = roll * 180 / M_PI;
    pitch = pitch * 180 / M_PI;
    yaw = yaw * 180 / M_PI;

    geometry_msgs::Twist cmd_vel_msg;
    if (roll > 20 || roll < -20)
    {
        ROS_WARN("滚转角度过大，为%.2f°", roll);
    }
    if (pitch > 20 || pitch < -20)
    {
        ROS_WARN("俯仰角度过大，为%.2f°", pitch);
    }
    if (yaw > 20 || yaw < -20)
    {
        ROS_WARN("航向角度过大，为%.2f°", yaw);
    }

    double target_yaw = 0, target_roll = 0, target_pitch = 0;
    double adjust_yaw_angle = target_yaw - yaw;
    double adjust_roll_angle = target_roll - roll;
    double adjust_pitch_angle = target_pitch - pitch;

    cmd_vel_msg.angular.z = adjust_yaw_angle * 0.01;
    cmd_vel_msg.angular.y = adjust_roll_angle * 0.01;
    cmd_vel_msg.angular.x = adjust_pitch_angle * 0.01;

    ROS_INFO("滚转roll: %.2f", roll);
    ROS_INFO("俯仰pitch: %.2f", pitch);
    ROS_INFO("偏航yaw: %.2f", yaw);

    vel_pub.publish(cmd_vel_msg);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "zh_CN.UTF-8");
    ros::init(argc, argv, "imu_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<sensor_msgs::Imu>("/imu/data", 10, imu_callback);

    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    while (ros::ok())
    {
        ros::spinOnce();
    }
    return 0;
}
