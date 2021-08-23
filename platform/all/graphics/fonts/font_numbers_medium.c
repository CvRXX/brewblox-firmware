/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --no-compress --no-prefilter --bpp 4 --format lvgl --size 20 --font Roboto-Medium.ttf -r 0x20,0x25,0xB0,0x43,0x46,0x2D,0x30-0x39,0x2E -o font_numbers_medium.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FONT_NUMBERS_MEDIUM
#define FONT_NUMBERS_MEDIUM 1
#endif

#if FONT_NUMBERS_MEDIUM

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0025 "%" */
    0x1, 0xae, 0xe9, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xf9, 0x9f, 0xa0, 0x0, 0x30, 0x0, 0xf, 0xb0,
    0xb, 0xe0, 0x5, 0xf3, 0x0, 0xf, 0xa0, 0xa,
    0xf0, 0x1e, 0xa0, 0x0, 0xd, 0xe4, 0x4e, 0xc0,
    0x9f, 0x10, 0x0, 0x3, 0xef, 0xfe, 0x33, 0xf6,
    0x0, 0x0, 0x0, 0x3, 0x30, 0xc, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x6f, 0x30, 0x10, 0x0,
    0x0, 0x0, 0x1, 0xf9, 0x2c, 0xff, 0x90, 0x0,
    0x0, 0xa, 0xe1, 0xdf, 0x69, 0xf7, 0x0, 0x0,
    0x4f, 0x61, 0xf8, 0x0, 0xeb, 0x0, 0x0, 0xdc,
    0x3, 0xf7, 0x0, 0xdd, 0x0, 0x7, 0xf3, 0x1,
    0xf9, 0x0, 0xeb, 0x0, 0x1, 0x60, 0x0, 0xcf,
    0x8a, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x1a, 0xfe,
    0x70,

    /* U+002D "-" */
    0x4f, 0xff, 0xfc, 0x5f, 0xff, 0xfd,

    /* U+002E "." */
    0x29, 0x50, 0xaf, 0xf0, 0x5f, 0xb0,

    /* U+0030 "0" */
    0x0, 0x8d, 0xfe, 0xa2, 0x0, 0xb, 0xff, 0xff,
    0xfe, 0x20, 0x5f, 0xf6, 0x2, 0xef, 0xa0, 0xaf,
    0xb0, 0x0, 0x5f, 0xf0, 0xdf, 0x80, 0x0, 0x2f,
    0xf3, 0xef, 0x60, 0x0, 0x1f, 0xf4, 0xff, 0x60,
    0x0, 0xf, 0xf5, 0xff, 0x60, 0x0, 0xf, 0xf5,
    0xff, 0x60, 0x0, 0xf, 0xf5, 0xef, 0x60, 0x0,
    0xf, 0xf4, 0xdf, 0x70, 0x0, 0x2f, 0xf3, 0xaf,
    0xb0, 0x0, 0x5f, 0xf0, 0x4f, 0xf6, 0x2, 0xdf,
    0xa0, 0xa, 0xff, 0xff, 0xfe, 0x20, 0x0, 0x7d,
    0xfe, 0xa2, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x5b, 0x70, 0x39, 0xef, 0xf7, 0x5f,
    0xff, 0xff, 0x75, 0xe9, 0x3e, 0xf7, 0x10, 0x0,
    0xef, 0x70, 0x0, 0xe, 0xf7, 0x0, 0x0, 0xef,
    0x70, 0x0, 0xe, 0xf7, 0x0, 0x0, 0xef, 0x70,
    0x0, 0xe, 0xf7, 0x0, 0x0, 0xef, 0x70, 0x0,
    0xe, 0xf7, 0x0, 0x0, 0xef, 0x70, 0x0, 0xe,
    0xf7, 0x0, 0x0, 0xef, 0x70,

    /* U+0032 "2" */
    0x0, 0x18, 0xdf, 0xea, 0x30, 0x0, 0x1e, 0xff,
    0xff, 0xff, 0x30, 0xb, 0xfe, 0x30, 0x3e, 0xfc,
    0x0, 0xff, 0x60, 0x0, 0x7f, 0xf0, 0x1b, 0xb2,
    0x0, 0x5, 0xff, 0x0, 0x0, 0x0, 0x0, 0x8f,
    0xc0, 0x0, 0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0,
    0x0, 0xd, 0xfc, 0x0, 0x0, 0x0, 0xb, 0xfe,
    0x20, 0x0, 0x0, 0x9, 0xff, 0x30, 0x0, 0x0,
    0x7, 0xff, 0x50, 0x0, 0x0, 0x5, 0xff, 0x60,
    0x0, 0x0, 0x3, 0xff, 0x80, 0x0, 0x0, 0x0,
    0xef, 0xff, 0xff, 0xff, 0xf9, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xa0,

    /* U+0033 "3" */
    0x0, 0x2a, 0xef, 0xea, 0x20, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0x30, 0xc, 0xfd, 0x20, 0x2d, 0xfb,
    0x0, 0xdd, 0x50, 0x0, 0x7f, 0xf0, 0x0, 0x0,
    0x0, 0x7, 0xfe, 0x0, 0x0, 0x0, 0x3, 0xef,
    0x80, 0x0, 0x2, 0xef, 0xff, 0x90, 0x0, 0x0,
    0x3f, 0xff, 0xfa, 0x0, 0x0, 0x0, 0x0, 0x4e,
    0xfa, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xf0, 0x4,
    0x40, 0x0, 0x3, 0xff, 0x22, 0xff, 0x40, 0x0,
    0x5f, 0xf1, 0xd, 0xfd, 0x20, 0x2d, 0xfc, 0x0,
    0x4f, 0xff, 0xff, 0xff, 0x30, 0x0, 0x2a, 0xef,
    0xea, 0x20, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0xaf, 0xf1, 0x0, 0x0, 0x0,
    0x3f, 0xff, 0x10, 0x0, 0x0, 0xc, 0xff, 0xf1,
    0x0, 0x0, 0x6, 0xff, 0xff, 0x10, 0x0, 0x1,
    0xef, 0x7f, 0xf1, 0x0, 0x0, 0x9f, 0x94, 0xff,
    0x10, 0x0, 0x2f, 0xe1, 0x4f, 0xf1, 0x0, 0xb,
    0xf7, 0x4, 0xff, 0x10, 0x5, 0xfd, 0x0, 0x4f,
    0xf1, 0x0, 0xef, 0x40, 0x4, 0xff, 0x10, 0x6f,
    0xff, 0xff, 0xff, 0xff, 0xd6, 0xff, 0xff, 0xff,
    0xff, 0xfc, 0x0, 0x0, 0x0, 0x4f, 0xf1, 0x0,
    0x0, 0x0, 0x4, 0xff, 0x10, 0x0, 0x0, 0x0,
    0x4f, 0xf1, 0x0,

    /* U+0035 "5" */
    0x9, 0xff, 0xff, 0xff, 0xf1, 0xb, 0xff, 0xff,
    0xff, 0xf1, 0xc, 0xf7, 0x11, 0x11, 0x10, 0xe,
    0xf4, 0x0, 0x0, 0x0, 0xf, 0xf2, 0x0, 0x0,
    0x0, 0x1f, 0xf9, 0xdf, 0xc6, 0x0, 0x3f, 0xff,
    0xff, 0xff, 0x70, 0x19, 0xc4, 0x2, 0xcf, 0xf1,
    0x0, 0x0, 0x0, 0x2f, 0xf6, 0x0, 0x0, 0x0,
    0xe, 0xf8, 0x23, 0x10, 0x0, 0xe, 0xf8, 0xaf,
    0xc0, 0x0, 0x1f, 0xf6, 0x4f, 0xf6, 0x1, 0xbf,
    0xf1, 0xa, 0xff, 0xff, 0xff, 0x60, 0x0, 0x6c,
    0xff, 0xc4, 0x0,

    /* U+0036 "6" */
    0x0, 0x1, 0x8d, 0xf7, 0x0, 0x0, 0x5f, 0xff,
    0xf7, 0x0, 0x3, 0xff, 0xb4, 0x10, 0x0, 0xd,
    0xfb, 0x0, 0x0, 0x0, 0x4f, 0xf1, 0x0, 0x0,
    0x0, 0x8f, 0xc7, 0xdf, 0xd6, 0x0, 0xbf, 0xff,
    0xff, 0xff, 0x70, 0xdf, 0xf8, 0x12, 0xcf, 0xf1,
    0xdf, 0xa0, 0x0, 0x2f, 0xf5, 0xdf, 0x80, 0x0,
    0xe, 0xf7, 0xbf, 0xa0, 0x0, 0xd, 0xf7, 0x7f,
    0xe0, 0x0, 0x1f, 0xf5, 0x1f, 0xf9, 0x1, 0xbf,
    0xe0, 0x6, 0xff, 0xff, 0xff, 0x50, 0x0, 0x4c,
    0xff, 0xb3, 0x0,

    /* U+0037 "7" */
    0x5f, 0xff, 0xff, 0xff, 0xff, 0x85, 0xff, 0xff,
    0xff, 0xff, 0xf7, 0x0, 0x0, 0x0, 0x3, 0xff,
    0x10, 0x0, 0x0, 0x0, 0xaf, 0xa0, 0x0, 0x0,
    0x0, 0x1f, 0xf3, 0x0, 0x0, 0x0, 0x8, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x60, 0x0, 0x0,
    0x0, 0x6f, 0xe0, 0x0, 0x0, 0x0, 0xd, 0xf8,
    0x0, 0x0, 0x0, 0x4, 0xff, 0x20, 0x0, 0x0,
    0x0, 0xaf, 0xb0, 0x0, 0x0, 0x0, 0x2f, 0xf4,
    0x0, 0x0, 0x0, 0x8, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x70, 0x0, 0x0, 0x0, 0x6f, 0xf1,
    0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x8d, 0xfe, 0xb3, 0x0, 0xd, 0xff, 0xff,
    0xff, 0x30, 0x6f, 0xf5, 0x2, 0xef, 0xc0, 0x9f,
    0xc0, 0x0, 0x6f, 0xf0, 0x9f, 0xc0, 0x0, 0x6f,
    0xe0, 0x3f, 0xf5, 0x2, 0xdf, 0x90, 0x6, 0xff,
    0xff, 0xfa, 0x0, 0x6, 0xff, 0xff, 0xfa, 0x0,
    0x5f, 0xf5, 0x3, 0xdf, 0xa0, 0xcf, 0x90, 0x0,
    0x4f, 0xf2, 0xff, 0x60, 0x0, 0x1f, 0xf4, 0xef,
    0x90, 0x0, 0x3f, 0xf3, 0x9f, 0xf4, 0x1, 0xcf,
    0xe0, 0x1e, 0xff, 0xff, 0xff, 0x50, 0x1, 0x9e,
    0xfe, 0xb3, 0x0,

    /* U+0039 "9" */
    0x0, 0x8, 0xdf, 0xd8, 0x0, 0x0, 0xc, 0xff,
    0xff, 0xfb, 0x0, 0x7, 0xff, 0x50, 0x5f, 0xf6,
    0x0, 0xdf, 0x80, 0x0, 0x9f, 0xc0, 0xf, 0xf5,
    0x0, 0x4, 0xff, 0x1, 0xff, 0x40, 0x0, 0x3f,
    0xf2, 0xf, 0xf8, 0x0, 0x4, 0xff, 0x20, 0xaf,
    0xe3, 0x2, 0xdf, 0xf2, 0x2, 0xef, 0xff, 0xff,
    0xff, 0x10, 0x2, 0xbf, 0xfa, 0x6f, 0xe0, 0x0,
    0x0, 0x0, 0x9, 0xfa, 0x0, 0x0, 0x0, 0x2,
    0xff, 0x40, 0x0, 0x0, 0x16, 0xef, 0xb0, 0x0,
    0x0, 0xff, 0xff, 0xb0, 0x0, 0x0, 0xf, 0xeb,
    0x50, 0x0, 0x0,

    /* U+0043 "C" */
    0x0, 0x7, 0xdf, 0xfc, 0x60, 0x0, 0x2, 0xdf,
    0xff, 0xff, 0xfb, 0x0, 0xc, 0xfe, 0x51, 0x27,
    0xff, 0x80, 0x5f, 0xf3, 0x0, 0x0, 0x9f, 0xf0,
    0xaf, 0xc0, 0x0, 0x0, 0x4f, 0xf3, 0xdf, 0x90,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x80, 0x0, 0x0,
    0x0, 0x0, 0xff, 0x70, 0x0, 0x0, 0x0, 0x0,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0xdf, 0x90,
    0x0, 0x0, 0x0, 0x0, 0xbf, 0xc0, 0x0, 0x0,
    0x4f, 0xf3, 0x5f, 0xf3, 0x0, 0x0, 0x9f, 0xf0,
    0xd, 0xfe, 0x41, 0x27, 0xff, 0x80, 0x2, 0xef,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0x18, 0xdf, 0xfc,
    0x60, 0x0,

    /* U+0046 "F" */
    0x8f, 0xff, 0xff, 0xff, 0xf7, 0x8f, 0xff, 0xff,
    0xff, 0xf7, 0x8f, 0xe0, 0x0, 0x0, 0x0, 0x8f,
    0xe0, 0x0, 0x0, 0x0, 0x8f, 0xe0, 0x0, 0x0,
    0x0, 0x8f, 0xe0, 0x0, 0x0, 0x0, 0x8f, 0xe0,
    0x0, 0x0, 0x0, 0x8f, 0xff, 0xff, 0xff, 0xa0,
    0x8f, 0xff, 0xff, 0xff, 0xa0, 0x8f, 0xe0, 0x0,
    0x0, 0x0, 0x8f, 0xe0, 0x0, 0x0, 0x0, 0x8f,
    0xe0, 0x0, 0x0, 0x0, 0x8f, 0xe0, 0x0, 0x0,
    0x0, 0x8f, 0xe0, 0x0, 0x0, 0x0, 0x8f, 0xe0,
    0x0, 0x0, 0x0,

    /* U+00B0 "°" */
    0x0, 0x0, 0x0, 0xa, 0xff, 0x50, 0x7f, 0x69,
    0xf1, 0xba, 0x0, 0xf4, 0x9e, 0x36, 0xf2, 0x1d,
    0xff, 0x80, 0x0, 0x32, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 80, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 235, .box_w = 14, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 105, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 111, .adv_w = 89, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 182, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 182, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 182, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 182, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 182, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 494, .adv_w = 182, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 182, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 644, .adv_w = 182, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 182, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 802, .adv_w = 182, .box_w = 11, .box_h = 15, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 885, .adv_w = 209, .box_w = 12, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 975, .adv_w = 176, .box_w = 10, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1050, .adv_w = 122, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 9}
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
    -43
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
const lv_font_t font_numbers_medium = {
#else
lv_font_t font_numbers_medium = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FONT_NUMBERS_MEDIUM*/

