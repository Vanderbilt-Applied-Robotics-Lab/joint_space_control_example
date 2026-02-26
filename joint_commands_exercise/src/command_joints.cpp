#include <joint_commands_exercise/command_joints.h>

CommandJoints::CommandJoints() : Node("joint_commands")
{
    moveJoints(target_joints_1_);
    moveJoints(target_joints_2_);
}

void CommandJoints::moveJoints(std::vector<double> & joint_angles)
{
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    move_group_.setJointValueTarget(joint_angles);

    if (move_group_.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS)
    {
        move_group_.execute(plan);
    }
    else
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
    
    rclcpp::shutdown();
    return 0;
}