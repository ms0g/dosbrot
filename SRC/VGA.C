#include "VGA.H"
#include <MALLOC.H>
#include <STRING.H>

static unsigned char far* vram;
static unsigned char far* offscreen;

void initvga(void) {
    vram = (unsigned char far*)0xA0000000L;
    offscreen = (unsigned char far*)farmalloc(64000u);

    if (offscreen) {
        _fmemset(offscreen, 0, 64000u);
        
        _initMode(MODE_VGA_13H);
    }
}

void exitvga(void) {
    farfree(offscreen);
    // Return to the text mode
   _initMode(MODE_VGA_3H);
}

void clroffscreen(char color) {
    _fmemset(offscreen, color, 64000u);
}

void putpixel(int x, int y, char color) {
    offscreen[(y << 8) + (y << 6) + x] = color;
}

void updateVRAM(void) {
    _waitvretrace();

    _fmemcpy(vram, offscreen, 64000u);
}

