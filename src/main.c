#include <stdio.h>
#include "hal.h"
#include "ins_processor.h"
#include "control.h"

int main() {
    // Initialize hardware and peripherals
    HAL_Init();

    printf("System initialized successfully.\n");

    // Main control loop
    while (1) {
        // Fetch input data from INS
        INS_Data ins_data = HAL_GetINSData();

        // Debug INS data
        printf("INS Data: Position (%f, %f), Velocity: %f\n",
               ins_data.position_x, ins_data.position_y, ins_data.velocity);

        // Process control logic based on INS data
        Control_Output control_output = Control_Process(ins_data);

        // Debug control output
        printf("Control Output: Engine Control: %f, Steering: %f\n",
               control_output.engine_control, control_output.steering);

        // Send control commands to actuators
        HAL_SetEngineControl(control_output.engine_control);
        HAL_SetSteering(control_output.steering);

        // Simulate a delay to mimic real-time processing
        HAL_Delay(100); // 100 ms delay
    }

    return 0;
}
