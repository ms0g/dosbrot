#ifndef VGA_H
#define VGA_H

#include <_defs.h>
// VGA GFX Mode
#define MODE_VGA_13H 0x13
// VGA Text Mode
#define MODE_VGA_3H  0x03

#ifdef __cplusplus
extern "C" {
#endif
void _Cdecl _waitvretrace(void);
void _Cdecl _putpixel(int x, int y, char color);
void _Cdecl _initMode(int mode);

void initvga(void);
void exitvga(void);
void clroffscreen(char color);
void putpixel(int x, int y, char color);
void updateVRAM(void);
#ifdef __cplusplus
}
#endif
#endif