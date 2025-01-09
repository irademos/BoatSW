#include "hal.h"
#include <stdio.h>
#include <unistd.h> // For usleep()

void HAL_Init() {
    // Initialize hardware peripherals
    printf("Initializing hardware...\n");
    // Here, you would initialize GPIOs, communication buses (e.g., I2C, SPI), etc.
}

INS_Data HAL_GetINSData() {
    // Stubbed data for simulation
    static float x = 0.0;
    static float y = 0.0;
    static float velocity = 1.0;

    x += velocity * 0.1; // Simulate movement
    y += velocity * 0.1;

    INS_Data data = {x, y, velocity};
    return data;
}

void HAL_SetEngineControl(float control) {
    // Send control command to the engine (stub)
    printf("Setting engine control to %f\n", control);
    // Actual implementation would involve writing to hardware registers or communication interfaces.
}

void HAL_SetSteering(float steering) {
    // Send steering command to actuators (stub)
    printf("Setting steering angle to %f\n", steering);
    // Actual implementation would depend on the actuator interface.
}

void HAL_Delay(int milliseconds) {
    // Convert milliseconds to microseconds and sleep
    usleep(milliseconds * 1000);
}
