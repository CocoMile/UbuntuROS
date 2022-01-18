/*
 * hello.cpp
 *
 *  Created on: 2022年1月16日
 *      Author: li
 */
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "hello");
    ros::NodeHandle n;

    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(1);


    int count = 0;
    while (ros::ok()) {
    	std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());
        chatter_pub.publish(msg);

        ros::spinOnce(); // Allow ROS to process incoming messages
        loop_rate.sleep(); // Sleep for the rest of the cycle
        count++;
    }
 return 0;
}



