#include <ros/ros.h>
#include <string.h>
#include <darknet_ros_msgs/BoundingBoxes.h>
#include <darknet_ros_msgs/BoundingBox.h>
#include <geometry_msgs/Twist.h>

geometry_msgs::Twist res;

void resinit(){
	res.linear.x=0.0;
	res.linear.y=0.0;
	res.linear.z=0.0;
	res.angular.x=0.0;
	res.angular.y=0.0;
	res.angular.z=0.0;	
}

void msgCallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr& msg){
	ROS_INFO("receive [%s]",msg->bounding_boxes[0].Class.c_str());

	if (strcmp(msg->bounding_boxes[0].Class.c_str(),"g10") == 0){
		resinit();
		res.linear.x = 0.5;
		ROS_INFO("forward");
	}
	else if (strcmp(msg->bounding_boxes[0].Class.c_str(),"g2") == 0){
		resinit();
		res.angular.z = 1.0;	
		ROS_INFO("angular");
	}
	else if (strcmp(msg->bounding_boxes[0].Class.c_str(),"g4") == 0){
		resinit();
		ROS_INFO("stop");
	}
	else if (strcmp(msg->bounding_boxes[0].Class.c_str(),"g9") == 0){
		resinit();
		res.linear.x = -0.5;	
		ROS_INFO("back");
	}
	else{
		resinit();
		res.linear.x = 1.0;
		res.angular.z = 1.0;
		ROS_INFO("round");
	}
}

int main(int argc,char **argv){
	ros::init(argc,argv,"subscriber");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("/darknet_ros/bounding_boxes",1000,msgCallback);
	//turtlebot2
	//ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",1000);
	//turtlesim
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel",1000);	
	
	while (ros::ok()){
		ros::spinOnce();
		pub.publish(res);	
	}

	return 0;
}
