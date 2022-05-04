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
extern lv_style_t number_small;
extern lv_style_t field_label;

void init();
}
