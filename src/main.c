#include <gbdk/platform.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "qr_wrapper.h"

#define ARRAY_LEN(A)  sizeof(A) / sizeof(A[0])

void main(void) {

    SHOW_BKG;
    const char embed_str[] = "https://gbdk.org/";
    if ( qr_generate(embed_str, ARRAY_LEN(embed_str)) ) {
        qr_render();
    } // else .. there was an error

	while(1) {
	    vsync();
	}
}
