/*******************************************************************************
 * Size: 36 px
 * Bpp: 4
 * Opts: --no-compress --no-prefilter --bpp 4 --format lvgl --size 36 --font RobotoMono-Medium.ttf -r 0x20,0x25,0xB0,0x43,0x46,0x2D,0x30-0x39,0x2E,0x3A -o font_numbers_large.c
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
    0x0, 0x29, 0xef, 0xea, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0x50,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0xff, 0xea,
    0xdf, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xff, 0xe1, 0x0, 0xdf, 0xf4, 0x0, 0x3, 0x70,
    0x0, 0x0, 0x4f, 0xfa, 0x0, 0x8, 0xff, 0x60,
    0x0, 0xcf, 0xd0, 0x0, 0x4, 0xff, 0xa0, 0x0,
    0x7f, 0xf6, 0x0, 0x5f, 0xf5, 0x0, 0x0, 0x4f,
    0xfb, 0x0, 0x9, 0xff, 0x60, 0xe, 0xfc, 0x0,
    0x0, 0x1, 0xff, 0xf5, 0x3, 0xef, 0xf3, 0x7,
    0xff, 0x40, 0x0, 0x0, 0xa, 0xff, 0xff, 0xff,
    0xfc, 0x1, 0xff, 0xb0, 0x0, 0x0, 0x0, 0xb,
    0xff, 0xff, 0xfc, 0x10, 0x9f, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x4, 0x89, 0x85, 0x0, 0x3f, 0xf9,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xff, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xff, 0x70, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xdf, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f,
    0xf6, 0x1, 0x69, 0x96, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x1e, 0xfd, 0x4, 0xff, 0xff, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x8, 0xff, 0x41, 0xff, 0xff,
    0xff, 0xff, 0x10, 0x0, 0x0, 0x2, 0xff, 0xb0,
    0x8f, 0xfb, 0x11, 0xbf, 0xf8, 0x0, 0x0, 0x0,
    0xaf, 0xf2, 0xc, 0xff, 0x30, 0x3, 0xff, 0xc0,
    0x0, 0x0, 0x3f, 0xf9, 0x0, 0xef, 0xf0, 0x0,
    0xf, 0xfe, 0x0, 0x0, 0xc, 0xff, 0x10, 0xe,
    0xff, 0x0, 0x0, 0xff, 0xe0, 0x0, 0x0, 0x3c,
    0x80, 0x0, 0xdf, 0xf2, 0x0, 0x1f, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xa, 0xff, 0x70, 0x6,
    0xff, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xbb, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x9f, 0xff, 0xff, 0xf9, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0xff, 0xc6,
    0x0,

    /* U+002D "-" */
    0x48, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x58,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x8f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa8, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfa,

    /* U+002E "." */
    0x0, 0x9e, 0xe9, 0x0, 0x9, 0xff, 0xff, 0xa0,
    0xf, 0xff, 0xff, 0xf0, 0xf, 0xff, 0xff, 0xf0,
    0xa, 0xff, 0xff, 0xa0, 0x0, 0x9e, 0xe9, 0x10,

    /* U+0030 "0" */
    0x0, 0x0, 0x6, 0xbe, 0xfe, 0xd9, 0x30, 0x0,
    0x0, 0x0, 0x3, 0xdf, 0xff, 0xff, 0xff, 0xfa,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0, 0x0, 0x0, 0xdf, 0xff, 0xfb, 0x89,
    0xdf, 0xff, 0xf8, 0x0, 0x6, 0xff, 0xff, 0x30,
    0x0, 0x8, 0xff, 0xff, 0x10, 0xd, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0xcf, 0xff, 0x70, 0x1f, 0xff,
    0xf1, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xb0, 0x4f,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xf0,
    0x6f, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x4f, 0xff,
    0xf0, 0x7f, 0xff, 0xb0, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xf1, 0x7f, 0xff, 0xb0, 0x0, 0x1, 0xbf,
    0xff, 0xff, 0xf2, 0x7f, 0xff, 0xb0, 0x0, 0x4e,
    0xff, 0xef, 0xff, 0xf2, 0x7f, 0xff, 0xb0, 0x8,
    0xff, 0xfa, 0x2f, 0xff, 0xf2, 0x7f, 0xff, 0xb2,
    0xcf, 0xff, 0x60, 0x1f, 0xff, 0xf2, 0x7f, 0xff,
    0xef, 0xff, 0xd2, 0x0, 0x1f, 0xff, 0xf2, 0x7f,
    0xff, 0xff, 0xf9, 0x0, 0x0, 0x1f, 0xff, 0xf2,
    0x7f, 0xff, 0xff, 0x50, 0x0, 0x0, 0x1f, 0xff,
    0xf1, 0x6f, 0xff, 0xe2, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xf0, 0x4f, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0xf0, 0x1f, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0x6f, 0xff, 0xb0, 0xd, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0xcf, 0xff, 0x70, 0x6, 0xff, 0xff,
    0x40, 0x0, 0x8, 0xff, 0xff, 0x10, 0x0, 0xdf,
    0xff, 0xfb, 0x89, 0xdf, 0xff, 0xf8, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0x3, 0xdf, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xbe, 0xff, 0xd9, 0x30,
    0x0, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0,
    0x0, 0x2, 0x8e, 0xf1, 0x0, 0x0, 0x6, 0xcf,
    0xff, 0xf1, 0x0, 0x39, 0xff, 0xff, 0xff, 0xf1,
    0x5d, 0xff, 0xff, 0xff, 0xff, 0xf1, 0xaf, 0xff,
    0xff, 0xff, 0xff, 0xf1, 0xaf, 0xff, 0xd7, 0x3f,
    0xff, 0xf1, 0xaf, 0x93, 0x0, 0x2f, 0xff, 0xf1,
    0x30, 0x0, 0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1,
    0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1,
    0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1,
    0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1,
    0x0, 0x0, 0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xf1,

    /* U+0032 "2" */
    0x0, 0x0, 0x5, 0xad, 0xff, 0xeb, 0x60, 0x0,
    0x0, 0x0, 0x0, 0x3d, 0xff, 0xff, 0xff, 0xff,
    0xe4, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf5, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xca, 0xae, 0xff, 0xff, 0xf1, 0x0, 0xc, 0xff,
    0xfe, 0x30, 0x0, 0x8, 0xff, 0xff, 0x80, 0x2,
    0xff, 0xff, 0x30, 0x0, 0x0, 0xb, 0xff, 0xfc,
    0x0, 0x7f, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x4f,
    0xff, 0xf0, 0x9, 0xff, 0xf9, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xff, 0x0, 0x23, 0x33, 0x20, 0x0,
    0x0, 0x0, 0x4f, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9, 0xff, 0xfa, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xff,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f,
    0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6f, 0xff, 0xf5, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5f, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4f, 0xff, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2e, 0xff, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1d, 0xff,
    0xfd, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xfd, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xc, 0xff, 0xfe, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xb, 0xff, 0xff, 0xa7, 0x77, 0x77, 0x77,
    0x77, 0x77, 0x2, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x2f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,

    /* U+0033 "3" */
    0x0, 0x0, 0x5, 0xad, 0xff, 0xec, 0x82, 0x0,
    0x0, 0x0, 0x4, 0xdf, 0xff, 0xff, 0xff, 0xff,
    0x90, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfb, 0x0, 0x2, 0xff, 0xff, 0xfc, 0x99,
    0xbf, 0xff, 0xff, 0x70, 0x9, 0xff, 0xff, 0x50,
    0x0, 0x1, 0xdf, 0xff, 0xe0, 0xe, 0xff, 0xf7,
    0x0, 0x0, 0x0, 0x3f, 0xff, 0xf2, 0xc, 0xcc,
    0xc2, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4f, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xef,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x56, 0x67, 0xaf,
    0xff, 0xfb, 0x0, 0x0, 0x0, 0x0, 0xdf, 0xff,
    0xff, 0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0xdf,
    0xff, 0xff, 0xfd, 0x50, 0x0, 0x0, 0x0, 0x0,
    0xdf, 0xff, 0xff, 0xff, 0xfa, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3b, 0xff, 0xff, 0x90, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0xff,
    0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9,
    0xff, 0xf9, 0x16, 0x66, 0x50, 0x0, 0x0, 0x0,
    0x8, 0xff, 0xfa, 0x3f, 0xff, 0xf0, 0x0, 0x0,
    0x0, 0xa, 0xff, 0xf9, 0x1f, 0xff, 0xf5, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xf6, 0xb, 0xff, 0xff,
    0x50, 0x0, 0x1, 0xbf, 0xff, 0xf1, 0x3, 0xff,
    0xff, 0xfc, 0x88, 0xaf, 0xff, 0xff, 0x70, 0x0,
    0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x4, 0xef, 0xff, 0xff, 0xff, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x6, 0xad, 0xff, 0xeb, 0x71,
    0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xff,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0xff, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xef, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xaf, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4f, 0xff, 0xff, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0xe, 0xff, 0xda, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0xf3,
    0xaf, 0xff, 0x80, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xf9, 0xa, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0xdf, 0xfe, 0x0, 0xaf, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0x40, 0xa, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x2f, 0xff, 0xa0, 0x0, 0xaf, 0xff,
    0x80, 0x0, 0x0, 0xc, 0xff, 0xe1, 0x0, 0xa,
    0xff, 0xf8, 0x0, 0x0, 0x6, 0xff, 0xf5, 0x0,
    0x0, 0xaf, 0xff, 0x80, 0x0, 0x1, 0xff, 0xfb,
    0x0, 0x0, 0xa, 0xff, 0xf8, 0x0, 0x0, 0xaf,
    0xff, 0x10, 0x0, 0x0, 0xaf, 0xff, 0x80, 0x0,
    0x5f, 0xff, 0xd8, 0x88, 0x88, 0x8d, 0xff, 0xfc,
    0x88, 0x6c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0xcf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xcc, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xa, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xaf, 0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xa, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xaf, 0xff, 0x80, 0x0,

    /* U+0035 "5" */
    0x0, 0x4f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x70, 0x0, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x70, 0x0, 0x8f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x70, 0x0, 0xaf, 0xff, 0xed, 0xdd,
    0xdd, 0xdd, 0xdd, 0x60, 0x0, 0xbf, 0xff, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xdf, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xff, 0xfa, 0x3, 0x67, 0x64, 0x0, 0x0,
    0x0, 0x4, 0xff, 0xfd, 0xef, 0xff, 0xff, 0xf8,
    0x0, 0x0, 0x6, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc1, 0x0, 0x8, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfa, 0x0, 0x7, 0xff, 0xfd, 0x51,
    0x1, 0x6e, 0xff, 0xff, 0x40, 0x0, 0x3, 0x60,
    0x0, 0x0, 0x2, 0xef, 0xff, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xf4, 0x27, 0x77, 0x50, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf3, 0x4f, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x3f, 0xff, 0xf1, 0x1f, 0xff, 0xf5, 0x0,
    0x0, 0x0, 0x9f, 0xff, 0xd0, 0xb, 0xff, 0xfe,
    0x30, 0x0, 0x6, 0xff, 0xff, 0x70, 0x2, 0xff,
    0xff, 0xfb, 0x88, 0xcf, 0xff, 0xfd, 0x0, 0x0,
    0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x0,
    0x0, 0x4, 0xef, 0xff, 0xff, 0xff, 0xfd, 0x30,
    0x0, 0x0, 0x0, 0x5, 0xae, 0xff, 0xda, 0x50,
    0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x1, 0x5a, 0xce, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x8f, 0xff, 0xff, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x3e, 0xff, 0xff, 0xff,
    0xf4, 0x0, 0x0, 0x0, 0x5, 0xff, 0xff, 0xff,
    0xec, 0xb3, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0x92, 0x0, 0x0, 0x0, 0x0, 0x0, 0xdf, 0xff,
    0xd2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff,
    0xfd, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xff, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xff, 0xd0, 0x29, 0xdf, 0xec, 0x60, 0x0,
    0x0, 0x5f, 0xff, 0x97, 0xff, 0xff, 0xff, 0xfd,
    0x30, 0x0, 0x8f, 0xff, 0xef, 0xff, 0xff, 0xff,
    0xff, 0xe2, 0x0, 0xbf, 0xff, 0xff, 0xfb, 0x8a,
    0xef, 0xff, 0xfb, 0x0, 0xcf, 0xff, 0xfd, 0x20,
    0x0, 0x1b, 0xff, 0xff, 0x30, 0xdf, 0xff, 0xe1,
    0x0, 0x0, 0x1, 0xef, 0xff, 0x80, 0xef, 0xff,
    0x70, 0x0, 0x0, 0x0, 0x8f, 0xff, 0xc0, 0xef,
    0xff, 0x50, 0x0, 0x0, 0x0, 0x4f, 0xff, 0xe0,
    0xdf, 0xff, 0x50, 0x0, 0x0, 0x0, 0x2f, 0xff,
    0xf0, 0xcf, 0xff, 0x60, 0x0, 0x0, 0x0, 0x2f,
    0xff, 0xf0, 0xaf, 0xff, 0x90, 0x0, 0x0, 0x0,
    0x4f, 0xff, 0xe0, 0x6f, 0xff, 0xe0, 0x0, 0x0,
    0x0, 0x8f, 0xff, 0xb0, 0x1f, 0xff, 0xf6, 0x0,
    0x0, 0x0, 0xef, 0xff, 0x60, 0x9, 0xff, 0xff,
    0x40, 0x0, 0x1b, 0xff, 0xff, 0x0, 0x1, 0xef,
    0xff, 0xfb, 0x89, 0xef, 0xff, 0xf7, 0x0, 0x0,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa0, 0x0,
    0x0, 0x3, 0xdf, 0xff, 0xff, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x5, 0xbe, 0xfe, 0xd8, 0x20,
    0x0, 0x0,

    /* U+0037 "7" */
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf3, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x24, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0xbf, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0xf5, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f,
    0xff, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xe, 0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x6, 0xff, 0xf9, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xdf, 0xff, 0x20, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0xff, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0xff,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0xff, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xa, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xff, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xff, 0xa0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xff, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xef, 0xff, 0x60, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x5f, 0xff, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xd, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4, 0xff, 0xff, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xff,
    0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xff, 0xf3, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x17, 0xbe, 0xff, 0xda, 0x50, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xff, 0xff, 0xff, 0xfd,
    0x20, 0x0, 0x0, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xe2, 0x0, 0x3, 0xff, 0xff, 0xfb, 0x9a,
    0xef, 0xff, 0xfc, 0x0, 0x9, 0xff, 0xff, 0x40,
    0x0, 0x9, 0xff, 0xff, 0x40, 0xe, 0xff, 0xf8,
    0x0, 0x0, 0x0, 0xdf, 0xff, 0x80, 0xf, 0xff,
    0xf4, 0x0, 0x0, 0x0, 0x9f, 0xff, 0x90, 0xf,
    0xff, 0xf4, 0x0, 0x0, 0x0, 0x9f, 0xff, 0x90,
    0xb, 0xff, 0xf8, 0x0, 0x0, 0x0, 0xdf, 0xff,
    0x50, 0x4, 0xff, 0xff, 0x40, 0x0, 0x9, 0xff,
    0xfe, 0x0, 0x0, 0x9f, 0xff, 0xfc, 0x9a, 0xdf,
    0xff, 0xf4, 0x0, 0x0, 0x7, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x30, 0x0, 0x0, 0x2, 0xcf, 0xff,
    0xff, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x5f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xd1, 0x0, 0x4, 0xff,
    0xff, 0xa3, 0x1, 0x5d, 0xff, 0xfd, 0x0, 0xd,
    0xff, 0xf9, 0x0, 0x0, 0x0, 0xef, 0xff, 0x70,
    0x4f, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x5f, 0xff,
    0xe0, 0x7f, 0xff, 0xb0, 0x0, 0x0, 0x0, 0x1f,
    0xff, 0xf1, 0x8f, 0xff, 0xa0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf3, 0x7f, 0xff, 0xc0, 0x0, 0x0,
    0x0, 0x2f, 0xff, 0xf1, 0x5f, 0xff, 0xf2, 0x0,
    0x0, 0x0, 0x9f, 0xff, 0xf0, 0xf, 0xff, 0xfd,
    0x20, 0x0, 0x5, 0xff, 0xff, 0xa0, 0x7, 0xff,
    0xff, 0xfa, 0x88, 0xcf, 0xff, 0xff, 0x20, 0x0,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x0,
    0x0, 0x8, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x40,
    0x0, 0x0, 0x0, 0x18, 0xbe, 0xff, 0xda, 0x50,
    0x0, 0x0,

    /* U+0039 "9" */
    0x0, 0x0, 0x28, 0xce, 0xfe, 0xb5, 0x0, 0x0,
    0x0, 0x0, 0x8f, 0xff, 0xff, 0xff, 0xfd, 0x30,
    0x0, 0x0, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x30, 0x0, 0x6f, 0xff, 0xff, 0xa9, 0xbf, 0xff,
    0xfd, 0x0, 0xe, 0xff, 0xfc, 0x10, 0x0, 0x4f,
    0xff, 0xf8, 0x6, 0xff, 0xff, 0x10, 0x0, 0x0,
    0x5f, 0xff, 0xe0, 0xaf, 0xff, 0x90, 0x0, 0x0,
    0x0, 0xdf, 0xff, 0x3d, 0xff, 0xf5, 0x0, 0x0,
    0x0, 0x9, 0xff, 0xf7, 0xef, 0xff, 0x40, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xad, 0xff, 0xf6, 0x0,
    0x0, 0x0, 0x6, 0xff, 0xfb, 0xbf, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x6f, 0xff, 0xc8, 0xff, 0xfe,
    0x0, 0x0, 0x0, 0xd, 0xff, 0xfc, 0x2f, 0xff,
    0xfa, 0x0, 0x0, 0x1b, 0xff, 0xff, 0xb0, 0xbf,
    0xff, 0xfd, 0x87, 0x9f, 0xff, 0xff, 0xfa, 0x1,
    0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x90,
    0x2, 0xdf, 0xff, 0xff, 0xff, 0xb9, 0xff, 0xf7,
    0x0, 0x0, 0x6b, 0xef, 0xeb, 0x50, 0xbf, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0xff,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xef,
    0xff, 0x60, 0x0, 0x0, 0x0, 0x0, 0x1, 0xcf,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x28, 0xff,
    0xff, 0xf4, 0x0, 0x0, 0x2, 0xbc, 0xef, 0xff,
    0xff, 0xf7, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xff, 0xf5, 0x0, 0x0, 0x0, 0x3, 0xff, 0xff,
    0xff, 0xa2, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xed,
    0xa6, 0x10, 0x0, 0x0, 0x0,

    /* U+003A ":" */
    0x0, 0x0, 0x0, 0x0, 0x4d, 0xfd, 0x40, 0x2f,
    0xff, 0xff, 0x27, 0xff, 0xff, 0xf7, 0x7f, 0xff,
    0xff, 0x72, 0xff, 0xff, 0xf2, 0x4, 0xdf, 0xd4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4, 0xcf, 0xd4, 0x2, 0xff, 0xff, 0xf2, 0x7f,
    0xff, 0xff, 0x77, 0xff, 0xff, 0xf7, 0x2f, 0xff,
    0xff, 0x20, 0x4d, 0xfd, 0x40,

    /* U+0043 "C" */
    0x0, 0x0, 0x0, 0x5a, 0xef, 0xfd, 0xa6, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xdf, 0xff, 0xff, 0xff,
    0xfe, 0x40, 0x0, 0x0, 0x4, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x60, 0x0, 0x2, 0xff, 0xff,
    0xfd, 0xa9, 0xcf, 0xff, 0xff, 0x30, 0x0, 0xcf,
    0xff, 0xe4, 0x0, 0x0, 0x3e, 0xff, 0xfc, 0x0,
    0x4f, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x3f, 0xff,
    0xf3, 0x9, 0xff, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0xff, 0x80, 0xef, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x8, 0xff, 0xfb, 0x2f, 0xff, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0x26, 0x66, 0x54, 0xff, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5f,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6f, 0xff, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xff, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff, 0xe0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4f, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xff, 0xff, 0x10, 0x0, 0x0, 0x0,
    0x1, 0x33, 0x32, 0xe, 0xff, 0xf5, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xc0, 0x9f, 0xff, 0xa0,
    0x0, 0x0, 0x0, 0xb, 0xff, 0xf9, 0x4, 0xff,
    0xff, 0x30, 0x0, 0x0, 0x3, 0xff, 0xff, 0x40,
    0xb, 0xff, 0xfe, 0x30, 0x0, 0x3, 0xef, 0xff,
    0xd0, 0x0, 0x3f, 0xff, 0xff, 0xc9, 0x9c, 0xff,
    0xff, 0xf3, 0x0, 0x0, 0x5f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf6, 0x0, 0x0, 0x0, 0x4e, 0xff,
    0xff, 0xff, 0xff, 0xe4, 0x0, 0x0, 0x0, 0x0,
    0x6, 0xbe, 0xff, 0xda, 0x50, 0x0, 0x0,

    /* U+0046 "F" */
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf8, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf8, 0xf, 0xff, 0xfa, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x95, 0xf, 0xff, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xf2, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0xf, 0xff,
    0xfa, 0x99, 0x99, 0x99, 0x99, 0x99, 0x0, 0xf,
    0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xf2, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xff, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xf2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xff,
    0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xf2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+00B0 "°" */
    0x0, 0x3, 0x76, 0x20, 0x0, 0x1, 0xbf, 0xff,
    0xf9, 0x0, 0xc, 0xff, 0xff, 0xff, 0x90, 0x5f,
    0xf9, 0x11, 0xbf, 0xf2, 0x9f, 0xe0, 0x0, 0x1f,
    0xf6, 0xaf, 0xc0, 0x0, 0xf, 0xf7, 0x8f, 0xf2,
    0x0, 0x4f, 0xf5, 0x2f, 0xff, 0x9a, 0xff, 0xe0,
    0x6, 0xff, 0xff, 0xff, 0x40, 0x0, 0x4b, 0xff,
    0xb2, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 346, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 346, .box_w = 21, .box_h = 26, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 346, .box_w = 15, .box_h = 4, .ofs_x = 4, .ofs_y = 10},
    {.bitmap_index = 303, .adv_w = 346, .box_w = 8, .box_h = 6, .ofs_x = 7, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 346, .box_w = 18, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 346, .box_w = 12, .box_h = 27, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 346, .box_w = 19, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 970, .adv_w = 346, .box_w = 18, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1204, .adv_w = 346, .box_w = 19, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1451, .adv_w = 346, .box_w = 18, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1685, .adv_w = 346, .box_w = 18, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1919, .adv_w = 346, .box_w = 19, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2166, .adv_w = 346, .box_w = 18, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2400, .adv_w = 346, .box_w = 17, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2621, .adv_w = 346, .box_w = 7, .box_h = 22, .ofs_x = 8, .ofs_y = 0},
    {.bitmap_index = 2698, .adv_w = 346, .box_w = 19, .box_h = 26, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2945, .adv_w = 346, .box_w = 18, .box_h = 26, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 3179, .adv_w = 346, .box_w = 10, .box_h = 10, .ofs_x = 6, .ofs_y = 17}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x5, 0xd, 0xe, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x23,
    0x26, 0x90
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 145, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 18, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
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
    .kern_dsc = NULL,
    .kern_scale = 0,
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

