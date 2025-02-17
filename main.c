/*****************************************************************************
* File        : minecraft_clock_rotating.c
* Author      : Based on Waveshare examples
* Description : Animated Minecraft clock display for RP2040-LCD-1.28
* Details     : Creates a rotating clock face that mimics the Minecraft day/night
*               cycle clock item. The clock face consists of blue arcs that rotate
*               around a yellow center on a brown background.
******************************************************************************/

// Include all necessary header files for our project
#include "LCD_Test.h"      // Contains core LCD testing utilities
#include "LCD_1in28.h"     // Specific header for our 1.28 inch LCD display
#include <stdio.h>         // Standard input/output operations
#include "pico/stdlib.h"   // Core Raspberry Pi Pico functionality
#include <math.h>          // Mathematical functions for rotation calculations

// Define our custom colors to match Minecraft's aesthetic
// RGB macro creates 16-bit color values from RGB components
// RGB565 color conversion macro
#define RGB_(r, g, b) ((((r) & 0xF8) << 8) | (((g) & 0xFC) << 3) | ((b) >> 3))

#define MINECRAFT_BLUE   RGB_(51, 51, 255)    // The blue color used for the rotating arcs
#define MINECRAFT_YELLOW RGB_(255, 255, 0)     // The yellow color for the center and background
#define MINECRAFT_BROWN  RGB_(139, 69, 19)     // The brown color for the outer border

