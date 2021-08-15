#pragma once
#include <lvgl.h>
#include <memory>
#include <vector>

namespace cbox {
class Box;
}

class TFT035;
class Layout;
class Bar;
class BaseWidget;

/// Represents the graphics for the pyschical screen of the brewblox system.
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
    static lv_disp_drv_t disp_drv;
    static std::unique_ptr<TFT035> display;
    static std::unique_ptr<Layout> layout;
};

/// A structure that holds the layout of the screen and it's children.
class Layout {
public:
    /**
     * Constructs the layout.
     * @param box The Cbox box.
     */
    Layout(cbox::Box& box);
    ~Layout();

    /** Updates the following:
     *   - Checks if a new config is available the layout will be redrawn based on the new config.
     *   - Updates alle the widgets with the latest information about the objects they represent.
     *   - Updates the status bar with the current ip and network status.
     *   - Updates the status bar with the latest time. 
     */
    void update();

    /// Updates alle the widgets with the latest information about the objects they represent.
    void updateWidgets();

    /// If a new config is available the layout will be redrawn based on the new config.
    void updateConfig();

    std::unique_ptr<Bar> bar;

private:
    cbox::Box& box;
    std::vector<std::unique_ptr<BaseWidget>> sensorWidgets;
    std::array<lv_obj_t*, 6> placeholders;
    lv_obj_t* mainContainer;
    lv_obj_t* grid;
};