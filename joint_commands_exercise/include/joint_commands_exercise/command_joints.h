#ifndef COMMAND_JOINTS
#define COMMAND_JOINTS

#include <rclcpp/rclcpp.hpp>
// INSERT INCLUDES HERE 
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
    // INSERT CODE HERE
};

#endif // COMMAND_JOINTS