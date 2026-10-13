# joint_space_control_example
Example of commanding the meca500 robot in joint space using MoveIt

## Downloading Code
1. Navigate to examples workspace source folder: `cd ~/workspaces/examples_ws/src`
2. Download code: `git clone https://github.com/Vanderbilt-Applied-Robotics-Lab/joint_space_control_example.git`

## Compiling Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Compile the code: `colcon build`

## Running Code
### Simulated Robot
1. Navigate to meca500 workspace: `cd ~/workspaces/meca_ws`
2. Source the meca500 workspace: `source install/setup.bash`
3. Launch the meca500 robot: `ros2 launch meca500_bringup moveit.launch.py simulation:=true`
4. Open a new terminal window
5. Navigate to the examples workspace: `cd ~/workspaces/examples_ws`
6. Source the examples workspace: `source install/setup.bash`
7. Run the code: `ros2 run joint_space_control command_joints`

## Real Robot
1. Connect the meca500 to your computer and turn on power(see quickstart guide)
2. Navigate to meca500 workspace: `cd ~/workspaces/meca_ws`
3. Source the meca500 workspace: `source install/setup.bash`
4. Launch the meca500 robot: `ros2 launch meca500_bringup moveit.launch.py simulation:=false`
5. Wait for robot to release brakes and home. Restart code if robot does not go to home pose.
6. Open a new terminal window
7. Navigate to the examples workspace: `cd ~/workspaces/examples_ws`
8. Source the examples workspace: `source install/setup.bash`
9. Run the code: `ros2 run joint_space_control command_joints`
10. Watch the robot move. Hit the E-Stop if something goes wrong.
11. Shut down the robot (see quickstart guide)
