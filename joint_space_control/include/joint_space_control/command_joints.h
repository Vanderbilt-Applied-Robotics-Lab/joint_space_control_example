#ifndef COMMAND_JOINTS
#define COMMAND_JOINTS

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
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

    /**
     * prints the transforms
     *
     */
    void printTransform();
    
private:
    moveit::planning_interface::MoveGroupInterface::Plan plan_;
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
    std::vector<double> target_joints_1_ = {M_PI/2.0, 0.0,  0.0, 0.0, 0.0, 0.0};
    std::vector<double> target_joints_2_ = {-M_PI/2.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    // transform stuff
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
};

#endif // COMMAND_JOINTS