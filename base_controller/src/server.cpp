/*
 * server.cpp
 *
 *  Created on: 2022年1月16日
 *      Author: li
 */
#include "ros/ros.h"
#include "base_controller/AddTwoInts.h"

bool add(base_controller::AddTwoInts::Request &req, base_controller::AddTwoInts::Response &res)
{
	res.sum = req.a + req.b;
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: [%ld]", (long int)res.sum);
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "add_two_ints_server");
	ros::NodeHandle n;

	ros::ServiceServer service = n.advertiseService("add_two_ints", add);
	ROS_INFO("Ready to add tow ints.");
	ros::spin();
	return 0;
}



