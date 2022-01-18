/*
 * client.cpp
 *
 *  Created on: 2022年1月16日
 *      Author: li
 */
#include <cstdlib>
#include "ros/ros.h"
#include "base_controller/AddTwoInts.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "add_two_ints_client");
	if(argc != 3)
	{
		ROS_INFO("usage: add_two_ints_client X Y");
		return 1;
	}

	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<base_controller::AddTwoInts>("add_two_ints");
	base_controller::AddTwoInts srv;
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);

	if(client.call(srv))
	{
		ROS_INFO("SUM: %ld", (long int)srv.response.sum);
	}
	else
	{
		ROS_ERROR("Failed to call service add_two_ints");
		return 1;
	}
	return 0;
}



