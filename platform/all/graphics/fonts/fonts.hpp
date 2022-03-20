#pragma once

#include "lvgl.h"

extern "C" {
extern lv_font_t font_main;
extern lv_font_t font_main_small;
extern lv_font_t font_numbers_medium;
extern lv_font_t font_numbers_large;
}
// extern lv_font_t main_font_10;
// extern lv_font_t main_font_12;
// extern lv_font_t main_font_14;
// extern lv_font_t main_font_16;
// extern lv_font_t main_font_18;
// extern lv_font_t main_font_20;
// extern lv_font_t main_font_22;
// extern lv_font_t main_font_24;
// extern lv_font_t main_font_26;
// extern lv_font_t main_font_28;
// extern lv_font_t main_font_30;
// extern lv_font_t main_font_32;
// extern lv_font_t main_font_34;
// extern lv_font_t main_font_36;
// extern lv_font_t main_font_38;
// extern lv_font_t main_font_40;
// extern lv_font_t main_font_42;
// extern lv_font_t main_font_44;
// extern lv_font_t main_font_46;
// extern lv_font_t main_font_48;

namespace fonts {
static constexpr lv_font_t& main = ::font_main;
static constexpr lv_font_t& main_small = ::font_main_small;
static constexpr lv_font_t& numbers_medium = ::font_numbers_medium;
static constexpr lv_font_t& numbers_large = ::font_numbers_large;
static constexpr lv_font_t& widget_name = ::font_main;
// static constexpr lv_font_t& main_8 = main_font_8;
// static constexpr lv_font_t& main_10 = main_font_10;
// static constexpr lv_font_t& main_12 = main_font_12;
// static constexpr lv_font_t& main_14 = main_font_14;
// static constexpr lv_font_t& main_16 = main_font_16;
// static constexpr lv_font_t& main_18 = main_font_18;
// static constexpr lv_font_t& main_20 = main_font_20;
// static constexpr lv_font_t& main_22 = main_font_22;
// static constexpr lv_font_t& main_24 = main_font_24;
// static constexpr lv_font_t& main_26 = main_font_26;
// static constexpr lv_font_t& main_28 = main_font_28;
// static constexpr lv_font_t& main_30 = main_font_30;
// static constexpr lv_font_t& main_32 = main_font_32;
// static constexpr lv_font_t& main_34 = main_font_34;
// static constexpr lv_font_t& main_36 = main_font_36;
// static constexpr lv_font_t& main_38 = main_font_38;
// static constexpr lv_font_t& main_40 = main_font_40;
// static constexpr lv_font_t& main_42 = main_font_42;
// static constexpr lv_font_t& main_44 = main_font_44;
// static constexpr lv_font_t& main_46 = main_font_46;
// static constexpr lv_font_t& main_48 = main_font_48;
}
namespace symbols {
static constexpr auto wifi_strength1 = "\U000F091F";
static constexpr auto wifi_strength2 = "\U000F0922";
static constexpr auto wifi_strength3 = "\U000F0925";
static constexpr auto wifi_strength4 = "\U000F0928";
static constexpr auto wifi_off = "\U000F092E";
static constexpr auto wifi_cog = "\U000F16BE";
static constexpr auto ethernet = "\U000F0200";
static constexpr auto bluetooth = "\U000F00AF";
static constexpr auto arrow_thick_right = "\U000F0055";
}
