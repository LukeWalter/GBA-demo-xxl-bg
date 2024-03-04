#ifndef XXLBG_DEMO_H
#define XXLBG_DEMO_H

// Returns value when min <= value <= max, returns min when value < min, returns max when value > max
#define CLAMP(value, min, max) (((value) * ((min) <= (value) && (value) <= (max))) + ((min) * ((min) > (value))) + ((max) * ((max) < (value))))

#define WIDEXL_SB_WIDTH 2   // Width of XL wide BG in screen blocks
#define WIDEXL_SB_HEIGHT 1  // Height of XL wide BG in screen blocks

#define TALLXL_SB_WIDTH 1   // Width of XL tall BG in screen blocks
#define TALLXL_SB_HEIGHT 2  // Height of XL tall BG in screen blocks

#define LARGEXL_SB_WIDTH 2  // Width of XL large BG in screen blocks
#define LARGEXL_SB_HEIGHT 2 // Height of XL large BG in screen blocks

int hOff, vOff; // Distance from (0, 0) in map
int mapWidth, mapHeight; // Width/height of map in pixels

void initialize();
void update();
void draw();

// State machine

void goToWide();
void goToTall();
void goToLarge();

enum { WIDE_XL, TALL_XL, LARGE_XL };
int state;

#endif