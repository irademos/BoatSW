#include "control.h"

Control_Output Control_Process(INS_Data ins_data) {
    Control_Output output;

    // Simple control logic:
    // - Maintain a constant velocity
    // - Adjust steering based on position
    float desired_velocity = 5.0; // Target velocity
    float position_tolerance = 0.5;

    // Proportional control for velocity
    output.engine_control = (desired_velocity - ins_data.velocity) * 0.8;

    // Steering logic: Adjust based on position
    if (ins_data.position_x > position_tolerance) {
        output.steering = -10.0; // Turn left
    } else if (ins_data.position_x < -position_tolerance) {
        output.steering = 10.0; // Turn right
    } else {
        output.steering = 0.0; // Go straight
    }

    return output;
}
