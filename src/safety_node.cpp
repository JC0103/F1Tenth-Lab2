#include "jchia029_lab2/safety.h"

Safety::Safety() : nh(), speed(0.0){ init_pub_sub();}

void Safety::init_pub_sub(){
    scan_sub = nh.subscribe("/scan", 1000, &Safety::scan_callback, this);
    odom_sub = nh.subscribe("/odom", 1000, &Safety::odom_callback, this);
    brake_bool_pub = nh.advertise<std_msgs::Bool>("/brake_bool", 1000);
    brake_pub = nh.advertise<ackermann_msgs::AckermannDriveStamped>("/brake", 1000);
}

void Safety::odom_callback(const nav_msgs::Odometry::ConstPtr &odom_msg) {
    // Retrieve current speed for TTC caluclation
    speed = odom_msg->twist.twist.linear.x;
}

void Safety::scan_callback(const sensor_msgs::LaserScan::ConstPtr &scan_msg) {
    
    for (int i = 0; i < (scan_msg->ranges.size())/2; i++){  //Only take front ranging data
        double obs_dist = scan_msg->ranges[i + scan_msg->ranges.size()/4];
        if(!std::isinf(obs_dist) && !std::isnan(obs_dist)){
            // Calculate TTC
            double TTC = obs_dist / std::max(0.0, (speed * cos( i * scan_msg->angle_increment - PI/2)));
            //publish brake messages when TTC less than minimum required TTC
            if (TTC < 0.23){
                // ROS_INFO("TTC%d: %f", i, TTC);  //Used for tuning min TTC
                brake_bool_msg.data = true;
                brake_msg.drive.speed = 0.0;
                brake_bool_pub.publish(brake_bool_msg);
                brake_pub.publish(brake_msg);
            }
        }
    }
}

int main(int argc, char ** argv) {
    ros::init(argc, argv, "safety_node");
    Safety sn;
    ros::spin();
    return 0;
}