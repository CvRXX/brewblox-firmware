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

/**
 * A wrapper class to add lifetime management to LVGL objects.
 */
class LvglObjectWrapper {
public:
    constexpr LvglObjectWrapper(lv_obj_t* lvglObject)
        : lvglObject(lvglObject)
    {
    }

    constexpr LvglObjectWrapper(LvglObjectWrapper&& lvglObjectWrapper)
        : lvglObject(lvglObjectWrapper.lvglObject)
    {
        lvglObjectWrapper.lvglObject = nullptr;
    }

    ~LvglObjectWrapper()
    {
        if (lvglObject) {
            lv_obj_del(lvglObject);
        }
    }

    lv_obj_t* operator->()
    {
        return lvglObject;
    }

    /**
     * Returns the raw internal pointer.
     * This is non owning
     */
    lv_obj_t* operator&()
    {
        return lvglObject;
    }

    /**
     * Destructs the current LVGL object and replaces it with the passed object.
     * @param newPtr A pointer to the object that should replace the current object.
     */
    void reset(lv_obj_t* newPtr)
    {
        if (lvglObject) {
            lv_obj_del(lvglObject);
        }
        lvglObject = newPtr;
    }

private:
    lv_obj_t* lvglObject;
};
