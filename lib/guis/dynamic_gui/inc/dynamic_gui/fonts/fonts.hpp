#pragma once

#include "lvgl.h"
extern "C" {
extern lv_font_t font_main;
extern lv_font_t font_main_small;
extern lv_font_t font_numbers_small;
extern lv_font_t font_numbers_medium;
extern lv_font_t font_numbers_large;
extern lv_font_t font_numbers_huge;
}
namespace gui::dynamic_interface {

namespace fonts {

    static constexpr lv_font_t& main = font_main;
    static constexpr uint16_t main_height = 16;
    static constexpr uint16_t main_width = main_height * 0.844;

    static constexpr lv_font_t& main_small = font_main_small;
    static constexpr uint16_t main_small_height = 12;
    static constexpr uint16_t main_small_width = main_small_height * 0.844;

    static constexpr lv_font_t& numbers_small = font_numbers_small;
    static constexpr uint16_t numbers_small_height = 10;
    static constexpr uint16_t numbers_small_width = numbers_small_height * 0.844;

    static constexpr lv_font_t& numbers_medium = font_numbers_medium;
    static constexpr uint16_t numbers_medium_height = 20;
    static constexpr uint16_t numbers_medium_width = numbers_medium_height * 0.844;

    static constexpr lv_font_t& numbers_large = font_numbers_large;
    static constexpr uint16_t numbers_large_height = 36;
    static constexpr uint16_t numbers_large_width = numbers_large_height * 0.844;

    static constexpr lv_font_t& numbers_huge = font_numbers_huge;
    static constexpr uint16_t numbers_huge_height = 80;
    static constexpr uint16_t numbers_huge_width = numbers_huge_height * 0.844;

    static constexpr lv_font_t& widget_name = font_main;
    static constexpr uint16_t widget_name_height = 16;
    static constexpr uint16_t widget_name_width = main_small_height * 0.844;

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
}
