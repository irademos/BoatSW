#ifndef HAL_H
#define HAL_H

// Data structure for INS input
typedef struct {
    float position_x;   // X-coordinate of the position
    float position_y;   // Y-coordinate of the position
    float velocity;     // Velocity of the boat
} INS_Data;

// Data structure for control output
typedef struct {
    float steering;      // Steering angle
    float engine_control; // Engine throttle value
} Control_Output;

// HAL initialization function
void HAL_Init();

// INS data fetching
INS_Data HAL_GetINSData();

// Actuator control
void HAL_SetEngineControl(float control);
void HAL_SetSteering(float steering);

// Utility function for delays
void HAL_Delay(int milliseconds);

#endif
