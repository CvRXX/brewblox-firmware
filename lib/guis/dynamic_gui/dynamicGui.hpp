#pragma once
#include <array>
#include <lvgl.h>
#include <memory>

/// A structure that holds the layout of the screen and its children.
class DynamicGui {
public:
    /**
     * Constructs the layout.
     * @param box The Cbox box.
     */
    DynamicGui()
    {
    }
    ~DynamicGui()
    {
    }

    /** Updates the following:
     *   - Checks if a new config is available the layout will be redrawn based on the new config.
     *   - Updates alle the widgets with the latest information about the objects they represent.
     *   - Updates the status bar with the current ip and network status.
     *   - Updates the status bar with the latest time.
     */
    void update()
    {
        if (toggler) {
            lv_obj_set_style_bg_color(lv_scr_act(), lv_color_black(), LV_STATE_DEFAULT);
            toggler = false;
        } else {
            lv_obj_set_style_bg_color(lv_scr_act(), lv_color_white(), LV_STATE_DEFAULT);
            toggler = true;
        }
    }

private:
    bool toggler = false;
};
