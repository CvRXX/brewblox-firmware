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

#include "pixel_format.hpp"
#include <lvgl.h>
#include <utility>

template <typename Display>
class LvglScreen {
public:
    static void monitor_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p)
    {
        auto nPixels = (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1);
        if (!nPixels) {
            // Log here when a better debug log is available.
        }

        if constexpr (Display::pixelformat == PixelFormat::rgb888) {
            uint8_t* readPtr = reinterpret_cast<uint8_t*>(color_p);
            uint8_t* writePtr = reinterpret_cast<uint8_t*>(color_p);

            std::swap(*(writePtr + 2), *writePtr);
            readPtr += 4;
            writePtr += 3;
            for (auto index = 1; index < nPixels; index++) {
                *writePtr = *(readPtr + 2);
                *(writePtr + 1) = *(readPtr + 1);
                *(writePtr + 2) = *readPtr;

                readPtr += 4;
                writePtr += 3;
            }
        } else if constexpr (Display::pixelformat == PixelFormat::rgb565) {
            uint8_t* readPtr = reinterpret_cast<uint8_t*>(color_p);
            uint16_t* writePtr = reinterpret_cast<uint16_t*>(color_p);

            for (auto index = 0; index < nPixels; index++) {
                auto b = *readPtr;
                auto g = *(readPtr + 1);
                auto r = *(readPtr + 2);

                uint16_t Rgb565 = 0;
                Rgb565 = (r & 0b11111000) << 8;
                Rgb565 = Rgb565 + ((g & 0b11111100) << 3);
                Rgb565 = Rgb565 + ((b) >> 3);

                *writePtr = Rgb565;

                readPtr += 4;
                writePtr += 1;
            }
        }

        display->writePixels(area->x1, area->x2, area->y1, area->y2, reinterpret_cast<uint8_t*>(color_p), nPixels);
    }

    static lv_disp_drv_t* init()
    {
        display = std::make_unique<Display>([]() { lv_disp_flush_ready(&disp_drv); });
        auto displayLock = std::lock_guard(*display);
        display->init();

        lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, 960);

        lv_disp_drv_init(&disp_drv);

        disp_drv.draw_buf = &disp_buf1;
        disp_drv.flush_cb = monitor_flush;
        disp_drv.hor_res = display->horResolution;
        disp_drv.ver_res = display->verResolution;
        lv_disp_rot_t rotation;
        switch (display->rotation) {
        case 0:
            rotation = LV_DISP_ROT_NONE;
            break;
        case 90:
            rotation = LV_DISP_ROT_90;
            break;
        case 180:
            rotation = LV_DISP_ROT_180;
            break;
        case 270:
            rotation = LV_DISP_ROT_270;
            break;
        default:
            rotation = LV_DISP_ROT_NONE;
        }
        disp_drv.rotated = rotation;
        return &disp_drv;
    }
    static std::unique_ptr<Display> display;
    constexpr static auto bufferSize = Display::horResolution * 3;
    static lv_disp_draw_buf_t disp_buf1;
    static lv_color_t buf1_1[bufferSize];
    static lv_color_t buf1_2[bufferSize];
    static lv_disp_drv_t disp_drv;

private:
};
template <typename Display>
lv_disp_draw_buf_t LvglScreen<Display>::disp_buf1;

template <typename Display>
lv_color_t LvglScreen<Display>::buf1_1[LvglScreen<Display>::bufferSize];

template <typename Display>
lv_color_t LvglScreen<Display>::buf1_2[LvglScreen<Display>::bufferSize];

template <typename Display>

std::unique_ptr<Display> LvglScreen<Display>::display;

template <typename Display>
lv_disp_drv_t LvglScreen<Display>::disp_drv;
