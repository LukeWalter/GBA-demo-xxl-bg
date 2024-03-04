#include "gba.h"
#include "print.h"

#include "mode0.h"
#include "bgXL.h"

#include "demo.h"

void draw() {

    int currentSBB;

    switch (state) {

        case WIDE_XL:

            REG_BG0HOFF = hOff;
            REG_BG0VOFF = vOff;

            break;

        case TALL_XL:

            REG_BG0HOFF = hOff;
            REG_BG0VOFF = vOff;

            break;

        case LARGE_XL:

            REG_BG0HOFF = hOff;
            REG_BG0VOFF = vOff;
            
            break;

    } // switch

} // draw

void goToLarge() {

    state = LARGE_XL;

    hOff = 0;
    vOff = 0;
    mapWidth = 256 * LARGEXL_SB_WIDTH;
    mapHeight = 256 * LARGEXL_SB_HEIGHT;

    REG_BG0CNT = BG_SIZE_LARGE | BG_SCREENBLOCK(0) | BG_CHARBLOCK(3);

} // goToLarge

void goToWide() {
    
    state = WIDE_XL;
    
    hOff = 0;
    vOff = 0;
    mapWidth = 256 * WIDEXL_SB_WIDTH;
    mapHeight = 256 * WIDEXL_SB_HEIGHT;

    REG_BG0CNT = BG_SIZE_WIDE | BG_SCREENBLOCK(0) | BG_CHARBLOCK(3);

} // goToWide

void goToTall() {

    state = TALL_XL;

    hOff = 0;
    vOff = 0;
    mapWidth = 256 * TALLXL_SB_WIDTH;
    mapHeight = 256 * TALLXL_SB_HEIGHT;

    REG_BG0CNT = BG_SIZE_TALL | BG_SCREENBLOCK(0) | BG_CHARBLOCK(3);

} // goToTall

void initialize() {

    mgba_open();
    REG_DISPCTL = MODE(0) | BG_ENABLE(0);

    DMANow(3, bgXLPal, BG_PALETTE, 256);
    DMANow(3, bgXLTiles, &CHARBLOCK[3], bgXLTilesLen / 2);
    DMANow(3, bgXLMap, &SCREENBLOCK[0], bgXLMapLen / 2);

    oldButtons = 0;
    buttons = REG_BUTTONS;

    hOff = 0;
    vOff = 0;

    goToWide();

} // initialize

void update() {

    if (BUTTON_HELD(BUTTON_LEFT))  hOff = CLAMP(hOff - 5, 0, mapWidth - SCREENWIDTH);
    if (BUTTON_HELD(BUTTON_RIGHT)) hOff = CLAMP(hOff + 5, 0, mapWidth - SCREENWIDTH);
    if (BUTTON_HELD(BUTTON_UP))    vOff = CLAMP(vOff - 5, 0, mapHeight - SCREENHEIGHT);
    if (BUTTON_HELD(BUTTON_DOWN))  vOff = CLAMP(vOff + 5, 0, mapHeight - SCREENHEIGHT);

    switch (state) {

        case WIDE_XL:
            if (BUTTON_PRESSED(BUTTON_LSHOULDER)) goToLarge();
            if (BUTTON_PRESSED(BUTTON_RSHOULDER)) goToTall();
            break;

        case TALL_XL:
            if (BUTTON_PRESSED(BUTTON_LSHOULDER)) goToWide();
            if (BUTTON_PRESSED(BUTTON_RSHOULDER)) goToLarge();
            break;

        case LARGE_XL:
            if (BUTTON_PRESSED(BUTTON_LSHOULDER)) goToTall();
            if (BUTTON_PRESSED(BUTTON_RSHOULDER)) goToWide();
            break;

    } // switch
    
} // update

int main() {

    initialize();

    while (1) {

        oldButtons = buttons;
        buttons = REG_BUTTONS;

        update();
        waitForVBlank();
        draw();

    } // while

    return 0;

} // main