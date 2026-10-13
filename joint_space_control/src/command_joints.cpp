#include <joint_space_control/command_joints.h>

CommandJoints::CommandJoints() : Node("joint_commands")
{
    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
}

void CommandJoints::mainJointMovement()
{
    // initialize movegroup
    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
            shared_from_this(), "meca500_arm");

    moveJoints(target_joints_1_);
    printTransform();
    moveJoints(target_joints_2_);
    printTransform();
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

void CommandJoints::printTransform()
{
    try
    {
        geometry_msgs::msg::TransformStamped transform = tf_buffer_->lookupTransform("meca_base_link", "meca_axis_6_link", tf2::TimePointZero);
        RCLCPP_INFO(this->get_logger(), "Position -- x: %0.2f, y: %0.2f, z: %0.2f", transform.transform.translation.x, transform.transform.translation.y, transform.transform.translation.z);
        RCLCPP_INFO(this->get_logger(), "Orientation -- w: %0.2f, x: %0.2f, y: %0.2f, z: %0.2f", transform.transform.rotation.w, transform.transform.rotation.x, transform.transform.rotation.y, transform.transform.rotation.z);
    }
    catch (const tf2::TransformException & ex)
    {
        RCLCPP_ERROR(this->get_logger(), "lookup failed!");
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