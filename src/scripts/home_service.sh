#!/bin/sh
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/workspace/capstone/src/worlds/cryptsky.world " &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/workspace/capstone/src/maps/map.yaml " &
sleep 5
xterm -e " rosrun rviz rviz -d /home/workspace/capstone/src/rvizConfig/one.rviz " &
sleep 15
xterm -e "rosrun add_markers add_markers " &
sleep 5
xterm -e "rosrun pick_objects pick_objects"
