#ifndef COMMAND_JOINTS
#define COMMAND_JOINTS

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <cmath>

/**
 * Example of using tf2 to look up a transform
 */
class CommandJoints : public rclcpp::Node
{
public:
    /**
     * Main constructor
     */
    CommandJoints();

    /**
     * Destructor
     */
    ~CommandJoints() = default;

    /**
     * Moves joints to specified angles
     * @param joint_angles desired joint angles
     */
    void moveJoints(std::vector<double> & joint_angles);
    
private:

    // SETUP MOVE GROUP INTERFACE
    // SETUP FIRST JOINT ANGLES 
    // SETUP SECOND JOINT ANGLES
};

#endif // COMMAND_JOINTS