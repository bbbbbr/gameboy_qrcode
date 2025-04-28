#include <gbdk/platform.h>
#include <gb/drawing.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "qr/qrcodegen.h"

// See qrcodegen.h for setting the QR code version/capacity

#define SCALE 4  // pixel size multiplier for output rendering

bool qr_generate(const char * embed_str) NONBANKED {
    
    // TODO: could check length here per settings and info in qrcodegen.h
    // if (strlen(embed_str) > ...) return false;

    uint8_t save_bank = CURRENT_BANK;
    SWITCH_ROM(BANK(qrcodegen));

    qrcodegen(embed_str);

    SWITCH_ROM(save_bank);

    return true;
}


void qr_render(void) NONBANKED {

    uint8_t save_bank = CURRENT_BANK;
    SWITCH_ROM(BANK(qrcodegen));

    for (uint8_t x = 0; x < (QRSIZE+2); x++) {
        for (uint8_t y = 0; y < (QRSIZE+2); y++) {
            if (qr(x,y))                
                color(WHITE,WHITE,SOLID);
            else
                color(BLACK,BLACK,SOLID);
            
            // plot_point(x, y);
            uint8_t x1 = x * SCALE;
            uint8_t y1 = y * SCALE;
            box(x1, y1, x1 + (SCALE - 1), y1 + (SCALE - 1), M_FILL);
        }
    }

    SWITCH_ROM(save_bank);    
}