#pragma once
#include <array>
#include <lvgl.h>
#include <memory>

namespace cbox {
class Box;
}

class TFT035;
class Layout;
class Bar;
class BaseWidget;

/// Represents the graphics for the TFT screen of the Spark 4.
class Graphics {
public:
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
    static lv_disp_drv_t disp_drv;
    static std::unique_ptr<TFT035> display;
    static std::unique_ptr<Layout> layout;
};
