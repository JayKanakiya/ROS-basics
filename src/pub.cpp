#include<iostream>
#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "demo_package/demo_msg.h"
#include<sstream>
int main(int argc, char **argv){
  ros::init(argc,argv,"pub");
  ros::NodeHandle node_obj;
  ros::Publisher number_pub = node_obj.advertise<demo_package::demo_msg>("/msg_topic",10);
  ros::Rate loop_rate(10);
  int count = 0;
  while(ros::ok()){
    demo_package::demo_msg msg;
    //msg.greeting = "Hello World!";
    std::stringstream ss;
    ss<<"Hello World!";
    msg.greeting = ss.str();
    msg.number = count;
    ROS_INFO("%s",msg.greeting.c_str());
    ROS_INFO("%d", msg.number);
    number_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    count++;
  }
  return 0;
}
