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
     * Main function that moves robot to all desired joint angles 
     */
    void mainJointMovement();

    /**
     * Moves joints to specified angles
     * @param joint_angles desired joint angles
     */
    void moveJoints(std::vector<double> & joint_angles);
    
private:
    // declare plan
    // declare movegroup
    // setup target joint angles
};

#endif // COMMAND_JOINTS