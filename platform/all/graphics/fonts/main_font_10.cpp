/*******************************************************************************
 * Size: 10 px
 * Bpp: 4
 * Opts: --no-compress --no-prefilter --bpp 4 --size 10 --font Roboto-Medium.ttf -r 0x20-0x7F,0xB0,0x2022 --font materialdesignicons-webfont.ttf -r 0xF091F,0xF0922,0xF0925,0xF0928,0xF092E,0xF0201,0xF0202 --format lvgl -o main_font_10.cpp --force-fast-kern-format
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef MAIN_FONT_10
#define MAIN_FONT_10 1
#endif

#if MAIN_FONT_10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x4f, 0x3, 0xf0, 0x3e, 0x3, 0xe0, 0x2e, 0x1,
    0x80, 0x4, 0x2, 0xd0,

    /* U+0022 "\"" */
    0x85, 0xc8, 0x4b, 0x63, 0x90,

    /* U+0023 "#" */
    0x0, 0x84, 0xa3, 0x0, 0xb1, 0xc0, 0x2e, 0xfe,
    0xfc, 0x0, 0xc2, 0xa0, 0x2, 0xa4, 0x80, 0x7e,
    0xee, 0xe7, 0x8, 0x59, 0x30, 0xb, 0x2c, 0x0,

    /* U+0024 "$" */
    0x0, 0x11, 0x0, 0x0, 0x66, 0x0, 0x8, 0xff,
    0x60, 0x2f, 0x25, 0xf0, 0x2f, 0x10, 0x70, 0xb,
    0xe7, 0x0, 0x0, 0x5d, 0xb0, 0x46, 0x1, 0xf2,
    0x5e, 0x35, 0xf1, 0x8, 0xee, 0x50, 0x0, 0x84,
    0x0,

    /* U+0025 "%" */
    0x2c, 0xc1, 0x0, 0x7, 0x66, 0x74, 0x80, 0x76,
    0x77, 0xc1, 0x1, 0xbb, 0x76, 0x0, 0x0, 0x1c,
    0x7d, 0x50, 0x9, 0x4d, 0x1d, 0x2, 0xa0, 0xc0,
    0xd0, 0x1, 0x9, 0xd7,

    /* U+0026 "&" */
    0x5, 0xed, 0x20, 0x0, 0xe5, 0x99, 0x0, 0xe,
    0x5a, 0x70, 0x0, 0x7f, 0xa0, 0x0, 0x1e, 0xda,
    0x2a, 0x8, 0xb1, 0xdc, 0xb0, 0x6d, 0x6, 0xf6,
    0x0, 0xaf, 0xea, 0xe1,

    /* U+0027 "'" */
    0x94, 0x93, 0x72,

    /* U+0028 "(" */
    0x0, 0x62, 0x4, 0xc0, 0xc, 0x40, 0x1f, 0x0,
    0x4c, 0x0, 0x5b, 0x0, 0x5b, 0x0, 0x3d, 0x0,
    0xf, 0x10, 0x9, 0x60, 0x1, 0xd1, 0x0, 0x21,

    /* U+0029 ")" */
    0x71, 0x4, 0xb0, 0xc, 0x40, 0x79, 0x4, 0xc0,
    0x3e, 0x4, 0xd0, 0x5b, 0x9, 0x70, 0xe1, 0x87,
    0x3, 0x0,

    /* U+002A "*" */
    0x2, 0xa0, 0x7, 0x6b, 0x71, 0x4c, 0xf7, 0x11,
    0xda, 0x50, 0x14, 0x15, 0x0,

    /* U+002B "+" */
    0x0, 0x94, 0x0, 0x0, 0xc5, 0x0, 0xaf, 0xff,
    0xf3, 0x23, 0xd7, 0x30, 0x0, 0xc5, 0x0, 0x0,
    0xc5, 0x0,

    /* U+002C "," */
    0x5b, 0x79, 0xa3, 0x0,

    /* U+002D "-" */
    0x9f, 0xd1, 0x21,

    /* U+002E "." */
    0x5, 0x3, 0xd0,

    /* U+002F "/" */
    0x0, 0x59, 0x0, 0xa3, 0x0, 0xd0, 0x5, 0x90,
    0xa, 0x40, 0xd, 0x0, 0x59, 0x0, 0xa4, 0x0,
    0x70, 0x0,

    /* U+0030 "0" */
    0x8, 0xed, 0x30, 0x2f, 0x37, 0xd0, 0x6b, 0x1,
    0xf1, 0x7b, 0x0, 0xf2, 0x7b, 0x0, 0xf2, 0x6b,
    0x1, 0xf1, 0x2f, 0x37, 0xd0, 0x7, 0xed, 0x40,

    /* U+0031 "1" */
    0x2, 0x8a, 0x2f, 0xdc, 0x0, 0x7c, 0x0, 0x7c,
    0x0, 0x7c, 0x0, 0x7c, 0x0, 0x7c, 0x0, 0x7c,

    /* U+0032 "2" */
    0x9, 0xfd, 0x40, 0x6d, 0x27, 0xe0, 0x45, 0x3,
    0xf0, 0x0, 0x9, 0xa0, 0x0, 0x5e, 0x10, 0x3,
    0xe3, 0x0, 0x1e, 0x71, 0x10, 0x7f, 0xff, 0xf5,

    /* U+0033 "3" */
    0xa, 0xfd, 0x40, 0x7d, 0x27, 0xe0, 0x0, 0x5,
    0xe0, 0x1, 0xef, 0x40, 0x0, 0x18, 0xd0, 0x33,
    0x1, 0xf1, 0x6d, 0x27, 0xe0, 0xa, 0xfd, 0x40,

    /* U+0034 "4" */
    0x0, 0xe, 0x80, 0x0, 0x8f, 0x80, 0x2, 0xeb,
    0x80, 0xb, 0x6a, 0x80, 0x4c, 0xa, 0x80, 0xbf,
    0xff, 0xf6, 0x12, 0x2a, 0x90, 0x0, 0xa, 0x80,

    /* U+0035 "5" */
    0xd, 0xff, 0xf0, 0xe, 0x42, 0x20, 0xf, 0x10,
    0x0, 0x1f, 0xdd, 0x60, 0x6, 0x36, 0xf1, 0x1,
    0x0, 0xf3, 0x3f, 0x34, 0xf1, 0x7, 0xee, 0x60,

    /* U+0036 "6" */
    0x0, 0x9e, 0x30, 0xa, 0xc3, 0x0, 0x2f, 0x10,
    0x0, 0x5e, 0xbd, 0x60, 0x6f, 0x45, 0xf1, 0x5c,
    0x0, 0xf3, 0x1f, 0x34, 0xf1, 0x5, 0xee, 0x50,

    /* U+0037 "7" */
    0xaf, 0xff, 0xf4, 0x1, 0x13, 0xe0, 0x0, 0x9,
    0x90, 0x0, 0xf, 0x20, 0x0, 0x6c, 0x0, 0x0,
    0xc6, 0x0, 0x3, 0xf0, 0x0, 0xa, 0x90, 0x0,

    /* U+0038 "8" */
    0x9, 0xfe, 0x50, 0x3f, 0x26, 0xe0, 0x3f, 0x15,
    0xe0, 0x9, 0xff, 0x40, 0x3e, 0x37, 0xd0, 0x7b,
    0x0, 0xf2, 0x4e, 0x26, 0xf0, 0x9, 0xfe, 0x50,

    /* U+0039 "9" */
    0x9, 0xfc, 0x20, 0x5e, 0x28, 0xb0, 0x8a, 0x2,
    0xf0, 0x6d, 0x5, 0xf1, 0xc, 0xfc, 0xf0, 0x0,
    0x5, 0xd0, 0x0, 0x4d, 0x70, 0x8, 0xe7, 0x0,

    /* U+003A ":" */
    0x3d, 0x1, 0x50, 0x0, 0x0, 0x0, 0x4, 0x3,
    0xd0,

    /* U+003B ";" */
    0x5c, 0x14, 0x0, 0x0, 0x0, 0x4c, 0x5a, 0x93,
    0x0,

    /* U+003C "<" */
    0x0, 0x18, 0x51, 0x9f, 0xb2, 0xae, 0x30, 0x2,
    0xaf, 0x91, 0x0, 0x2a, 0x60, 0x0, 0x0,

    /* U+003D "=" */
    0x4f, 0xff, 0xe0, 0x22, 0x22, 0x4f, 0xff, 0xe0,
    0x22, 0x22,

    /* U+003E ">" */
    0x59, 0x10, 0x2, 0xaf, 0x92, 0x0, 0x2d, 0xd1,
    0x9f, 0xb3, 0x5a, 0x30, 0x0, 0x0, 0x0,

    /* U+003F "?" */
    0x1c, 0xfb, 0x9, 0xb2, 0xd6, 0x0, 0xc, 0x60,
    0x6, 0xe0, 0x1, 0xf2, 0x0, 0x28, 0x0, 0x0,
    0x40, 0x0, 0x4c, 0x0,

    /* U+0040 "@" */
    0x0, 0x4b, 0xcc, 0x80, 0x0, 0x4c, 0x10, 0x6,
    0x90, 0xd, 0x13, 0xdc, 0x1b, 0x23, 0x90, 0xd2,
    0xa3, 0x66, 0x66, 0x2b, 0xb, 0x24, 0x77, 0x55,
    0x90, 0xd0, 0x56, 0x67, 0x5a, 0x1f, 0x9, 0x32,
    0xb0, 0xca, 0x8c, 0x80, 0xa, 0x70, 0x0, 0x0,
    0x0, 0x8, 0xdd, 0xc1, 0x0,

    /* U+0041 "A" */
    0x0, 0x6f, 0x10, 0x0, 0xb, 0xf6, 0x0, 0x1,
    0xf8, 0xb0, 0x0, 0x6c, 0x1f, 0x10, 0xb, 0x70,
    0xc6, 0x1, 0xff, 0xff, 0xb0, 0x6d, 0x22, 0x4f,
    0x1b, 0x80, 0x0, 0xd6,

    /* U+0042 "B" */
    0x4f, 0xff, 0xb1, 0x4f, 0x12, 0xd8, 0x4f, 0x0,
    0xc8, 0x4f, 0xef, 0xe0, 0x4f, 0x12, 0xc9, 0x4f,
    0x0, 0x7c, 0x4f, 0x12, 0xc9, 0x4f, 0xff, 0xb1,

    /* U+0043 "C" */
    0x3, 0xdf, 0xc2, 0x0, 0xe8, 0x29, 0xc0, 0x5e,
    0x0, 0x1a, 0x7, 0xc0, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0x5, 0xe0, 0x1, 0xa0, 0x1e, 0x72, 0x9d,
    0x0, 0x3d, 0xfc, 0x20,

    /* U+0044 "D" */
    0x4f, 0xfe, 0x70, 0x4, 0xf1, 0x4e, 0x60, 0x4f,
    0x0, 0x6d, 0x4, 0xf0, 0x4, 0xf0, 0x4f, 0x0,
    0x4f, 0x4, 0xf0, 0x6, 0xd0, 0x4f, 0x14, 0xe6,
    0x4, 0xff, 0xe7, 0x0,

    /* U+0045 "E" */
    0x4f, 0xff, 0xf5, 0x4f, 0x11, 0x10, 0x4f, 0x0,
    0x0, 0x4f, 0xff, 0xd0, 0x4f, 0x22, 0x10, 0x4f,
    0x0, 0x0, 0x4f, 0x11, 0x10, 0x4f, 0xff, 0xf6,

    /* U+0046 "F" */
    0x4f, 0xff, 0xf3, 0x4f, 0x11, 0x10, 0x4f, 0x0,
    0x0, 0x4f, 0xff, 0xc0, 0x4f, 0x22, 0x10, 0x4f,
    0x0, 0x0, 0x4f, 0x0, 0x0, 0x4f, 0x0, 0x0,

    /* U+0047 "G" */
    0x3, 0xcf, 0xc2, 0x0, 0xe8, 0x29, 0xd0, 0x5e,
    0x0, 0x19, 0x7, 0xc0, 0x0, 0x0, 0x7c, 0x7,
    0xee, 0x25, 0xe0, 0x2, 0xf2, 0xe, 0x92, 0x5f,
    0x20, 0x3c, 0xfe, 0x70,

    /* U+0048 "H" */
    0x4f, 0x0, 0xd, 0x64, 0xf0, 0x0, 0xd6, 0x4f,
    0x0, 0xd, 0x64, 0xff, 0xff, 0xf6, 0x4f, 0x22,
    0x2e, 0x64, 0xf0, 0x0, 0xd6, 0x4f, 0x0, 0xd,
    0x64, 0xf0, 0x0, 0xd6,

    /* U+0049 "I" */
    0x3f, 0x3, 0xf0, 0x3f, 0x3, 0xf0, 0x3f, 0x3,
    0xf0, 0x3f, 0x3, 0xf0,

    /* U+004A "J" */
    0x0, 0x5, 0xd0, 0x0, 0x5d, 0x0, 0x5, 0xd0,
    0x0, 0x5d, 0x0, 0x5, 0xd4, 0x20, 0x5d, 0x9b,
    0x2b, 0xa1, 0xcf, 0xc2,

    /* U+004B "K" */
    0x4f, 0x0, 0xad, 0x4, 0xf0, 0x6f, 0x20, 0x4f,
    0x2f, 0x50, 0x4, 0xfd, 0xc0, 0x0, 0x4f, 0xdf,
    0x30, 0x4, 0xf1, 0xac, 0x0, 0x4f, 0x1, 0xe6,
    0x4, 0xf0, 0x6, 0xf1,

    /* U+004C "L" */
    0x4f, 0x0, 0x0, 0x4f, 0x0, 0x0, 0x4f, 0x0,
    0x0, 0x4f, 0x0, 0x0, 0x4f, 0x0, 0x0, 0x4f,
    0x0, 0x0, 0x4f, 0x11, 0x10, 0x4f, 0xff, 0xf3,

    /* U+004D "M" */
    0x4f, 0x70, 0x0, 0xbf, 0x4, 0xfd, 0x0, 0x1f,
    0xf0, 0x4d, 0xe2, 0x6, 0xcf, 0x4, 0xe9, 0x70,
    0xc7, 0xf0, 0x4e, 0x4d, 0x1f, 0x3f, 0x4, 0xf0,
    0xe9, 0xa3, 0xf0, 0x4f, 0x9, 0xf5, 0x3f, 0x4,
    0xf0, 0x4f, 0x3, 0xf0,

    /* U+004E "N" */
    0x4f, 0x30, 0xd, 0x54, 0xfc, 0x0, 0xd5, 0x4f,
    0xe5, 0xd, 0x54, 0xf6, 0xe0, 0xd5, 0x4f, 0xd,
    0x7d, 0x54, 0xf0, 0x4f, 0xe5, 0x4f, 0x0, 0xbf,
    0x54, 0xf0, 0x2, 0xf5,

    /* U+004F "O" */
    0x3, 0xcf, 0xc2, 0x0, 0xe9, 0x3a, 0xd0, 0x5e,
    0x0, 0x1f, 0x37, 0xc0, 0x0, 0xe5, 0x7c, 0x0,
    0xd, 0x55, 0xe0, 0x0, 0xf3, 0xe, 0x93, 0xad,
    0x0, 0x3c, 0xfc, 0x20,

    /* U+0050 "P" */
    0x4f, 0xff, 0xc2, 0x4, 0xf2, 0x2a, 0xc0, 0x4f,
    0x0, 0x3f, 0x4, 0xf0, 0x8, 0xd0, 0x4f, 0xff,
    0xe4, 0x4, 0xf2, 0x10, 0x0, 0x4f, 0x0, 0x0,
    0x4, 0xf0, 0x0, 0x0,

    /* U+0051 "Q" */
    0x3, 0xcf, 0xb2, 0x1, 0xe8, 0x3a, 0xd0, 0x5e,
    0x0, 0x1f, 0x38, 0xb0, 0x0, 0xe5, 0x8b, 0x0,
    0xe, 0x55, 0xe0, 0x1, 0xf3, 0x1e, 0x83, 0xad,
    0x0, 0x3c, 0xff, 0x70, 0x0, 0x0, 0x5f, 0x20,
    0x0, 0x0, 0x10,

    /* U+0052 "R" */
    0x4f, 0xff, 0xb1, 0x4, 0xf2, 0x2c, 0x90, 0x4f,
    0x0, 0x7c, 0x4, 0xf0, 0xb, 0x90, 0x4f, 0xff,
    0xd1, 0x4, 0xf2, 0x8d, 0x0, 0x4f, 0x0, 0xe5,
    0x4, 0xf0, 0x7, 0xd0,

    /* U+0053 "S" */
    0x7, 0xef, 0x90, 0x4f, 0x43, 0xd7, 0x5e, 0x0,
    0x34, 0xc, 0xe8, 0x10, 0x0, 0x5c, 0xf3, 0x44,
    0x0, 0xa9, 0x6e, 0x32, 0xc8, 0x8, 0xef, 0xa1,

    /* U+0054 "T" */
    0xcf, 0xff, 0xfd, 0x11, 0x9a, 0x11, 0x0, 0x9a,
    0x0, 0x0, 0x9a, 0x0, 0x0, 0x9a, 0x0, 0x0,
    0x9a, 0x0, 0x0, 0x9a, 0x0, 0x0, 0x9a, 0x0,

    /* U+0055 "U" */
    0x6d, 0x0, 0x5e, 0x6d, 0x0, 0x5e, 0x6d, 0x0,
    0x5e, 0x6d, 0x0, 0x5e, 0x6d, 0x0, 0x5e, 0x5e,
    0x0, 0x5e, 0x2f, 0x52, 0xba, 0x5, 0xdf, 0xb1,

    /* U+0056 "V" */
    0xb9, 0x0, 0x1f, 0x36, 0xd0, 0x6, 0xe0, 0x1f,
    0x20, 0xb9, 0x0, 0xc7, 0xf, 0x40, 0x7, 0xb4,
    0xe0, 0x0, 0x2f, 0x9a, 0x0, 0x0, 0xdf, 0x40,
    0x0, 0x8, 0xf0, 0x0,

    /* U+0057 "W" */
    0xa8, 0x3, 0xf1, 0xb, 0x87, 0xb0, 0x6f, 0x40,
    0xe5, 0x4e, 0xa, 0xd8, 0x1f, 0x10, 0xf1, 0xd5,
    0xb4, 0xe0, 0xd, 0x6e, 0xe, 0x7b, 0x0, 0xac,
    0xa0, 0xcc, 0x70, 0x6, 0xf6, 0x8, 0xf4, 0x0,
    0x3f, 0x20, 0x5f, 0x10,

    /* U+0058 "X" */
    0x7e, 0x0, 0x9c, 0x0, 0xe7, 0x2f, 0x40, 0x6,
    0xea, 0xb0, 0x0, 0xd, 0xf3, 0x0, 0x0, 0xdf,
    0x30, 0x0, 0x6e, 0xac, 0x0, 0xe, 0x61, 0xf5,
    0x8, 0xe0, 0x8, 0xd0,

    /* U+0059 "Y" */
    0xb9, 0x0, 0x8c, 0x4, 0xf1, 0xe, 0x50, 0xc,
    0x76, 0xd0, 0x0, 0x5e, 0xd6, 0x0, 0x0, 0xde,
    0x0, 0x0, 0x9, 0xa0, 0x0, 0x0, 0x9a, 0x0,
    0x0, 0x9, 0xa0, 0x0,

    /* U+005A "Z" */
    0x9f, 0xff, 0xf8, 0x11, 0x14, 0xf3, 0x0, 0xc,
    0x90, 0x0, 0x6e, 0x0, 0x1, 0xe5, 0x0, 0xa,
    0xb0, 0x0, 0x3f, 0x41, 0x11, 0x9f, 0xff, 0xfb,

    /* U+005B "[" */
    0x5e, 0x95, 0xd1, 0x5d, 0x5, 0xd0, 0x5d, 0x5,
    0xd0, 0x5d, 0x5, 0xd0, 0x5d, 0x5, 0xd0, 0x5f,
    0x90, 0x11,

    /* U+005C "\\" */
    0xb7, 0x0, 0x6, 0xc0, 0x0, 0x1f, 0x20, 0x0,
    0xa7, 0x0, 0x5, 0xd0, 0x0, 0xf, 0x20, 0x0,
    0xa8, 0x0, 0x4, 0xe0, 0x0, 0x7, 0x10,

    /* U+005D "]" */
    0xde, 0x3, 0xf1, 0x2f, 0x12, 0xf1, 0x2f, 0x12,
    0xf1, 0x2f, 0x12, 0xf1, 0x2f, 0x12, 0xf1, 0xdf,
    0x11, 0x10,

    /* U+005E "^" */
    0x7, 0xb0, 0x0, 0xde, 0x10, 0x3c, 0x87, 0x8,
    0x72, 0xd0,

    /* U+005F "_" */
    0xef, 0xff, 0x71, 0x11, 0x10,

    /* U+0060 "`" */
    0x46, 0x0, 0xd3,

    /* U+0061 "a" */
    0xa, 0xfd, 0x23, 0x91, 0x9a, 0x9, 0xde, 0xc6,
    0xc0, 0x6c, 0x7c, 0x2b, 0xc1, 0xce, 0xbd,

    /* U+0062 "b" */
    0x6c, 0x0, 0x0, 0x6c, 0x0, 0x0, 0x6e, 0xce,
    0x50, 0x6e, 0x36, 0xf0, 0x6c, 0x0, 0xf3, 0x6c,
    0x0, 0xf3, 0x6f, 0x36, 0xf0, 0x6d, 0xce, 0x50,

    /* U+0063 "c" */
    0x8, 0xed, 0x35, 0xe2, 0x7c, 0x89, 0x0, 0x28,
    0x90, 0x0, 0x5e, 0x27, 0xd0, 0x9e, 0xd2,

    /* U+0064 "d" */
    0x0, 0x2, 0xf0, 0x0, 0x2, 0xf0, 0xa, 0xfb,
    0xf0, 0x5e, 0x37, 0xf0, 0x8a, 0x2, 0xf0, 0x89,
    0x2, 0xf0, 0x5d, 0x16, 0xf0, 0xa, 0xfb, 0xf0,

    /* U+0065 "e" */
    0x8, 0xfd, 0x40, 0x4d, 0x27, 0xd0, 0x8f, 0xff,
    0xf0, 0x8b, 0x0, 0x0, 0x4f, 0x43, 0x90, 0x7,
    0xee, 0x50,

    /* U+0066 "f" */
    0x7, 0xf8, 0xf, 0x60, 0xcf, 0xf4, 0xf, 0x30,
    0xf, 0x30, 0xf, 0x30, 0xf, 0x30, 0xf, 0x30,

    /* U+0067 "g" */
    0x9, 0xfa, 0xf1, 0x5e, 0x36, 0xf1, 0x8a, 0x2,
    0xf1, 0x8a, 0x2, 0xf1, 0x5e, 0x36, 0xf1, 0x9,
    0xfb, 0xf0, 0x6, 0x17, 0xd0, 0xa, 0xfd, 0x30,

    /* U+0068 "h" */
    0x6c, 0x0, 0x6, 0xc0, 0x0, 0x6d, 0xcf, 0x66,
    0xe3, 0x7e, 0x6c, 0x3, 0xf6, 0xc0, 0x3f, 0x6c,
    0x3, 0xf6, 0xc0, 0x3f,

    /* U+0069 "i" */
    0x4c, 0x14, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e,

    /* U+006A "j" */
    0x4, 0xb0, 0x13, 0x5, 0xd0, 0x5d, 0x5, 0xd0,
    0x5d, 0x5, 0xd0, 0x5d, 0x8, 0xc5, 0xf6,

    /* U+006B "k" */
    0x6c, 0x0, 0x0, 0x6c, 0x0, 0x0, 0x6c, 0xc,
    0xa0, 0x6c, 0x8d, 0x0, 0x6f, 0xf4, 0x0, 0x6f,
    0xcb, 0x0, 0x6c, 0x1e, 0x50, 0x6c, 0x6, 0xe0,

    /* U+006C "l" */
    0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e, 0x5e,

    /* U+006D "m" */
    0x6d, 0xce, 0x7b, 0xf8, 0x6, 0xe2, 0x7f, 0x45,
    0xf0, 0x6c, 0x4, 0xf0, 0x1f, 0x16, 0xc0, 0x4f,
    0x1, 0xf1, 0x6c, 0x4, 0xf0, 0x1f, 0x16, 0xc0,
    0x4f, 0x1, 0xf1,

    /* U+006E "n" */
    0x6d, 0xcf, 0x66, 0xe3, 0x7e, 0x6c, 0x3, 0xf6,
    0xc0, 0x3f, 0x6c, 0x3, 0xf6, 0xc0, 0x3f,

    /* U+006F "o" */
    0x8, 0xfd, 0x40, 0x5e, 0x26, 0xe0, 0x9a, 0x0,
    0xf3, 0x8a, 0x0, 0xf4, 0x4e, 0x26, 0xf0, 0x8,
    0xee, 0x40,

    /* U+0070 "p" */
    0x6d, 0xde, 0x50, 0x6e, 0x15, 0xf0, 0x6c, 0x0,
    0xf2, 0x6c, 0x0, 0xf2, 0x6e, 0x26, 0xf0, 0x6e,
    0xde, 0x50, 0x6c, 0x0, 0x0, 0x6c, 0x0, 0x0,

    /* U+0071 "q" */
    0xa, 0xfa, 0xf0, 0x5e, 0x26, 0xf0, 0x8a, 0x2,
    0xf0, 0x8a, 0x2, 0xf0, 0x5e, 0x27, 0xf0, 0xa,
    0xfb, 0xf0, 0x0, 0x2, 0xf0, 0x0, 0x2, 0xf0,

    /* U+0072 "r" */
    0x0, 0x0, 0x6d, 0xd6, 0x6f, 0x41, 0x6c, 0x0,
    0x6c, 0x0, 0x6c, 0x0, 0x6c, 0x0,

    /* U+0073 "s" */
    0xb, 0xfc, 0x26, 0xd1, 0x98, 0x2e, 0x94, 0x0,
    0x17, 0xe7, 0x8b, 0x19, 0xa1, 0xbf, 0xd2,

    /* U+0074 "t" */
    0x8, 0x0, 0x1f, 0x10, 0xef, 0xf0, 0x1f, 0x10,
    0x1f, 0x10, 0x1f, 0x10, 0x1f, 0x40, 0xb, 0xf0,

    /* U+0075 "u" */
    0x6c, 0x3, 0xf6, 0xc0, 0x3f, 0x6c, 0x3, 0xf6,
    0xc0, 0x3f, 0x5e, 0x28, 0xf0, 0xcf, 0xbf,

    /* U+0076 "v" */
    0xb7, 0x8, 0xa6, 0xb0, 0xc5, 0x2f, 0x1f, 0x10,
    0xd9, 0xb0, 0x8, 0xf7, 0x0, 0x3f, 0x20,

    /* U+0077 "w" */
    0xb6, 0xe, 0x40, 0xf2, 0x7a, 0x2f, 0x83, 0xe0,
    0x3d, 0x6a, 0xd6, 0xa0, 0xf, 0xb4, 0xdb, 0x60,
    0xc, 0xf0, 0x9f, 0x20, 0x8, 0xb0, 0x4e, 0x0,

    /* U+0078 "x" */
    0x8c, 0xb, 0x80, 0xe8, 0xe1, 0x6, 0xf7, 0x0,
    0x7f, 0x80, 0x1f, 0x7f, 0x19, 0xb0, 0xa9,

    /* U+0079 "y" */
    0xc7, 0x9, 0xa7, 0xc0, 0xd5, 0x1f, 0x3f, 0x0,
    0xcb, 0xa0, 0x7, 0xf5, 0x0, 0x2f, 0x0, 0x18,
    0xb0, 0x7, 0xe3, 0x0,

    /* U+007A "z" */
    0x8f, 0xff, 0x90, 0x14, 0xf2, 0x0, 0xd7, 0x0,
    0x8c, 0x0, 0x3f, 0x31, 0x9, 0xff, 0xfb,

    /* U+007B "{" */
    0x0, 0x91, 0x8, 0x90, 0xc, 0x50, 0xc, 0x50,
    0x1e, 0x20, 0xbb, 0x0, 0x1e, 0x20, 0xc, 0x50,
    0xc, 0x50, 0x8, 0x90, 0x0, 0x91,

    /* U+007C "|" */
    0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a,
    0x2a, 0x14,

    /* U+007D "}" */
    0x82, 0x0, 0x4d, 0x0, 0xf, 0x10, 0xf, 0x20,
    0xd, 0x50, 0x5, 0xf1, 0xd, 0x50, 0xf, 0x20,
    0xf, 0x10, 0x4d, 0x0, 0x82, 0x0,

    /* U+007E "~" */
    0xb, 0xe6, 0xe, 0x5, 0xb2, 0xcf, 0x90, 0x0,
    0x0, 0x10, 0x0,

    /* U+00B0 "°" */
    0x1b, 0x90, 0x56, 0x92, 0x1b, 0xa0,

    /* U+2022 "•" */
    0x7, 0x34, 0xfc, 0x2e, 0x90,

    /* U+F0201 "󰈁" */
    0x15, 0x41, 0xc8, 0x8b, 0xc9, 0x9b, 0x8a, 0xa7,
    0xf, 0xd0, 0xf, 0xe0, 0xf, 0xe0, 0xf, 0xe0,
    0x3, 0x20,

    /* U+F0202 "󰈂" */
    0x0, 0x0, 0x32, 0x0, 0x1, 0xa0, 0xc8, 0x8b,
    0x0, 0x6, 0xb4, 0x67, 0xb0, 0x0, 0x6, 0xb4,
    0xea, 0x0, 0x0, 0x6, 0xc0, 0x0, 0x0, 0x0,
    0xf, 0xc1, 0x0, 0x0, 0x0, 0xff, 0xb1, 0x0,
    0x0, 0xf, 0xe3, 0xc1, 0x0, 0x0, 0x87, 0x3,
    0x10,

    /* U+F091F "󰤟" */
    0x0, 0x48, 0xaa, 0x84, 0x0, 0x4d, 0x94, 0x22,
    0x49, 0xd4, 0x6b, 0x0, 0x0, 0x0, 0xa6, 0x9,
    0x70, 0x0, 0x7, 0x90, 0x0, 0xc6, 0x87, 0x6c,
    0x0, 0x0, 0x1e, 0xff, 0xe1, 0x0, 0x0, 0x3,
    0xff, 0x30, 0x0, 0x0, 0x0, 0x66, 0x0, 0x0,

    /* U+F0922 "󰤢" */
    0x0, 0x48, 0xaa, 0x84, 0x0, 0x4d, 0x94, 0x22,
    0x49, 0xd4, 0x6b, 0x0, 0x0, 0x0, 0xa6, 0x9,
    0x88, 0xbb, 0x88, 0x90, 0x0, 0xcf, 0xff, 0xfc,
    0x0, 0x0, 0x1e, 0xff, 0xe1, 0x0, 0x0, 0x3,
    0xff, 0x30, 0x0, 0x0, 0x0, 0x66, 0x0, 0x0,

    /* U+F0925 "󰤥" */
    0x0, 0x48, 0xaa, 0x84, 0x0, 0x4d, 0x94, 0x22,
    0x49, 0xd4, 0x6b, 0x6, 0x88, 0x60, 0xa6, 0x9,
    0xff, 0xff, 0xff, 0x90, 0x0, 0xcf, 0xff, 0xfc,
    0x0, 0x0, 0x1e, 0xff, 0xe1, 0x0, 0x0, 0x3,
    0xff, 0x30, 0x0, 0x0, 0x0, 0x66, 0x0, 0x0,

    /* U+F0928 "󰤨" */
    0x0, 0x15, 0x77, 0x51, 0x0, 0x1a, 0xff, 0xff,
    0xff, 0xa1, 0x8f, 0xff, 0xff, 0xff, 0xf8, 0xc,
    0xff, 0xff, 0xff, 0xc0, 0x1, 0xef, 0xff, 0xfe,
    0x10, 0x0, 0x3f, 0xff, 0xf3, 0x0, 0x0, 0x6,
    0xff, 0x60, 0x0, 0x0, 0x0, 0x99, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F092E "󰤮" */
    0x2, 0x0, 0x0, 0x0, 0x0, 0xb, 0x44, 0xaa,
    0x84, 0x0, 0x4c, 0xc4, 0x22, 0x49, 0xd4, 0x6b,
    0xb, 0x40, 0x0, 0xa6, 0x9, 0x70, 0xb4, 0x7,
    0x90, 0x0, 0xc4, 0xb, 0x47, 0x0, 0x0, 0x1d,
    0x23, 0xf3, 0x0, 0x0, 0x3, 0xcc, 0x4b, 0x30,
    0x0, 0x0, 0x66, 0x0, 0x10
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 40, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 43, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 52, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 17, .adv_w = 98, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 91, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 74, .adv_w = 118, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 102, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 27, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 133, .adv_w = 56, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 157, .adv_w = 56, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 175, .adv_w = 71, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 188, .adv_w = 89, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 206, .adv_w = 35, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 210, .adv_w = 53, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 213, .adv_w = 45, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 63, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 234, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 91, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 346, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 42, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 38, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 484, .adv_w = 81, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 90, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 509, .adv_w = 83, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 78, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 143, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 589, .adv_w = 106, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 101, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 104, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 105, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 697, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 721, .adv_w = 88, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 109, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 773, .adv_w = 114, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 801, .adv_w = 45, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 89, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 101, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 861, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 885, .adv_w = 140, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 114, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 949, .adv_w = 110, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 102, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1005, .adv_w = 110, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1040, .adv_w = 100, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1068, .adv_w = 97, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1092, .adv_w = 97, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1116, .adv_w = 104, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1140, .adv_w = 104, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1168, .adv_w = 141, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1204, .adv_w = 101, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1232, .adv_w = 98, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1260, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1284, .adv_w = 44, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1302, .adv_w = 67, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1325, .adv_w = 44, .box_w = 3, .box_h = 12, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1343, .adv_w = 68, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1353, .adv_w = 72, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1358, .adv_w = 52, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 1361, .adv_w = 87, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1376, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1400, .adv_w = 84, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1415, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1439, .adv_w = 86, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1457, .adv_w = 57, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1473, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1497, .adv_w = 89, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1517, .adv_w = 41, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1525, .adv_w = 40, .box_w = 3, .box_h = 10, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 1540, .adv_w = 84, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1564, .adv_w = 41, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1572, .adv_w = 139, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1599, .adv_w = 89, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1614, .adv_w = 91, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1632, .adv_w = 90, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1656, .adv_w = 91, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1680, .adv_w = 56, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1694, .adv_w = 83, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1709, .adv_w = 53, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1725, .adv_w = 89, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1740, .adv_w = 79, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1755, .adv_w = 119, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1779, .adv_w = 80, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1794, .adv_w = 78, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1814, .adv_w = 80, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1829, .adv_w = 54, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1851, .adv_w = 40, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1861, .adv_w = 54, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1883, .adv_w = 106, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1894, .adv_w = 61, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1900, .adv_w = 56, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1905, .adv_w = 160, .box_w = 4, .box_h = 9, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 1923, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1964, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2004, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2044, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2084, .adv_w = 160, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2129, .adv_w = 160, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x1f72
};

