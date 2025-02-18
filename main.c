#include <stdio.h>
#include <math.h>
#include "LCD_Test.h"
#include "LCD_1in28.h"
#include "pico/stdlib.h"
#include "time_header.h"

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

void draw_clock_face(uint16_t *imageBuffer, float angle) {
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
            int index = (int)(angle / (2 * M_PI) * 64) % 64;
            color = color_functions[index](x, y);
            Paint_DrawRectangle(centerX + x * pixelSize, centerY + y * pixelSize, centerX + (x+1) * pixelSize, centerY + (y+1) * pixelSize, color, DOT_PIXEL_1X1, DRAW_FILL_FULL);
        }
    }

}

int main(void) {
    stdio_init_all();
    
    if (DEV_Module_Init() != 0) {
        printf("ERROR: Device initialization failed!\r\n");
        return -1;
    }
    
    LCD_1IN28_Init(HORIZONTAL);
    LCD_1IN28_Clear(WHITE);
    
    // Set the backlight to maximum brightness
    DEV_SET_PWM(100);

    uint32_t imageSize = LCD_1IN28_HEIGHT * LCD_1IN28_WIDTH * 2;
    uint16_t *imageBuffer = (uint16_t *)malloc(imageSize);

    float angle = 0.0f;
    const float rotation_speed = 2 * M_PI / 2.0f;
    uint32_t last_time = time_us_32();
    
    while (1) {
        uint32_t current_time = time_us_32();        
        float elapsed = (current_time - last_time) / 1000000.0f;
        angle += rotation_speed * elapsed;
        
        if (angle >= 2 * M_PI) {
            angle = 0.0f;
        }
        
        draw_clock_face(imageBuffer, angle);
        LCD_1IN28_Display(imageBuffer);
        last_time = current_time;

        sleep_ms(10);
    }

    free(imageBuffer);
    DEV_Module_Exit();
    return 0;
}