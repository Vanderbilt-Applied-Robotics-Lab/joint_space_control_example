#include <joint_commands_exercise/command_joints.h>

// INSERT CODE HERE!

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