
![Home Service Robot Image](./result.png "Home Service Robot In Action")

In this project I have put togather solution and implemented the two nodes to pick up and drop a can, which home serveice robot to performs using SLAM on built map of the environment. Robot equipped with laser range finder sensors or RGB-D cameras.

The solution uses Adaptive Monte Carlo Localisation to detect the robot position within the known map.
Solution uses move_base library to plot a path to a target pose and navigate to it.

To install, clone the repository to /home/workspace. The command below will pull all required submodules and copy directly to Catkin Workspace.
`git clone https://github.com/cryptSky/RoboND_Home_Service_Robot.git .`

Once all the necessary files are in place, run the following commands from the catkin_ws directory:
1. `source devel/setup.bash`
2. `catkin_make`
3. `sudo chmod 7 src/scripts/*.sh`

# Running the Simulation
Now you should be prepared to go. From the `catkin_ws/` directory run the following command:
`./src/scripts/one.sh`
