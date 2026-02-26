#include <joint_commands_exercise/command_joints.h>

CommandJoints::CommandJoints() : Node("joint_commands")
{
}

void CommandJoints::mainJointMovement()
{
    // initialize movegroup
    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
            shared_from_this(), "rv_3s_arm");

    moveJoints(target_joints_1_);
    moveJoints(target_joints_2_);
}

void CommandJoints::moveJoints(std::vector<double> & joint_angles)
{
    // set movegroup to target joint angles
    move_group_->setJointValueTarget(joint_angles);

    // if move plan succeeded, move robot
    if (move_group_->plan(plan_) == moveit::core::MoveItErrorCode::SUCCESS)
    {
        move_group_->execute(plan_);
    }
    else // print error otherwise
    {
        RCLCPP_INFO(this->get_logger(), "Plan failed");
    }

}

int main(int argc, char** argv)
{
    // initialize the node
    rclcpp::init(argc, argv);
    
    // create instance of class
    auto node = std::make_shared<CommandJoints>();

    node->mainJointMovement();
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}