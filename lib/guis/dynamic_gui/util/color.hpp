/*
 * Copyright 2020 BrewPi B.V./Elco Jacobs.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "lvgl.h"
namespace gui::dynamic_interface {

// A represenation for colors with conversion option to an lvgl color.
struct Color {
    constexpr Color(uint8_t r, uint8_t g, uint8_t b)
        : r(r)
        , g(g)
        , b(b)
    {
    }

    // Returns a lvgl color.
    operator lv_color_t() const
    {
        return lv_color_make(r, g, b);
    }
    const uint8_t r;
    const uint8_t g;
    const uint8_t b;
};

}
