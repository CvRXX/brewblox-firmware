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
        mutex.lock();
        lv_init();
        auto displayDriver = LvglScreen<Display>::init();
        LvglScreen<Display>::display->aquire_spi();

        static lv_disp_t* disp;
        disp = lv_disp_drv_register(displayDriver);
        lv_disp_set_bg_color(disp, lv_color_black());

        auto touchScreenDriver = LvglTouchscreen<Touchscreen>::init();
        lv_indev_drv_register(touchScreenDriver);

        interface = std::make_unique<Interface>();
        LvglScreen<Display>::display->release_spi();
        mutex.unlock();
    }

    /**
     * Updates the gui and calls the lvgl task handler.
     */
    static void update()
    {
        if (mutex.try_lock()) {
            interface->update();
            LvglScreen<Display>::display->aquire_spi();
            lv_task_handler();
            LvglScreen<Display>::display->release_spi();
            mutex.unlock();
        }
    }

    /**
     * Indicates to lvlg that a certain amount of time has elapsed.
     * @param millisElapsed amount of time that has elapsed since the last call in ms.
     */
    static void tick(uint32_t millisElapsed)
    {
        lv_tick_inc(millisElapsed);
    }

private:
    static std::unique_ptr<Interface> interface;
    static std::mutex mutex;
};

template <typename Display, typename Touchscreen, typename Interface>
std::unique_ptr<Interface> Gui<Display, Touchscreen, Interface>::interface;

template <typename Display, typename Touchscreen, typename Interface>
std::mutex Gui<Display, Touchscreen, Interface>::mutex;
