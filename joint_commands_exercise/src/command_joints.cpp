#include <joint_commands_exercise/command_joints.h>

CommandJoints::CommandJoints() : Node("joint_commands")
{ 
    // MOVE JOINTS TO FIRST JOINT CONFIGURATION
    // MOVE JOINTS TO SECOND JOINT CONFIGURATION
}

void CommandJoints::moveJoints(std::vector<double> & joint_angles)
{
    // INSERT CODE HERE!
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