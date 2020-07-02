
![Home Service Robot Image](./result.png "Home Service Robot In Action")

To install, clone the repository to /home/workspace. The command below will pull all required submodules and copy directly to Catkin Workspace.
`git clone git clone https://github.com/cryptSky/RoboND_Home_Service_Robot.git .`

Once all the necessary files are in place, run the following commands from the catkin_ws directory:
1. `source devel/setup.bash`
2. `catkin_make`
3. `sudo chmod 7 src/scripts/*.sh`

The default rviz configuration can be updated to show the marker locations running the following in a new terminal:
`cp /home/workspace/catkin_ws/src/RVizConfig/navigation.rviz /home/workspace/catkin_ws/src/turtlebot_interactions/turtlebot_rviz_launchers/rviz/`

# Running the Simulation
Now you should be prepared to go. From the `catkin_ws/` directory run the following command:
`./src/scripts/home_service.sh`
