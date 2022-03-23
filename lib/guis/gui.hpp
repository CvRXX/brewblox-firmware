#pragma once
#include <array>
#include "lvgl_screen.hpp"
#include "lvgl_touchscreen.hpp"
#include <lvgl.h>
#include <memory>

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
        LvglScreen<Display>::init();
        LvglScreen<Display>::display->aquire_spi();

        static lv_disp_t* disp;
        disp = lv_disp_drv_register(&(LvglScreen<Display>::disp_drv));
        lv_disp_set_bg_color(disp, lv_color_black());

        LvglTouchscreen<Touchscreen>::init();
        lv_indev_drv_register(&(LvglTouchscreen<Touchscreen>::indev_drv));

        interface = std::make_unique<Interface>();
        LvglScreen<Display>::display->release_spi();
    }

    /**
     * Updates the gui and calls the lvgl task handler.
     */
    static void update()
    {
        interface->update();
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
    static std::unique_ptr<Interface> interface;
};





template <typename Display, typename Touchscreen, typename Interface>
std::unique_ptr<Interface> Gui<Display, Touchscreen, Interface>::interface;


