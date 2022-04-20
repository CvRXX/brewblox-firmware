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

#include <lvgl.h>

template <typename Touchscreen>
class LvglTouchscreen {
public:
    static void checkForTouches(lv_indev_drv_t* drv, lv_indev_data_t* data)
    {
        if (auto touch = touchscreen->getTouch()) {
            data->point.x = touch->x;
            data->point.y = touch->y;
            data->state = LV_INDEV_STATE_PR;
        } else {
            auto lastTouch = touchscreen->getLastTouch();
            data->point.x = lastTouch.x;
            data->point.y = lastTouch.y;
            data->state = LV_INDEV_STATE_REL;
        }
    }

    static lv_indev_drv_t* init()
    {
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = checkForTouches;
        touchscreen = std::make_unique<Touchscreen>(0x00);
        touchscreen->init();
        return &indev_drv;
    }
    static lv_indev_drv_t indev_drv;
    static std::unique_ptr<Touchscreen> touchscreen;

private:
};
template <typename Touchscreen>
std::unique_ptr<Touchscreen> LvglTouchscreen<Touchscreen>::touchscreen;

template <typename Touchscreen>
lv_indev_drv_t LvglTouchscreen<Touchscreen>::indev_drv;