static const uint16_t unicode_list_2[] = {
    0x0, 0x1, 0x71e, 0x721, 0x724, 0x727, 0x72d
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 8051, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 2, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 983553, .range_length = 1838, .glyph_id_start = 98,
        .unicode_list = unicode_list_2, .glyph_id_ofs_list = NULL, .list_length = 7, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 1, 0, 2, 0, 0, 0, 0,
    2, 3, 0, 0, 0, 4, 0, 4,
    5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 6, 7, 8, 9, 10, 11,
    0, 12, 12, 13, 14, 15, 12, 12,
    9, 16, 17, 18, 0, 19, 13, 20,
    21, 22, 23, 24, 25, 0, 0, 0,
    0, 0, 26, 27, 28, 0, 29, 30,
    0, 31, 0, 0, 32, 0, 31, 31,
    33, 27, 0, 34, 0, 35, 0, 36,
    37, 38, 36, 39, 40, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 0, 2, 0, 0, 0, 3,
    2, 0, 4, 5, 0, 6, 7, 6,
    8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    9, 0, 10, 0, 11, 0, 0, 0,
    11, 0, 0, 12, 0, 0, 0, 0,
    11, 0, 11, 0, 13, 14, 15, 16,
    17, 18, 19, 20, 0, 0, 21, 0,
    0, 0, 22, 0, 23, 23, 23, 24,
    23, 0, 0, 0, 0, 0, 25, 25,
    26, 25, 23, 27, 28, 29, 30, 31,
    32, 33, 31, 34, 0, 0, 35, 0,
    0, 36, 0, 0, 0, 0, 0, 0,
    0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, -9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, -5, 0, -2, -7, 0, -7,
    0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 2,
    3, 0, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -22, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -19,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -9, 0, 0,
    0, 0, 0, 0, -6, 0, -2, 0,
    0, -9, -1, -6, -3, 0, -12, 0,
    0, 0, 0, 0, -4, -1, 0, 0,
    -1, -1, -4, -3, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, -2,
    0, 0, -4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, -10, 0, 0,
    0, -2, 0, 0, 0, -7, 0, -2,
    0, -2, -3, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 0, -1, -1, 0, -1, 0, 0,
    0, -1, -2, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -21, 0, 0,
    0, -15, 0, -16, 0, 2, 0, 0,
    0, 0, 0, 0, 0, -3, -2, 0,
    0, -2, -2, 0, 0, -2, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, -2, 0, 0, 0, 1, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -13, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, -2, 0, 0,
    0, -2, -3, -5, 0, 0, 0, 0,
    0, -22, 0, 0, 0, 0, 0, 0,
    0, 1, -5, 0, 0, -16, -2, -16,
    -7, 0, -22, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, -10, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -32, 0, 0, 0, -14, 0, -14,
    0, 0, 0, 0, 0, -4, 0, -3,
    0, -1, -1, 0, 0, -1, 0, 0,
    1, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -2,
    -2, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, -1, 0, 0, -4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -5, 0, 0, 0, 0, -20, -21, 0,
    0, -9, -2, -17, -1, 1, 0, 1,
    1, 0, 1, 0, 0, -13, -7, 0,
    -7, -16, -5, -6, 0, -5, -6, -4,
    -6, -5, 0, 0, 0, 0, 0, 2,
    0, -17, -12, 0, 0, -6, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, -4, -3, 0, 0, -4, -2, 0,
    0, -2, -1, 0, 0, 0, 1, 0,
    0, 0, 0, 1, 0, -11, -5, 0,
    0, -3, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, -3, -2, 0,
    0, -2, -2, 0, 0, -1, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, -12, 0, 0, 0, -2, 0,
    0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, -2, 0, 0, -2, 0, 0,
    0, -2, -2, 0, 0, 0, 0, 0,
    0, 0, -2, 2, -4, -18, -12, 0,
    0, -12, -2, -7, -1, 1, -7, 1,
    1, 1, 1, 0, 1, -5, -5, -2,
    -3, -5, -3, -5, -2, -3, -2, 0,
    -2, -2, 1, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, -2, 0, 0,
    0, -1, -2, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -1, -1, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 1, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -7, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    -2, -1, 0, 0, 0, 1, 0, 0,
    0, -14, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, -1, 2, 0, -3, 0, 0,
    4, 0, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, -1, 1, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -10, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -2, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 40,
    .right_class_cnt     = 36,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 3,
    .bpp = 4,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t main_font_10 = {
#else
lv_font_t main_font_10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MAIN_FONT_10*/

