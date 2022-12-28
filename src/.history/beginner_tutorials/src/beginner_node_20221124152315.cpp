#include <ros/ros.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "beginner_node");
    while (ros::ok())
    {
        printf("hello\n");
    }
    return 0;
}
