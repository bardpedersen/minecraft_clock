#include "time_37.h"
#include "GUI_Paint.h"

uint16_t time_37_pixel_color(int x, int y) {
    uint16_t color;

    if (x == -5 && y == -1) {
        color = MINECRAFT_SKY_1;
    }
    else if (x == -5 && y == 0) {
        color = MINECRAFT_SKY_1;
    }
    else if (x == -4 && y == -3) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -4 && y == -2) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -4 && y == -1) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -4 && y == 0) {
        color = MINECRAFT_SKY_1;
    }
    else if (x == -4 && y == 1) {
        color = MINECRAFT_SKY_1;
    }
    else if (x == -3 && y == -4) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -3 && y == -3) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -3 && y == -2) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == -3 && y == -1) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == -3 && y == 0) {
        color = MINECRAFT_SKY_2;
    }
    else if (x == -3 && y == 1) {
        color = MINECRAFT_SKY_1;
    }
    else if (x == -2 && y == -4) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -2 && y == -3) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == -2 && y == -2) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == -2 && y == -1) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == -2 && y == 0) {
        color = MINECRAFT_SKY_2;
    }
    else if (x == -2 && y == 1) {
        color = MINECRAFT_SKY_1;
    }
    else if (x == -1 && y == -5) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -1 && y == -4) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == -1 && y == -3) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == -1 && y == -2) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == -1 && y == -1) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 0 && y == -5) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 0 && y == -4) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 0 && y == -3) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 0 && y == -2) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 0 && y == -1) {
        color = MINECRAFT_MOON_2;
    }
    else if (x == 1 && y == -4) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 1 && y == -3) {
        color = MINECRAFT_MOON_2;
    }
    else if (x == 1 && y == -2) {
        color = MINECRAFT_MOON_2;
    }
    else if (x == 1 && y == -1) {
        color = MINECRAFT_MOON_2;
    }
    else if (x == 1 && y == 0) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 1 && y == 1) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 2 && y == -4) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 2 && y == -3) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 2 && y == -2) {
        color = MINECRAFT_MOON_2;
    }
    else if (x == 2 && y == -1) {
        color = MINECRAFT_MOON_2;
    }
    else if (x == 2 && y == 0) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 2 && y == 1) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 3 && y == -3) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 3 && y == -2) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 3 && y == -1) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 3 && y == 0) {
        color = MINECRAFT_NIGHT_2;
    }
    else if (x == 3 && y == 1) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 4 && y == -1) {
        color = MINECRAFT_NIGHT_1;
    }
    else if (x == 4 && y == 0) {
        color = MINECRAFT_NIGHT_1;
    }
    else {
        color = BLACK;
    }

    return color;
}