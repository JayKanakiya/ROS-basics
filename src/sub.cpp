#include<iostream>
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "demo_package/demo_msg.h"
#include<sstream>
void number_callback(const demo_package::demo_msg::ConstPtr& msg){
  ROS_INFO("Received %d", msg->number);
  ROS_INFO("Received %s", msg->greeting.c_str());
}

int main(int argc, char **argv){
  ros::init(argc,argv,"subscribe");
  ros::NodeHandle node_obj;
  ros::Subscriber number_sub = node_obj.subscribe("/msg_topic",10,number_callback);
  ros::spin();
  return 0;
}
