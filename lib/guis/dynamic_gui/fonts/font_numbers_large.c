/*******************************************************************************
 * Size: 36 px
 * Bpp: 4
 * Opts: --no-compress --no-prefilter --bpp 4 --format lvgl --size 36 --font Roboto-Medium.ttf -r 0x20,0x25,0xB0,0x43,0x46,0x2D,0x30-0x39,0x2E -o font_numbers_large.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONT_NUMBERS_LARGE
#define FONT_NUMBERS_LARGE 1
#endif

#if FONT_NUMBERS_LARGE

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0025 "%" */
    0x0, 0x7, 0xcf, 0xfd, 0x91, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xff, 0xff,
    0xfe, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa, 0xff, 0xfc, 0xbe, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0x40, 0x1,
    0xdf, 0xf6, 0x0, 0x0, 0x1e, 0xa2, 0x0, 0x0,
    0x3f, 0xfd, 0x0, 0x0, 0x7f, 0xf8, 0x0, 0x0,
    0xbf, 0xf3, 0x0, 0x0, 0x4f, 0xfb, 0x0, 0x0,
    0x6f, 0xf9, 0x0, 0x5, 0xff, 0x80, 0x0, 0x0,
    0x3f, 0xfc, 0x0, 0x0, 0x7f, 0xf8, 0x0, 0x1e,
    0xfd, 0x0, 0x0, 0x0, 0x1f, 0xff, 0x40, 0x1,
    0xdf, 0xf6, 0x0, 0x9f, 0xf4, 0x0, 0x0, 0x0,
    0xa, 0xff, 0xfb, 0xae, 0xff, 0xe0, 0x4, 0xff,
    0xa0, 0x0, 0x0, 0x0, 0x1, 0xcf, 0xff, 0xff,
    0xff, 0x30, 0xd, 0xfe, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x6, 0xcf, 0xfd, 0x92, 0x0, 0x8f, 0xf6,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xff, 0xd0, 0x3,
    0xae, 0xfe, 0xa3, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xff, 0x30, 0x6f, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x0, 0x0, 0x0, 0x5f, 0xf9, 0x3, 0xff,
    0xfe, 0xbe, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x1,
    0xef, 0xe1, 0xa, 0xff, 0xa0, 0x0, 0xbf, 0xf9,
    0x0, 0x0, 0x0, 0xa, 0xff, 0x50, 0xe, 0xff,
    0x20, 0x0, 0x3f, 0xfd, 0x0, 0x0, 0x0, 0x4f,
    0xfb, 0x0, 0xf, 0xff, 0x0, 0x0, 0x1f, 0xfe,
    0x0, 0x0, 0x0, 0xdf, 0xf2, 0x0, 0xf, 0xff,
    0x0, 0x0, 0x1f, 0xfe, 0x0, 0x0, 0x8, 0xff,
    0x70, 0x0, 0xe, 0xff, 0x20, 0x0, 0x3f, 0xfd,
    0x0, 0x0, 0xc, 0xfc, 0x0, 0x0, 0xa, 0xff,
    0xa0, 0x0, 0xaf, 0xf9, 0x0, 0x0, 0x0, 0x53,
    0x0, 0x0, 0x3, 0xff, 0xfd, 0xad, 0xff, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f,
    0xff, 0xff, 0xff, 0x60, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xae, 0xfe, 0xa3, 0x0,

    /* U+002D "-" */
    0x69, 0x99, 0x99, 0x99, 0x94, 0xcf, 0xff, 0xff,
    0xff, 0xf7, 0xcf, 0xff, 0xff, 0xff, 0xf7, 0xcf,
    0xff, 0xff, 0xff, 0xf7,

    /* U+002E "." */
    0x7, 0xcb, 0x40, 0x5f, 0xff, 0xf1, 0x9f, 0xff,
    0xf4, 0x6f, 0xff, 0xf2, 0x9, 0xfe, 0x60,

    /* U+0030 "0" */
    0x0, 0x0, 0x4, 0x9d, 0xef, 0xeb, 0x70, 0x0,
    0x0, 0x0, 0x1, 0xbf, 0xff, 0xff, 0xff, 0xfe,
    0x50, 0x0, 0x0, 0xc, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf5, 0x0, 0x0, 0x8f, 0xff, 0xfe, 0x99,
    0xbf, 0xff, 0xfe, 0x10, 0x1, 0xff, 0xff, 0xa0,
    0x0, 0x4, 0xff, 0xff, 0x80, 0x6, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x8f, 0xff, 0xd0, 0xb, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf2, 0xe,
    0xff, 0xf5, 0x0, 0x0, 0x0, 0xe, 0xff, 0xf5,
    0xf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0xc, 0xff,
    0xf7, 0x1f, 0xff, 0xf1, 0x0, 0x0, 0x0, 0xb,
    0xff, 0xf8, 0x2f, 0xff, 0xf1, 0x0, 0x0, 0x0,
    0xa, 0xff, 0xf9, 0x2f, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0xa, 0xff, 0xf9, 0x2f, 0xff, 0xf1, 0x0,
    0x0, 0x0, 0xa, 0xff, 0xf9, 0x2f, 0xff, 0xf1,
    0x0, 0x0, 0x0, 0xa, 0xff, 0xf9, 0x2f, 0xff,
    0xf1, 0x0, 0x0, 0x0, 0xa, 0xff, 0xf9, 0x2f,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0xa, 0xff, 0xf9,
    0x1f, 0xff, 0xf2, 0x0, 0x0, 0x0, 0xb, 0xff,
    0xf8, 0xf, 0xff, 0xf3, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xf7, 0xd, 0xff, 0xf5, 0x0, 0x0, 0x0,
    0xe, 0xff, 0xf4, 0xa, 0xff, 0xf9, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf1, 0x6, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x8f, 0xff, 0xd0, 0x0, 0xff, 0xff,
    0xa0, 0x0, 0x4, 0xff, 0xff, 0x70, 0x0, 0x7f,
    0xff, 0xfe, 0x98, 0xbf, 0xff, 0xfe, 0x0, 0x0,
    0xc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x0,
    0x0, 0x0, 0xaf, 0xff, 0xff, 0xff, 0xfe, 0x40,
    0x0, 0x0, 0x0, 0x3, 0x9d, 0xff, 0xeb, 0x70,
    0x0, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x0, 0x0, 0x17, 0xd7, 0x0, 0x0,
    0x0, 0x5b, 0xff, 0xf7, 0x0, 0x3, 0x9f, 0xff,
    0xff, 0xf7, 0x7, 0xdf, 0xff, 0xff, 0xff, 0xf7,
    0xf, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xf, 0xff,
    0xfc, 0x7d, 0xff, 0xf7, 0xf, 0xd7, 0x20, 0xc,
    0xff, 0xf7, 0x3, 0x0, 0x0, 0xc, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xf7, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xf7, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xf7, 0x0, 0x0, 0x0, 0xc, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xf7, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xf7, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xf7, 0x0, 0x0, 0x0, 0xc, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xf7, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xf7, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xf7, 0x0, 0x0, 0x0, 0xc, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xf7, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xf7, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xf7, 0x0, 0x0, 0x0, 0xc, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xf7, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xf7,

    /* U+0032 "2" */
    0x0, 0x0, 0x5, 0xae, 0xff, 0xeb, 0x71, 0x0,
    0x0, 0x0, 0x0, 0x3e, 0xff, 0xff, 0xff, 0xff,
    0xf7, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0x0, 0x0, 0x2f, 0xff, 0xff,
    0xc9, 0x9c, 0xff, 0xff, 0xf4, 0x0, 0xc, 0xff,
    0xff, 0x40, 0x0, 0x6, 0xff, 0xff, 0xb0, 0x2,
    0xff, 0xff, 0x50, 0x0, 0x0, 0x9, 0xff, 0xff,
    0x0, 0x6f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xf1, 0x8, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xff, 0x10, 0x23, 0x33, 0x20, 0x0,
    0x0, 0x0, 0x4f, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9, 0xff, 0xfa, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5f, 0xff, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x4f, 0xff, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xfb, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2e, 0xff, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2e, 0xff, 0xfd, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1d, 0xff, 0xfd,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0xff,
    0xfe, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xfe, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xff, 0xff, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xa, 0xff, 0xff, 0xb8, 0x88, 0x88, 0x88,
    0x88, 0x88, 0x11, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf2, 0x1f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x21, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2,

    /* U+0033 "3" */
    0x0, 0x0, 0x16, 0xbd, 0xff, 0xeb, 0x60, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x50, 0x0, 0x0, 0x9f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf7, 0x0, 0x6, 0xff, 0xff, 0xfb, 0x99,
    0xcf, 0xff, 0xff, 0x20, 0xe, 0xff, 0xfd, 0x20,
    0x0, 0x4, 0xff, 0xff, 0x90, 0x3f, 0xff, 0xf3,
    0x0, 0x0, 0x0, 0x9f, 0xff, 0xd0, 0x4c, 0xcc,
    0xb0, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xff,
    0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff,
    0xff, 0x30, 0x0, 0x0, 0x1, 0x77, 0x89, 0xdf,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x2, 0xff, 0xff,
    0xff, 0xfe, 0x50, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xff, 0xff, 0xfa, 0x20, 0x0, 0x0, 0x0, 0x2,
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x5c, 0xff, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xff, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xf5, 0x36, 0x66, 0x40, 0x0, 0x0, 0x0,
    0xe, 0xff, 0xf5, 0x8f, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xf4, 0x5f, 0xff, 0xf2, 0x0,
    0x0, 0x0, 0x6f, 0xff, 0xf1, 0x1f, 0xff, 0xfd,
    0x10, 0x0, 0x3, 0xff, 0xff, 0xb0, 0x8, 0xff,
    0xff, 0xfb, 0x89, 0xcf, 0xff, 0xff, 0x30, 0x0,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0x0,
    0x0, 0x8, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x40,
    0x0, 0x0, 0x0, 0x17, 0xce, 0xff, 0xda, 0x50,
    0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1e,
    0xff, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xaf, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xff, 0xff, 0xff, 0x50, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xd, 0xff, 0xff, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xff,
    0xff, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xfa, 0xef, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xf1, 0xef, 0xff, 0x50, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0x60, 0xef, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x2, 0xff, 0xfc, 0x0,
    0xef, 0xff, 0x50, 0x0, 0x0, 0x0, 0xb, 0xff,
    0xf2, 0x0, 0xef, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x6f, 0xff, 0x80, 0x0, 0xef, 0xff, 0x50, 0x0,
    0x0, 0x1, 0xef, 0xfd, 0x0, 0x0, 0xef, 0xff,
    0x50, 0x0, 0x0, 0xa, 0xff, 0xf4, 0x0, 0x0,
    0xef, 0xff, 0x50, 0x0, 0x0, 0x4f, 0xff, 0x90,
    0x0, 0x0, 0xef, 0xff, 0x50, 0x0, 0x0, 0xef,
    0xfe, 0x10, 0x0, 0x0, 0xef, 0xff, 0x50, 0x0,
    0x9, 0xff, 0xfc, 0x88, 0x88, 0x88, 0xff, 0xff,
    0xb8, 0x84, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xef, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xef, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xef, 0xff, 0x50, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xef, 0xff, 0x50, 0x0,

    /* U+0035 "5" */
    0x0, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x30, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x30, 0x0, 0xdf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x30, 0x0, 0xef, 0xff, 0xdd, 0xdd,
    0xdd, 0xdd, 0xdd, 0x20, 0x0, 0xff, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0xff,
    0xfa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5,
    0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xf6, 0x15, 0x78, 0x74, 0x0, 0x0,
    0x0, 0x9, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xe6,
    0x0, 0x0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x90, 0x0, 0xc, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf6, 0x0, 0xc, 0xff, 0xfb, 0x40,
    0x2, 0x9f, 0xff, 0xff, 0x10, 0x0, 0x15, 0x60,
    0x0, 0x0, 0x6, 0xff, 0xff, 0x60, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xcf, 0xff, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xf0, 0x46, 0x66, 0x30, 0x0, 0x0, 0x0,
    0x5f, 0xff, 0xe0, 0x9f, 0xff, 0xa0, 0x0, 0x0,
    0x0, 0x9f, 0xff, 0xc0, 0x6f, 0xff, 0xf1, 0x0,
    0x0, 0x1, 0xef, 0xff, 0x80, 0x1f, 0xff, 0xfc,
    0x10, 0x0, 0x1b, 0xff, 0xff, 0x20, 0x7, 0xff,
    0xff, 0xfa, 0x8a, 0xef, 0xff, 0xf9, 0x0, 0x0,
    0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x8, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x0, 0x0, 0x18, 0xce, 0xfe, 0xd9, 0x30,
    0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x1, 0x6a, 0xce, 0xf3, 0x0,
    0x0, 0x0, 0x0, 0x19, 0xff, 0xff, 0xff, 0x30,
    0x0, 0x0, 0x0, 0x4f, 0xff, 0xff, 0xff, 0xf3,
    0x0, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xfe, 0xcb,
    0x20, 0x0, 0x0, 0x2f, 0xff, 0xfe, 0x71, 0x0,
    0x0, 0x0, 0x0, 0xc, 0xff, 0xfc, 0x10, 0x0,
    0x0, 0x0, 0x0, 0x5, 0xff, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xcf, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xd0, 0x4a,
    0xef, 0xec, 0x60, 0x0, 0x6, 0xff, 0xf9, 0xbf,
    0xff, 0xff, 0xff, 0xd2, 0x0, 0x9f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xe1, 0xc, 0xff, 0xff,
    0xff, 0xb9, 0xaf, 0xff, 0xff, 0xa0, 0xdf, 0xff,
    0xfd, 0x20, 0x0, 0x1d, 0xff, 0xff, 0x2e, 0xff,
    0xfe, 0x10, 0x0, 0x0, 0x2f, 0xff, 0xf8, 0xef,
    0xff, 0x60, 0x0, 0x0, 0x0, 0xaf, 0xff, 0xbe,
    0xff, 0xf5, 0x0, 0x0, 0x0, 0x6, 0xff, 0xfd,
    0xef, 0xff, 0x50, 0x0, 0x0, 0x0, 0x4f, 0xff,
    0xfd, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x4, 0xff,
    0xfe, 0xaf, 0xff, 0x90, 0x0, 0x0, 0x0, 0x6f,
    0xff, 0xd7, 0xff, 0xfe, 0x0, 0x0, 0x0, 0xa,
    0xff, 0xfa, 0x1f, 0xff, 0xf6, 0x0, 0x0, 0x2,
    0xff, 0xff, 0x60, 0xaf, 0xff, 0xf4, 0x0, 0x1,
    0xdf, 0xff, 0xe0, 0x1, 0xef, 0xff, 0xfb, 0x9a,
    0xff, 0xff, 0xf6, 0x0, 0x4, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf9, 0x0, 0x0, 0x3, 0xdf, 0xff,
    0xff, 0xff, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x6b,
    0xef, 0xec, 0x82, 0x0, 0x0,

    /* U+0037 "7" */
    0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfe, 0x68, 0x88, 0x88, 0x88, 0x88,
    0x88, 0x8d, 0xff, 0xf7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xe, 0xff, 0xf1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xff, 0xa0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xef, 0xff, 0x30, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0xf5,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xff,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf,
    0xff, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xff, 0xff, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x9, 0xff, 0xf9, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8f, 0xff, 0xb0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xff, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xe, 0xff, 0xf6, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0xff,
    0xff, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xff, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xaf, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x5, 0xad, 0xff, 0xec, 0x71, 0x0,
    0x0, 0x0, 0x2, 0xdf, 0xff, 0xff, 0xff, 0xff,
    0x70, 0x0, 0x0, 0x2e, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf8, 0x0, 0x0, 0xcf, 0xff, 0xfe, 0xa9,
    0xcf, 0xff, 0xff, 0x30, 0x3, 0xff, 0xff, 0xa0,
    0x0, 0x5, 0xff, 0xff, 0xa0, 0x7, 0xff, 0xff,
    0x0, 0x0, 0x0, 0x9f, 0xff, 0xe0, 0x9, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x4f, 0xff, 0xf0, 0x7,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x4f, 0xff, 0xe0,
    0x4, 0xff, 0xff, 0x10, 0x0, 0x0, 0x8f, 0xff,
    0xb0, 0x0, 0xdf, 0xff, 0xa0, 0x0, 0x4, 0xff,
    0xff, 0x40, 0x0, 0x3f, 0xff, 0xfe, 0xa9, 0xcf,
    0xff, 0xf9, 0x0, 0x0, 0x3, 0xdf, 0xff, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x8f, 0xff,
    0xff, 0xff, 0xfd, 0x20, 0x0, 0x0, 0x1d, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x0, 0x0, 0xcf,
    0xff, 0xd5, 0x10, 0x3a, 0xff, 0xff, 0x40, 0x7,
    0xff, 0xfe, 0x10, 0x0, 0x0, 0x9f, 0xff, 0xd0,
    0xd, 0xff, 0xf6, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf4, 0x1f, 0xff, 0xf2, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xf8, 0x2f, 0xff, 0xf1, 0x0, 0x0, 0x0,
    0xb, 0xff, 0xf9, 0x1f, 0xff, 0xf3, 0x0, 0x0,
    0x0, 0xc, 0xff, 0xf8, 0xe, 0xff, 0xf9, 0x0,
    0x0, 0x0, 0x2f, 0xff, 0xf5, 0x9, 0xff, 0xff,
    0x60, 0x0, 0x1, 0xdf, 0xff, 0xf1, 0x2, 0xff,
    0xff, 0xfd, 0x98, 0xaf, 0xff, 0xff, 0x80, 0x0,
    0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x0,
    0x0, 0x4, 0xef, 0xff, 0xff, 0xff, 0xff, 0x90,
    0x0, 0x0, 0x0, 0x5, 0xad, 0xff, 0xec, 0x82,
    0x0, 0x0,

    /* U+0039 "9" */
    0x0, 0x0, 0x5, 0xae, 0xff, 0xd9, 0x30, 0x0,
    0x0, 0x0, 0x2, 0xcf, 0xff, 0xff, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x2e, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xa0, 0x0, 0x0, 0xdf, 0xff, 0xfd, 0x9a,
    0xef, 0xff, 0xf6, 0x0, 0x7, 0xff, 0xff, 0x70,
    0x0, 0xb, 0xff, 0xff, 0x10, 0xd, 0xff, 0xfa,
    0x0, 0x0, 0x0, 0xdf, 0xff, 0x70, 0x2f, 0xff,
    0xf2, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xc0, 0x4f,
    0xff, 0xf0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf0,
    0x5f, 0xff, 0xd0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf2, 0x4f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xf3, 0x3f, 0xff, 0xf2, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf4, 0xf, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x4f, 0xff, 0xf4, 0xa, 0xff, 0xff, 0x50,
    0x0, 0x4, 0xff, 0xff, 0xf4, 0x3, 0xff, 0xff,
    0xfb, 0x78, 0xcf, 0xff, 0xff, 0xf3, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0x0,
    0x7, 0xff, 0xff, 0xff, 0xfe, 0x4f, 0xff, 0xf0,
    0x0, 0x0, 0x29, 0xdf, 0xfc, 0x70, 0x3f, 0xff,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f,
    0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xdf, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5f, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3a, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0,
    0x6b, 0xcf, 0xff, 0xff, 0xfe, 0x20, 0x0, 0x0,
    0x0, 0xaf, 0xff, 0xff, 0xff, 0xd1, 0x0, 0x0,
    0x0, 0x0, 0xaf, 0xff, 0xff, 0xe7, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xec, 0x94, 0x0, 0x0,
    0x0, 0x0,

    /* U+0043 "C" */
    0x0, 0x0, 0x0, 0x5, 0xad, 0xff, 0xec, 0x94,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xef, 0xff,
    0xff, 0xff, 0xff, 0xc2, 0x0, 0x0, 0x0, 0x0,
    0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x0, 0x8, 0xff, 0xff, 0xff, 0xcb, 0xdf,
    0xff, 0xff, 0xf3, 0x0, 0x0, 0x4f, 0xff, 0xfe,
    0x60, 0x0, 0x0, 0x8f, 0xff, 0xfd, 0x0, 0x0,
    0xcf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x6, 0xff,
    0xff, 0x50, 0x3, 0xff, 0xff, 0x60, 0x0, 0x0,
    0x0, 0x0, 0xdf, 0xff, 0xa0, 0x9, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xff, 0xe0,
    0xd, 0xff, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4c, 0xcc, 0xc0, 0xf, 0xff, 0xf7, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xf5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xff, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf5,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xd, 0xff, 0xfa, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3a, 0xaa, 0xa0, 0x9, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xff,
    0xe0, 0x4, 0xff, 0xff, 0x50, 0x0, 0x0, 0x0,
    0x0, 0xdf, 0xff, 0xb0, 0x0, 0xdf, 0xff, 0xe2,
    0x0, 0x0, 0x0, 0x6, 0xff, 0xff, 0x50, 0x0,
    0x5f, 0xff, 0xfe, 0x40, 0x0, 0x1, 0x7f, 0xff,
    0xfd, 0x0, 0x0, 0x9, 0xff, 0xff, 0xfe, 0xcb,
    0xdf, 0xff, 0xff, 0xf3, 0x0, 0x0, 0x0, 0xaf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50, 0x0,
    0x0, 0x0, 0x6, 0xef, 0xff, 0xff, 0xff, 0xff,
    0xc2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xbe,
    0xff, 0xec, 0x83, 0x0, 0x0, 0x0,

    /* U+0046 "F" */
    0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xd6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfd, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xd6, 0xff, 0xff, 0xbb, 0xbb, 0xbb, 0xbb,
    0xbb, 0xb9, 0x6f, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x50, 0x6f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x6, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x50, 0x6f,
    0xff, 0xfa, 0xaa, 0xaa, 0xaa, 0xaa, 0xa3, 0x6,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6f, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6f, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0xff, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6f, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xff, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6, 0xff, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+00B0 "°" */
    0x0, 0x4, 0x87, 0x30, 0x0, 0x1, 0xcf, 0xff,
    0xf9, 0x0, 0xd, 0xff, 0xff, 0xff, 0x80, 0x6f,
    0xf8, 0x12, 0xcf, 0xf1, 0xbf, 0xd0, 0x0, 0x2f,
    0xf5, 0xbf, 0xb0, 0x0, 0xf, 0xf6, 0x9f, 0xf2,
    0x0, 0x6f, 0xf4, 0x3f, 0xff, 0xab, 0xff, 0xd0,
    0x7, 0xff, 0xff, 0xff, 0x30, 0x0, 0x4c, 0xfe,
    0xa2, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 143, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 423, .box_w = 24, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 189, .box_w = 10, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 332, .adv_w = 161, .box_w = 6, .box_h = 5, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 327, .box_w = 18, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 581, .adv_w = 327, .box_w = 12, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 737, .adv_w = 327, .box_w = 19, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 984, .adv_w = 327, .box_w = 18, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1218, .adv_w = 327, .box_w = 20, .box_h = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1478, .adv_w = 327, .box_w = 18, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1712, .adv_w = 327, .box_w = 17, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1933, .adv_w = 327, .box_w = 18, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2167, .adv_w = 327, .box_w = 18, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2401, .adv_w = 327, .box_w = 18, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2635, .adv_w = 376, .box_w = 22, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2921, .adv_w = 316, .box_w = 17, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3142, .adv_w = 219, .box_w = 10, .box_h = 10, .ofs_x = 2, .ofs_y = 17}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x5, 0xd, 0xe, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x23, 0x26,
    0x90
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 145, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 17, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    16, 4
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -77
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 1,
    .glyph_ids_size = 0
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
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
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
const lv_font_t font_numbers_large = {
#else
lv_font_t font_numbers_large = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 27,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONT_NUMBERS_LARGE*/

