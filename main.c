#include <stdio.h>         // Standard input/output operations
#include <math.h>          // Mathematical functions for rotation calculations
#include "LCD_Test.h"      // Contains core LCD testing utilities
#include "LCD_1in28.h"     // Specific header for our 1.28 inch LCD display
#include "pico/stdlib.h"   // Core Raspberry Pi Pico functionality
#include "time_header.h"   // Header file including all time pixel color functions

// Array of function pointers for 64 different time pixel color functions
uint16_t (*color_functions[64])(int, int) = {
    time_1_pixel_color, time_2_pixel_color, time_3_pixel_color, time_4_pixel_color,
    time_5_pixel_color, time_6_pixel_color, time_7_pixel_color, time_8_pixel_color,
    time_9_pixel_color, time_10_pixel_color, time_11_pixel_color, time_12_pixel_color,
    time_13_pixel_color, time_14_pixel_color, time_15_pixel_color, time_16_pixel_color,
    time_17_pixel_color, time_18_pixel_color, time_19_pixel_color, time_20_pixel_color,
    time_21_pixel_color, time_22_pixel_color, time_23_pixel_color, time_24_pixel_color,
    time_25_pixel_color, time_26_pixel_color, time_27_pixel_color, time_28_pixel_color,
    time_29_pixel_color, time_30_pixel_color, time_31_pixel_color, time_32_pixel_color,
    time_33_pixel_color, time_34_pixel_color, time_35_pixel_color, time_36_pixel_color,
    time_37_pixel_color, time_38_pixel_color, time_39_pixel_color, time_40_pixel_color,
    time_41_pixel_color, time_42_pixel_color, time_43_pixel_color, time_44_pixel_color,
    time_45_pixel_color, time_46_pixel_color, time_47_pixel_color, time_48_pixel_color,
    time_49_pixel_color, time_50_pixel_color, time_51_pixel_color, time_52_pixel_color,
    time_53_pixel_color, time_54_pixel_color, time_55_pixel_color, time_56_pixel_color,
    time_57_pixel_color, time_58_pixel_color, time_59_pixel_color, time_60_pixel_color,
    time_61_pixel_color, time_62_pixel_color, time_63_pixel_color, time_64_pixel_color
};

// Function to draw the clock face
void draw_clock_face(uint16_t *imageBuffer, float angle) {
    // Initialize a new image with white background
    Paint_NewImage((uint8_t *)imageBuffer, LCD_1IN28.WIDTH, LCD_1IN28.HEIGHT, 0, WHITE);
    Paint_SetScale(65);  // Set the scale for drawing
    Paint_Clear(BLACK);  // Clear the image with black color
    Paint_SetRotate(ROTATE_0);  // Set the rotation to 0 degrees

    // Calculate the center of the display
    uint16_t centerX = LCD_1IN28.WIDTH / 2;
    uint16_t centerY = LCD_1IN28.HEIGHT / 2; 
    uint16_t pixelSize = 24;  // Size of each pixel block

    uint16_t color;
    // Loop through a 11x11 grid centered on the display
    for (int x = -5; x < 6; x++) {
        for (int y = -5; y < 6; y++) {
            // Calculate the index for the color function based on the angle
            int index = (int)(angle / (2 * M_PI) * 64) % 64;
            // Get the color for the current pixel
            color = color_functions[index](x, y);
            // Draw the pixel block on the display
            Paint_DrawRectangle(centerX + x * pixelSize, centerY + y * pixelSize, centerX + (x+1) * pixelSize, centerY + (y+1) * pixelSize, color, DOT_PIXEL_1X1, DRAW_FILL_FULL);
        }
    }
}

int main(void) {
    stdio_init_all();  // Initialize standard I/O

    // Initialize the device module and check for errors
    if (DEV_Module_Init() != 0) {
        printf("ERROR: Device initialization failed!\r\n");
        return -1;
    }
    
    // Initialize the LCD display
    LCD_1IN28_Init(HORIZONTAL);
    LCD_1IN28_Clear(WHITE);  // Clear the display with white color
    
    // Set the backlight to maximum brightness
    DEV_SET_PWM(100);

    // Calculate the size of the image buffer
    uint32_t imageSize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;
    // Allocate memory for the image buffer
    uint16_t *imageBuffer = (uint16_t *)malloc(imageSize);

    // Calculate the initial angle based on the current time (17:30)
    float initial_time_seconds = 17 * 3600 + 47 * 60; // 17:30 in seconds
    float angle = fmod(((initial_time_seconds + 43200) / 86400.0) * 2 * M_PI, 2 * M_PI); // Initial angle in radians

    const float rotation_speed = 2 * M_PI / 86400.0f; // Rotation speed for 24 hours
    uint32_t last_time = time_us_32();  // Get the current time in microseconds

    while (1) {
        uint32_t current_time = time_us_32();  // Get the current time in microseconds
        float elapsed = (current_time - last_time) / 1000000.0f;  // Calculate elapsed time in seconds
        angle += rotation_speed * elapsed;  // Update the angle based on the elapsed time
        
        // Keep the angle within the range of 0 to 2π
        if (angle >= 2 * M_PI) {
            angle -= 2 * M_PI;
        }
        
        // Draw the clock face with the current angle
        draw_clock_face(imageBuffer, angle);
        // Display the image buffer on the LCD
        LCD_1IN28_Display(imageBuffer);
        last_time = current_time;  // Update the last time

        sleep_ms(60000);  // Sleep for 1 minute
    }

    free(imageBuffer);  // Free the allocated memory
    DEV_Module_Exit();  // Exit the device module
    return 0;  // Return success
}