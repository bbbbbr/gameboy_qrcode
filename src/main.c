#include <gbdk/platform.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "qr_wrapper.h"


void main(void) {

    SHOW_BKG;
    qr_generate("https://gbdk.org");
    qr_render();

	while(1) {
	    vsync();
	}
}
