#pragma once
#include "lvgl_screen.hpp"
#include "lvgl_touchscreen.hpp"
#include <array>
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

        { // Display lock scope
            auto displayLock = std::lock_guard(*LvglScreen<Display>::display);
            auto displayDriver = LvglScreen<Display>::init();

            static lv_disp_t* disp;
            disp = lv_disp_drv_register(displayDriver);
            lv_disp_set_bg_color(disp, lv_color_black());
        }

        auto touchScreenDriver = LvglTouchscreen<Touchscreen>::init();
        lv_indev_drv_register(touchScreenDriver);

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

private:
    static std::unique_ptr<Interface> interface;
};

template <typename Display, typename Touchscreen, typename Interface>
std::unique_ptr<Interface> Gui<Display, Touchscreen, Interface>::interface;
