#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <math.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "minimal_commander"); // minimal_commander node
    ros::NodeHandle n;
    ros::Publisher command_publisher = n.advertise<std_msgs::Float64>("vel_cmd", 1); // publish to vel_cmd topic
    ros::Rate naptime(10); // update @ 10hz

    double pi = 3.14159; // value of pi
    double t = 0; // current time in calculation
    double dt = 0.1; // timestep for calculation
    double sine; // sine output
    double amplitude1 = 1; // amplitude value for sine 
    double frequency1 = 1; // frequency value for sine
 
    std_msgs::Float64 output; // message wrapper for sine output

    while (ros::ok()) {
        sine = amplitude * sin(2*pi*frequency*t); // Calculate sine value
        output.data = sine; // Store sine value in proper message format
        command_publisher.publish(output); // Publish value to vel_cmd topic
        t += dt; // Increment t by timeset dt
        naptime.sleep();
    }
}
