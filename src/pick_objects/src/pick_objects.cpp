#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

float source[3] = {-2.0, 2.0, 1.0};
float dest[3] = {-7.0, 5.0, 1.0};

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  MoveBaseClient mover("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!mover.waitForServer(ros::Duration(2.0))){
    ROS_INFO("Waiting for the action server to start");
  }

  move_base_msgs::MoveBaseGoal destination;

  destination.target_pose.header.frame_id = "map";
  destination.target_pose.header.stamp = ros::Time::now();
  destination.target_pose.pose.position.x = source[0];
  destination.target_pose.pose.position.y = source[1];
  destination.target_pose.pose.orientation.w = source[2] ;


  ROS_INFO("Sending Pick up location");
  mover.sendGoal(destination);
  mover.waitForResult();

  // Check if the robot reached its goal
  if(mover.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
     
    {
     ROS_INFO("Robot reached source location......");
     ros::Duration(5.0).sleep();
     //Go to drop off point
     // Define a position and orientation for the robot to reach
     destination.target_pose.pose.position.x = dest[0];
     destination.target_pose.pose.position.y = dest[1];
     destination.target_pose.pose.orientation.w = dest[2];
     
     mover.sendGoal(destination);
     // Wait an infinite time for the results
     mover.waitForResult();

  if(mover.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
     {ROS_INFO("Robot reached destination location......");
     ros::Duration(5.0).sleep();}
  else
     {ROS_INFO("Robot failed to reach destination");}
    }
  else
    {ROS_INFO("Robot failed to reach destination");}

  return 0;
}
