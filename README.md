# Project 3 - Map My World

The final project of the Udacity Robotics Nanodegree incorporates a number of elements from previous projects, rolling them into a single solution that would actually be required to engineer a home service robot:
1. Build a simulated map using Gazebo building editor
2. Build a map of the environment using gmapping and teleop.
3. Use Adaptive Monte Carlo Localisation to detect the robot position within the known map.
4. Use the ROS move_base library to plot a path to a target pose and navigate to it.
5. Write a custom node to encompass the path planning and driving libraries, listening for goal poses.
6. Write a custom node to publish goal poses for the robot, then compare these to the actual pose (odometry topic) to determine success.

![Home Service Robot Image](./result.png?raw=true "Home Service Robot In Action")

# Installation
This repository is intended to run only on Linux Ubuntu v16.04 with ROS Kinetic. Create a Catkin Workspace if you have not already done so, as explained here ((here)[http://wiki.ros.org/catkin/Tutorials/create_a_workspace]).

To install, clone the repository to /home/workspace. The command below will pull all required submodules and copy directly to Catkin Workspace.
`git clone --recurse-submodules https://github.com/PatrickMockridge/RoboND-Home-Service-Robot.git .`

Once all the necessary files are in place, run the following commands from the catkin_ws directory:
1. `source devel/setup.bash`
2. `catkin_make`
3. `sudo chmod 7 src/scripts/*.sh`

The default rviz configuration can be updated to show the marker locations running the following in a new terminal:
`cp /home/workspace/catkin_ws/src/RVizConfig/navigation.rviz /home/workspace/catkin_ws/src/turtlebot_interactions/turtlebot_rviz_launchers/rviz/`

# Running the Simulation
Now you should be prepared to go. From the `capstone/` directory run the following command:
`./src/scripts/home_service.sh`

## Result
![alt text](200613113527154.png)

### How to clone this repository
```
$ cd ~/catkin_ws

$ git clone https://github.com/cryptSky/RoboND_Home_Service_Robot
```