/*****************************************************************************
* Function    : draw_clock_face
* Description : Draws a single frame of the clock at a specified rotation angle
* Parameters  : imageBuffer - Pointer to the display buffer
*               angle - Current rotation angle in radians
* Note        : This function completely redraws the clock face each frame
******************************************************************************/
void draw_clock_face(uint16_t *imageBuffer, float angle) {
    // Step 1: Initialize the drawing canvas
    // Convert our uint16_t buffer to uint8_t as required by the Paint functions
    Paint_NewImage((uint8_t *)imageBuffer, LCD_1IN28.WIDTH, LCD_1IN28.HEIGHT, 0, WHITE);
    
    // Set the scaling factor for our drawing operations
    // 65 is the recommended value for this display by Waveshare
    Paint_SetScale(65);
    
    // Clear the entire canvas to white
    // This gives us a clean slate to work with
    Paint_Clear(WHITE);
    
    // Set the rotation to 0 degrees
    // This is our base rotation, we'll handle animation rotation separately
    Paint_SetRotate(ROTATE_0);
    
    // Step 2: Calculate center point of our display
    // Our display is 240x240 pixels, so center is at (120,120)
    uint16_t centerX = LCD_1IN28.WIDTH / 2;   // Horizontal center (120 pixels)
    uint16_t centerY = LCD_1IN28.HEIGHT / 2;  // Vertical center (120 pixels)
    
    // Define the size of each "pixel" block
    // This creates the chunky Minecraft aesthetic
    uint16_t pixelSize = 8;  // Each game "pixel" is 8x8 real pixels
    
    // Step 3: Draw the outer brown circle border
    // This creates the frame for our clock
    // Radius of 80 gives us a good size for the 240x240 display
    Paint_DrawCircle(centerX, centerY, 80, MINECRAFT_BROWN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    
    // Step 4: Draw the yellow background circle
    // Slightly smaller than the brown border
    Paint_DrawCircle(centerX, centerY, 70, MINECRAFT_YELLOW, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    
    // Step 5: Pre-calculate sine and cosine values
    // This optimization prevents recalculating for each pixel
    float cos_angle = cos(angle);  // Cosine of our rotation angle
    float sin_angle = sin(angle);  // Sine of our rotation angle
    
    // Step 6: Draw the rotating blue arc segments
    // Iterate through a 13x13 grid (-6 to 6 in both dimensions)
    for(int x = -6; x <= 6; x++) {
        for(int y = -6; y <= 6; y++) {
            // Check if this point falls within our arc shape
            // Using the equation of a ring: r1² ≤ x² + y² ≤ r2²
            if(x*x + y*y <= 36 && x*x + y*y >= 16) {
                // Apply rotation transformation to this point
                // [x'] = [cos θ  -sin θ] [x]
                // [y'] = [sin θ   cos θ] [y]
                float rotated_x = x * cos_angle - y * sin_angle;
                float rotated_y = x * sin_angle + y * cos_angle;
                
                // Only draw pixels that fall in the correct quadrants
                // This creates our two-arc pattern
                if ((rotated_x < 0 && rotated_y < 0) || (rotated_x > 0 && rotated_y > 0)) {
                    // Draw a rectangle representing one game "pixel"
                    Paint_DrawRectangle(
                        centerX + x * pixelSize,          // Left edge
                        centerY + y * pixelSize,          // Top edge
                        centerX + (x+1) * pixelSize - 1,  // Right edge
                        centerY + (y+1) * pixelSize - 1,  // Bottom edge
                        MINECRAFT_BLUE,                   // Blue color
                        DOT_PIXEL_1X1,                   // 1 pixel line width
                        DRAW_FILL_FULL                   // Solid fill
                    );
                }
            }
        }
    }
    
    // Step 7: Draw the center yellow pixels
    // This is a 3x3 grid of pixels that doesn't rotate
    for(int x = -1; x <= 1; x++) {
        for(int y = -1; y <= 1; y++) {
            Paint_DrawRectangle(
                centerX + x * pixelSize,
                centerY + y * pixelSize,
                centerX + (x+1) * pixelSize - 1,
                centerY + (y+1) * pixelSize - 1,
                MINECRAFT_YELLOW,
                DOT_PIXEL_1X1,
                DRAW_FILL_FULL
            );
        }
    }
}

/*****************************************************************************
* Function    : main
* Description : Main program entry point and animation loop
* Returns     : 0 on success, -1 on failure
******************************************************************************/
int main(void) {
    // Step 1: Initialize system components
    // Set up standard input/output
    stdio_init_all();
    
    // Initialize the display module and check for errors
    if (DEV_Module_Init() != 0) {
        printf("ERROR: Device initialization failed!\r\n");
        return -1;
    }
    
    // Print startup message to serial console
    printf("Rotating Minecraft Clock - Starting\r\n");
    
    // Step 2: Initialize the LCD display
    // Set horizontal orientation and clear to white
    LCD_1IN28_Init(HORIZONTAL);
    LCD_1IN28_Clear(WHITE);
    
    // Set the backlight to maximum brightness
    DEV_SET_PWM(100);
    
    // Step 3: Allocate memory for the image buffer
    // Calculate required size: width * height * 2 bytes per pixel
    uint32_t imageSize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;
    uint16_t *imageBuffer = (uint16_t *)malloc(imageSize);
    
    // Check if memory allocation was successful
    if (imageBuffer == NULL) {
        printf("ERROR: Memory allocation failed\r\n");
        return -1;
    }
    
    // Step 4: Set up animation variables
    // Current rotation angle (in radians)
    float angle = 0.0f;
    
    // Calculate rotation speed
    // 2π radians = 360 degrees = one full rotation
    // Divide by 24.0 to complete rotation in 24 seconds
    const float rotation_speed = 2 * M_PI / 24.0f;
    
    // Keep track of the last frame time for smooth animation
    uint32_t last_time = time_us_32();
    
    // Step 5: Main animation loop
    while (1) {
        // Get current time in microseconds
        uint32_t current_time = time_us_32();
        
        // Calculate elapsed time in seconds since last frame
        float elapsed = (current_time - last_time) / 1000000.0f;
        
        // Update rotation angle
        angle -= rotation_speed * elapsed;
        
        // Keep angle between 0 and 2π
        if (angle >= 2 * M_PI) {
            angle += 2 * M_PI;
        }
        
        // Draw the clock face at current rotation angle
        draw_clock_face(imageBuffer, angle);
        
        // Update the display with new frame
        LCD_1IN28_Display(imageBuffer);
        
        // Save current time for next frame
        last_time = current_time;
        
        // Add a small delay to prevent screen tearing
        // and reduce CPU usage
        DEV_Delay_ms(20);  // 20ms = ~50 FPS
    }
    
    // Step 6: Cleanup
    // Note: This code is never reached due to infinite loop
    // But it's good practice to include cleanup code
    free(imageBuffer);      // Free allocated memory
    DEV_Module_Exit();      // Clean up device module
    return 0;               // Return success
}