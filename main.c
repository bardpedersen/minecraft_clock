#include "LCD_Test.h"
#include "LCD_1in28.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main(void)
{
    // Initialize the DEV Module
    if (DEV_Module_Init() != 0) {
        return -1;
    }
    
    printf("LCD 1.28 Circle Demo\r\n");
    
    // Initialize LCD and clear with white background
    LCD_1IN28_Init(HORIZONTAL);
    LCD_1IN28_Clear(WHITE);
    
    // Set backlight to 100%
    DEV_SET_PWM(100);
    
    // Create image buffer
    uint32_t imageSize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;
    uint16_t *imageBuffer = (uint16_t *)malloc(imageSize);
    if (imageBuffer == NULL) {
        printf("Failed to allocate memory\r\n");
        return -1;
    }
    
    // Initialize the image and set it to white
    Paint_NewImage((uint8_t *)imageBuffer, LCD_1IN28.WIDTH, LCD_1IN28.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(WHITE);
    Paint_SetRotate(ROTATE_0);
    
    // Calculate center point and radius
    uint16_t centerX = LCD_1IN28.WIDTH / 2;
    uint16_t centerY = LCD_1IN28.HEIGHT / 2;
    uint16_t radius = 60;  // You can adjust this value to change circle size
    
    // Draw filled black circle in the center
    Paint_DrawCircle(centerX, centerY, radius, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    
    // Display the image
    LCD_1IN28_Display(imageBuffer);
    
    // Free the image buffer
    free(imageBuffer);
    
    // Keep program running
    while (1) {
        DEV_Delay_ms(100);
    }
    
    // Clean up
    DEV_Module_Exit();
    return 0;
}