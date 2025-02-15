#pragma once
#include "dynamic_gui/fonts/fonts.hpp"
#include "dynamic_gui/styles/styles.hpp"

namespace gui::dynamic_interface::sizing {

// The number of chars that a number can consist of.
// This includes the decimal separator.
constexpr uint16_t numbersNChars = 3;

// The margin in px to apply to the numbers
constexpr uint16_t numbersMargin = 10;

constexpr uint16_t hugeBreakPointWidth = fonts::numbers_huge_width * numbersNChars + numbersMargin;
constexpr uint16_t hugeBreakPointHeight = fonts::numbers_huge_height + numbersMargin;

constexpr uint16_t largeBreakPointWidth = fonts::numbers_large_width * numbersNChars + numbersMargin;
constexpr uint16_t largeBreakPointHeight = fonts::numbers_large_height + numbersMargin;

constexpr uint16_t mediumBreakPointWidth = fonts::numbers_medium_width * numbersNChars + numbersMargin;
constexpr uint16_t mediumBreakPointHeight = fonts::numbers_medium_height + numbersMargin;

constexpr uint16_t smallBreakPointWidth = fonts::numbers_small_width * numbersNChars + numbersMargin;
constexpr uint16_t smallBreakPointHeight = fonts::numbers_small_height + numbersMargin;

// The length of the label that should fit.
constexpr uint16_t labelNChars = 10;
constexpr uint16_t labelBreakingPointWidth = fonts::main_small_width * labelNChars + 10;
constexpr uint16_t labelBreakingPointHeight = hugeBreakPointHeight;

// Returns true if there is space for a label.
constexpr bool spaceForNameLabel(uint16_t width, uint16_t height)
{
    return (width > labelBreakingPointWidth) && (height > labelBreakingPointHeight);
}

lv_obj_t* makeBigNumberLabel(lv_obj_t* parent, uint16_t width, uint16_t height)
{
    auto label = lv_label_create(parent);
    if ((width > hugeBreakPointWidth) && (height > hugeBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_huge, LV_PART_MAIN);
    } else if ((width > largeBreakPointWidth) && (height > largeBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_large, LV_PART_MAIN);
    } else if ((width > mediumBreakPointWidth) && (height > mediumBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_medium, LV_PART_MAIN);
    } else if ((width > smallBreakPointWidth) && (height > smallBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_small, LV_PART_MAIN);
    } else {
        lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
    }
    return label;
}
}
