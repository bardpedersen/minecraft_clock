#ifndef COLOR_MAP_H
#define COLOR_MAP_H

#define RGB_(r, g, b) ((((r) & 0xF8) << 8) | (((g) & 0xFC) << 3) | ((b) >> 3))

#define MINECRAFT_SKY_1   RGB_(64, 71, 174)
#define MINECRAFT_SKY_2   RGB_(81, 89, 219)
#define MINECRAFT_SUN_1   RGB_(248, 255, 0)
#define MINECRAFT_SUN_2   RGB_(198, 211, 0)
#define MINECRAFT_NIGHT_1 RGB_(30, 28, 28)
#define MINECRAFT_NIGHT_2 RGB_(24, 22, 22)
#define MINECRAFT_MOON_1  RGB_(110, 105, 138)
#define MINECRAFT_MOON_2  RGB_(88, 84, 110)

#endif