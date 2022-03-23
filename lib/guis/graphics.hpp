#pragma once
#include <array>
#include "lvgl_screen.hpp"
#include <lvgl.h>
#include <memory>

/// Represents the graphics for the TFT screen of the Spark 4.
template <typename Display, typename Touchscreen, typename GUI>
class Graphics {
public:


    /**
     * Initialises the graphics module.
     * @param box The Cbox box.
     */
    static void init()
    {
        lv_init();
        LvglScreen<Display>::init();
        LvglScreen<Display>::display->aquire_spi();

        static lv_disp_t* disp;
        disp = lv_disp_drv_register(&(LvglScreen<Display>::disp_drv));
        lv_disp_set_bg_color(disp, lv_color_black());


        static lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);

        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = checkForTouches;
        touchscreen = std::make_unique<Touchscreen>(0x00);
        touchscreen->init();
        lv_indev_drv_register(&indev_drv);

        gui = std::make_unique<GUI>();
        LvglScreen<Display>::display->release_spi();
    }

    /**
     * Updates the gui and calls the lvgl task handler.
     */
    static void update()
    {
        gui->update();
        LvglScreen<Display>::display->aquire_spi();
        lv_task_handler();
        LvglScreen<Display>::display->release_spi();
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
    static std::unique_ptr<Touchscreen> touchscreen;
    static std::unique_ptr<GUI> gui;
};




template <typename Display, typename Touchscreen, typename GUI>
std::unique_ptr<Touchscreen> Graphics<Display, Touchscreen, GUI>::touchscreen;

template <typename Display, typename Touchscreen, typename GUI>
std::unique_ptr<GUI> Graphics<Display, Touchscreen, GUI>::gui;


