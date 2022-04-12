#pragma once

#include "lvgl.h"

namespace style {

extern lv_style_t bar;
extern lv_style_t grid;
extern lv_style_t maincontainer;
extern lv_style_t block;
extern lv_style_t block_disabled;
extern lv_style_t bg_dark;
extern lv_style_t bg_light;
extern lv_style_t widget_name;
extern lv_style_t number_large;
extern lv_style_t number_huge;
extern lv_style_t number_medium;
extern lv_style_t field_label;

void init();
}
