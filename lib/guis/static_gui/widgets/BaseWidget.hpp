#pragma once
#include "control/Temperature.hpp"
#include "lvgl.h"
#include "static_gui/fonts/fonts.hpp"
#include "static_gui/styles.hpp"

class BaseWidget {
public:
    BaseWidget(lv_obj_t* grid, uint8_t row, uint8_t col, const char* labelText, lv_color_t color);
    virtual ~BaseWidget();

    BaseWidget(const BaseWidget&) = delete;
    BaseWidget& operator=(const BaseWidget&) = delete;

    /// Returns the luminance of the background color.
    uint8_t getLuminance();

    /// Returns the redness of the background color.
    uint8_t getRed();

    virtual void update(){};
    static TempUnit tempUnit;

protected:
    lv_obj_t* obj;

private:
    lv_obj_t* label;
    lv_color_t bg_color;
};
