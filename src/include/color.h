#pragma once

#define RGB_(r, g, b) ((((r) & 0xF8) << 8) | (((g) & 0xFC) << 3) | ((b) >> 3))

#define MINECRAFT_SKY_1   RGB_(62, 72, 173) // side color
#define MINECRAFT_SKY_2   RGB_(81, 89, 220) // middle color
#define MINECRAFT_SUN_1   RGB_(248, 255, 0) // middle color
#define MINECRAFT_SUN_2   RGB_(197, 211, 0) // side color
#define MINECRAFT_NIGHT_1 RGB_(21, 21, 21) // side color
#define MINECRAFT_NIGHT_2 RGB_(29, 29, 29) // middle color
#define MINECRAFT_MOON_1  RGB_(88, 84, 111) // side color
#define MINECRAFT_MOON_2  RGB_(111, 105, 138) // middle color
