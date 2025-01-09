#include "ins_processor.h"

INS_Data Process_INS_Data(INS_Data raw_data) {
    // Example: Apply a filter to smooth out noise in the INS data
    static INS_Data previous_data = {0.0, 0.0, 0.0};

    INS_Data smoothed_data;
    smoothed_data.position_x = 0.9 * previous_data.position_x + 0.1 * raw_data.position_x;
    smoothed_data.position_y = 0.9 * previous_data.position_y + 0.1 * raw_data.position_y;
    smoothed_data.velocity = 0.9 * previous_data.velocity + 0.1 * raw_data.velocity;

    // Update previous data for the next iteration
    previous_data = smoothed_data;

    return smoothed_data;
}
