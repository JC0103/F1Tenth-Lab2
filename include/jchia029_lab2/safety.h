#ifndef SAFETY_H
#define SAFETY_H

#include <ros/ros.h>
#include <cmath>
#include <algorithm>

#include <std_msgs/Bool.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/LaserScan.h>
#include <ackermann_msgs/AckermannDriveStamped.h>

#define PI 3.14159

// The class that handles emergency braking
class Safety {
public:
    // Constructor
    Safety();

    // Initialize publishers & subscribers API
    void init_pub_sub();

private:
    ros::NodeHandle nh;

    // Variables
    double speed;
    std_msgs::Bool brake_bool_msg;
    ackermann_msgs::AckermannDriveStamped brake_msg;

    // Declare Subscribers
    ros::Subscriber scan_sub;
    ros::Subscriber odom_sub;
    
    // Declare Publishers
    ros::Publisher brake_bool_pub;
    ros::Publisher brake_pub;

    // Callback functions
    void odom_callback(const nav_msgs::Odometry::ConstPtr &odom_msg);
    void scan_callback(const sensor_msgs::LaserScan::ConstPtr &scan_msg);

    // Publish messages function
    void publish_brake_msg();
};

#endif