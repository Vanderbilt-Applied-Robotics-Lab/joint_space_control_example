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
     * Main function that moves to desired joint angles 
     */
    void mainJointMovement();

    /**
     * Moves joints to specified angles
     * @param joint_angles desired joint angles
     */
    void moveJoints(std::vector<double> & joint_angles);
    
private:

    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
    std::vector<double> target_joints_1_ = {M_PI/2.0, 0.0,  0.0, 0.0, 0.0, 0.0};
    std::vector<double> target_joints_2_ = {-M_PI/2.0, 0.0, 0.0, 0.0, 0.0, 0.0};
};

#endif // COMMAND_JOINTS