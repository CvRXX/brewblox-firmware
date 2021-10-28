#pragma once
#include "blox/DisplaySettingsBlock.h"
#include "cbox/Box.h"
#include "graphics.hpp"
#include "layout.hpp"
#include "lvgl.h"
#include <array>
#include <esp_log.h>
#include <lvgl.h>
#include <memory>

namespace cbox {
class Box;
}

class Layout;
class Bar;
class BaseWidget;

/// Represents the graphics for the TFT screen of the Spark 4.
template <typename Display>
class Graphics {
public:
    /**
     * Initialises the graphics module. 
     * @param box The Cbox box.
     */
    static void init(cbox::Box& box)
    {
        Display::init([](hal_spi::TransactionData& transaction) { lv_disp_flush_ready(&disp_drv); });
        lv_init();
        static lv_disp_buf_t disp_buf1;
        static lv_color_t buf1_1[960];
        static lv_color_t buf1_2[960];
        lv_disp_buf_init(&disp_buf1, buf1_1, buf1_2, 960);

        lv_disp_drv_init(&disp_drv);

        disp_drv.buffer = &disp_buf1;
        disp_drv.flush_cb = Display::monitor_flush;
        disp_drv.hor_res = Display::getHorResolution();
        disp_drv.ver_res = Display::getVerResolution();
        disp_drv.rotated = Display::getRotation();

        static lv_disp_t* disp;
        disp = lv_disp_drv_register(&disp_drv);
        lv_disp_set_bg_color(disp, LV_COLOR_BLACK);

        style::init();

        layout = move(std::make_unique<Layout>(box));
    }

    /** 
     * Updates the layout and calls the lvgl task handler.
     */
    static void update()
    {
        layout->update();
        Display::acquire();
        lv_task_handler();
        Display::release();
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
    static lv_disp_drv_t disp_drv;
    static std::unique_ptr<Layout> layout;
};

template <typename Display>
std::unique_ptr<Layout> Graphics<Display>::layout{};

template <typename Display>
lv_disp_drv_t Graphics<Display>::disp_drv{};