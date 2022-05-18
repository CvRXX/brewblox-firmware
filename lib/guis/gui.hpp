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
#include "lvgl_screen.hpp"
#include "lvgl_touchscreen.hpp"
#include <array>
#include <lvgl.h>
#include <memory>
#include <mutex>

/// Represents the graphics for the TFT screen of the Spark 4.
template <typename Display, typename Touchscreen, typename Interface>
class Gui {
public:
    /**
     * Initialises the graphics module.
     * @param box The Cbox box.
     */
    static void init()
    {
        lv_init();

        displayDriver = lv_disp_drv_register(LvglScreen<Display>::init());
        lv_disp_set_bg_color(displayDriver, lv_color_black());

        touchScreenDriver = lv_indev_drv_register(LvglTouchscreen<Touchscreen>::init());

        interface = std::make_unique<Interface>();
    }

    /**
     * Updates the gui and calls the lvgl task handler.
     */
    static void update()
    {
        interface->update();
        auto displayLock = std::lock_guard(*LvglScreen<Display>::display);
        lv_task_handler();
    }

    /**
     * Indicates to lvlg that a certain amount of time has elapsed.
     * @param millisElapsed amount of time that has elapsed since the last call in ms.
     */
    static void tick(uint32_t millisElapsed)
    {
        lv_tick_inc(millisElapsed);
    }
    static std::unique_ptr<Interface> interface;

private:
    static lv_disp_t* displayDriver;
    static lv_indev_t* touchScreenDriver;
};

template <typename Display, typename Touchscreen, typename Interface>
std::unique_ptr<Interface> Gui<Display, Touchscreen, Interface>::interface;

template <typename Display, typename Touchscreen, typename Interface>
lv_disp_t* Gui<Display, Touchscreen, Interface>::displayDriver;

template <typename Display, typename Touchscreen, typename Interface>
lv_indev_t* Gui<Display, Touchscreen, Interface>::touchScreenDriver;
