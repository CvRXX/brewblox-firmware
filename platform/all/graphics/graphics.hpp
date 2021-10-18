#pragma once
#include <array>
#include <lvgl.h>
#include <memory>

namespace cbox {
class Box;
}

class TFT035;
class FT6236;
class Layout;
class Bar;
class BaseWidget;

/// Represents the graphics for the TFT screen of the Spark 4.
class Graphics {
public:
    /**
    * This function will be called by lvgl to write pixels to the screen. 
    * @param disp_drv A pointer to the display driver as saved by lvgl.
    * @param area The area of pixels to be written.
    * @param color_p A pointer to the beginning of the pixels to be written.
    */
    static void monitor_flush(lv_disp_drv_t* disp_drv, const lv_area_t* area, lv_color_t* color_p);

    /**
     * Initialises the graphics module. 
     * @param box The Cbox box.
     */
    static void init(cbox::Box& box);

    /** 
     * Updates the layout and calls the lvgl task handler.
     */
    static void update();

    /**
     * Indicates to lvlg that a certain amount of time has elapsed.
     * @param millisElapsed amount of time that has elapsed since the last call in ms.
     */
    static void tick(uint32_t millisElapsed);

private:
    static void checkForTouches();
    static lv_disp_drv_t disp_drv;
    static std::unique_ptr<TFT035> display;
    static std::unique_ptr<FT6236> touchscreen;
    static std::unique_ptr<Layout> layout;
};
