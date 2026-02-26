#include <joint_commands_exercise/command_joints.h>

CommandJoints::CommandJoints() : Node("joint_commands")
{
}

void CommandJoints::mainJointMovement()
{
    // initialize movegroup

    // move to first joint angles
    // move to second joint angles
}

void CommandJoints::moveJoints(std::vector<double> & joint_angles)
{
    // set movegroup to target joint angles

    // if move plan succeeded, execute plan
    // print error otherwise
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