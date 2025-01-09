#include "hal.h"
#include "ins_processor.h"
#include "control.h"

int main() {
    // Initialize hardware
    HAL_Init();

    // Main loop
    while (1) {
        // Fetch input from INS
        INS_Data ins_data = HAL_GetINSData();

        // Process control logic
        Control_Output output = Control_Process(ins_data);

        // Send commands to actuators
        HAL_SetEngineControl(output.engine_control);
        HAL_SetSteering(output.steering);
    }

    return 0;
}
