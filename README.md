# yoloros_turtlesim
Depend on 
1. leggedrobotics/YOLO ROS: Real-Time Object Detection for ROS 
1.1 opencv 3.4.6
1.2 boost_1_60(the lastest version can not use in this package)
2. ros_kinetic on ubuntu 16.04
3. YOLO ROS in environment path

The objec detection result publish on the topic <B> /darknet_ros/bounding_boxes </B> 
and use the mgsg <B> darknet_ros_msgs/Boundingboxes.msg </B>

The robot turtlesim use the topic <B> /turtle1/cmd_vel </b> 
and use the msge <B> geometry_msgs/Twist.msg </B>

So this project receive the message of darknet_ros and send the instructions to the robot.
