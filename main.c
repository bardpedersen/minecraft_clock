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

#define MINECRAFT_SKY_1   RGB_(64, 71, 174)
#define MINECRAFT_SKY_2   RGB_(81, 89, 219)
#define MINECRAFT_SUN_1   RGB_(248, 255, 0)
#define MINECRAFT_SUN_2   RGB_(198, 211, 0)
#define MINECRAFT_NIGHT_1 RGB_(30, 28, 28)
#define MINECRAFT_NIGHT_2 RGB_(24, 22, 22)
#define MINECRAFT_MOON_1  RGB_(110, 105, 138)
#define MINECRAFT_MOON_2  RGB_(88, 84, 110)

/*****************************************************************************
* Function    : draw_clock_face
* Description : Draws a single frame of the clock at a specified rotation angle
* Parameters  : imageBuffer - Pointer to the display buffer
*               angle - Current rotation angle in radians
* Note        : This function completely redraws the clock face each frame
******************************************************************************/
void draw_clock_face_one(uint16_t *imageBuffer) {
    Paint_NewImage((uint8_t *)imageBuffer, LCD_1IN28.WIDTH, LCD_1IN28.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(BLACK);
    Paint_SetRotate(ROTATE_0);
    

    uint16_t centerX = LCD_1IN28.WIDTH / 2;
    uint16_t centerY = LCD_1IN28.HEIGHT / 2; 
    uint16_t pixelSize = 24; 

    uint16_t color;
    for (int x = -5; x < 6; x++) {
        for (int y = -5; y < 6; y++) {
            if (x == -5 && y == -1) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -5 && y == 0) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -4 && y == -3) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -4 && y == -2) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -4 && y == -1) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -4 && y == 0) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -4 && y == 1) {
                color = MINECRAFT_NIGHT_1;
            }
            else if (x == -3 && y == -4) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -3 && y == -3) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -3 && y == -2) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == -3 && y == -1) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == -3 && y == 0) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == -3 && y == 1) {
                color = MINECRAFT_NIGHT_1;
            }
            else if (x == -2 && y == -4) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -2 && y == -3) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == -2 && y == -2) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == -2 && y == -1) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == -2 && y == 0) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == -2 && y == 1) {
                color = MINECRAFT_NIGHT_1;
            }
            else if (x == -1 && y == -5) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == -1 && y == -4) {
                color = MINECRAFT_SUN_2;
            }
            else if (x == -1 && y == -3) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == -1 && y == -2) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == -1 && y == -1) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == 0 && y == -5) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == 0 && y == -4) {
                color = MINECRAFT_SUN_2;
            }
            else if (x == 0 && y == -3) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == 0 && y == -2) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == 0 && y == -1) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == 1 && y == -4) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == 1 && y == -3) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == 1 && y == -2) {
                color = MINECRAFT_SUN_1;
            }
            else if (x == 1 && y == -1) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 1 && y == 0) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == 1 && y == 1) {
                color = MINECRAFT_NIGHT_1;
            }
            else if (x == 2 && y == -4) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == 2 && y == -3) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 2 && y == -2) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 2 && y == -1) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 2 && y == 0) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 2 && y == 1) {
                color = MINECRAFT_NIGHT_1;
            }
            else if (x == 3 && y == -3) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == 3 && y == -2) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 3 && y == -1) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 3 && y == 0) {
                color = MINECRAFT_SKY_2;
            }
            else if (x == 3 && y == 1) {
                color = MINECRAFT_NIGHT_1;
            }
            else if (x == 4 && y == -1) {
                color = MINECRAFT_SKY_1;
            }
            else if (x == 4 && y == 0) {
                color = MINECRAFT_SKY_1;
            }
            else {
                color = BLACK;
            }
            Paint_DrawRectangle(centerX + x * pixelSize, centerY + y * pixelSize, centerX + (x+1) * pixelSize, centerY + (y+1) * pixelSize, color, DOT_PIXEL_1X1, DRAW_FILL_FULL);
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
    
    // Step 2: Initialize the LCD display
    // Set horizontal orientation and clear to white
    LCD_1IN28_Init(HORIZONTAL);
    LCD_1IN28_Clear(WHITE);
    
    // Set the backlight to maximum brightness
    DEV_SET_PWM(65);

    uint32_t imageSize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;
    uint16_t *imageBuffer = (uint16_t *)malloc(imageSize);
    

    float angle = 0.0f;
    const float rotation_speed = 2 * M_PI / 24.0f;
    uint32_t last_time = time_us_32();
    
    while (1) {
        // Get current time in microseconds
        uint32_t current_time = time_us_32();
        
        // Calculate elapsed time in seconds since last frame
        float elapsed = (current_time - last_time) / 1000000.0f;
        angle -= rotation_speed * elapsed;
        
        // Keep angle between 0 and 2π
        if (angle >= 2 * M_PI) {
            angle += 2 * M_PI;
        }
        
        // Draw the clock face at current rotation angle
        draw_clock_face_one(imageBuffer);
        LCD_1IN28_Display(imageBuffer);
        last_time = current_time;

        DEV_Delay_ms(20);  // 20ms = ~50 FPS
    }
    
    // Step 6: Cleanup
    // Note: This code is never reached due to infinite loop
    // But it's good practice to include cleanup code
    free(imageBuffer);      // Free allocated memory
    DEV_Module_Exit();      // Clean up device module
    return 0;               // Return success
}