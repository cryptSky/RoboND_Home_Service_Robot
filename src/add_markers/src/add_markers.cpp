#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include <complex>

float source[3] = {-2.0, 2.0, 1.0};
float destination[3] = {-7.0, 5.0, 1.0};
float threshold[2] = {0.4, 0.5};

bool isSourceLocation = false;
bool isDestinationLocation = false;
bool picked = false;
bool dropped = false;


void positionChecker(const nav_msgs::Odometry::ConstPtr& msg)
{   

   float pick_distance = std::sqrt((std::abs(source[0]) -std::abs(msg->pose.pose.position.x))*(std::abs(source[0]) -std::abs(msg->pose.pose.position.y))+(std::abs(source[1]) -std::abs(msg->pose.pose.position.y))*(std::abs(source[1]) -std::abs(msg->pose.pose.position.y)));
   float pick_angle = source[2]-msg->pose.pose.orientation.w-1.57;

   float drop_distance = std::sqrt((std::abs(destination[1]) -std::abs(msg->pose.pose.position.x))*(std::abs(destination[1]) -std::abs(msg->pose.pose.position.x))+(std::abs(destination[0]) -std::abs(msg->pose.pose.position.y))*(std::abs(destination[0]) -std::abs(msg->pose.pose.position.y)));

   float drop_angle = destination[2]-msg->pose.pose.orientation.w-1.57;


ROS_INFO(" pick_distance =  %f, pick_angle = %f", pick_distance, pick_angle);
ROS_INFO(" drop_distance =  %f, drop_angle = %f", drop_distance, drop_angle);

if (pick_distance < threshold[0] && std::abs(pick_angle) < threshold[1])
   { 
    	if(!isSourceLocation)
     	{
     		isSourceLocation = true;
     	}
    }
    

if (drop_distance < threshold[0] && std::abs(drop_angle) < threshold[1])
  { 
    	if(!isDestinationLocation)
    	{
     		isDestinationLocation = true;
    	}
   }

}

int main( int argc, char** argv )
{
  ROS_INFO("Main");
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher can_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odometry_subscriber = n.subscribe("odom", 1000, positionChecker);
  
  uint32_t shape = visualization_msgs::Marker::CYLINDER;

  while (ros::ok())
  {
    visualization_msgs::Marker can;
        can.header.frame_id = "map";
    can.header.stamp = ros::Time::now();

   
    can.ns = "basic_shapes";
    can.id = 0;

    can.type = shape;
    can.action = visualization_msgs::Marker::ADD;
    can.pose.position.x = source[0];
    can.pose.position.y = source[1];
    can.pose.position.z = 0;
    
    can.pose.orientation.x = 0.0;
    can.pose.orientation.y = 0.0;
    can.pose.orientation.z = 0.0;
    can.pose.orientation.w = source[2];

    can.scale.x = 0.2;
    can.scale.y = 0.2;
    can.scale.z = 0.2;

    
    can.color.r = 1.0f;
    can.color.g = 1.0f;
    can.color.b = 0.0f;
    can.color.a = 1.0;

    can.lifetime = ros::Duration();

    while (can_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a robot for a can to be picked up");
      sleep(1);
    }
    
   can_pub.publish(can);
   ROS_INFO("Can displayed");

   while(!isSourceLocation)
   {
    ros::spinOnce();
   }
   
   if(isSourceLocation && !picked)
   {
    can.action = visualization_msgs::Marker::DELETE;
    can_pub.publish(can);
    ROS_INFO("Robot picked up the can");
    picked = true;
   }  

   while(!isDestinationLocation)
   {
    ros::spinOnce();
   }

   if(isDestinationLocation && !dropped)
   {
    can.pose.position.x = destination[0];
    can.pose.position.y = destination[1];
    can.pose.orientation.w = destination[2];;
    can.action = visualization_msgs::Marker::ADD;
    can_pub.publish(can);
    ROS_INFO("Can has moved to the destination");
    dropped = true;
    ros::Duration(5.0).sleep();
   }  
    return 0;
  }
 
}
