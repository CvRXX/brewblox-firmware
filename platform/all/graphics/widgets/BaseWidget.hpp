#pragma once
#include "../fonts/fonts.hpp"
#include "../styles.hpp"
#include "Temperature.h"
#include "lvgl.h"

class BaseWidget {
public:
    BaseWidget(lv_obj_t* grid, lv_color_t color);
    virtual ~BaseWidget() = default;

    BaseWidget(const BaseWidget&) = delete;
    BaseWidget& operator=(const BaseWidget&) = delete;

    /// Returns the luminance of the background color.
    uint8_t getLuminance();

    /// Returns the redness of the background color.
    uint8_t getRed();

    virtual void update() = 0;
    static TempUnit tempUnit;

protected:
    lv_obj_t* obj;
    lv_obj_t* grid;
    lv_color_t textColor;
};