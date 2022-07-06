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

lv_obj_t* makeBigNumberLabel(lv_obj_t* parent, uint16_t width, uint16_t height);

}
