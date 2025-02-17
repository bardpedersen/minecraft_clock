#include "LCD_Test.h"
#include "DEV_Config.h"
#include "GUI_Paint.h"
#include "fonts.h"
#include <stdlib.h>
#include "pico/stdlib.h"

void setup() {
    // Initialize the display configuration
    if(DEV_Module_Init() != 0) {
        return;
    }
    
    // Initialize LCD configuration
    LCD_Init();
    LCD_Clear(BLACK);
    DEV_Delay_ms(100);
    
    // Create a new image cache
    UDOUBLE Imagesize = LCD_HEIGHT*LCD_WIDTH*2;
    UWORD *BlackImage = (UWORD *)malloc(Imagesize);
    
    // Create a new painting
    Paint_NewImage(BlackImage, LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
    Paint_Clear(BLACK);
    Paint_SetRotate(ROTATE_0);
    
    // Set font style and size
    Paint_SetScale(2);
    
    // Draw the text
    Paint_DrawString_EN(40, 100, "Hello World!", &Font20, BLACK, WHITE);
    
    // Display the image and update screen
    LCD_Display(BlackImage);
    
    // Free the image cache
    free(BlackImage);
}

void loop() {
    // Main loop can be empty for this example
    // or you can add animations/updates here
    sleep_ms(1000);
}

int main() {
    // Initialize stdio
    stdio_init_all();
    
    // Run setup
    setup();
    
    // Main program loop
    while(1) {
        loop();
    }
    
    // Clean up (this won't be reached in this example)
    DEV_Module_Exit();
    return 0;
}