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
#include <memory>

struct LvglDeleter {
 void operator()(lv_obj_t* lvglObject) {
     lv_obj_del(lvglObject);
 }
};

// A wrapper type which wraps an lv_obj_t in a std::unique_ptr which calls the lvgl deleter.
using LvglObjectWrapper = std::unique_ptr<lv_obj_t, LvglDeleter>;


