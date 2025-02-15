#pragma once

#include "../styles.hpp"
#include "./BaseWidget.hpp"
#include "lvgl.h"

/// A widget which represents an temperature.
class TemperatureWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The name printed at the bottom of the widget.
     * @param color The background color of the widget.
     */
    TemperatureWidget(lv_obj_t* grid, uint8_t row, uint8_t col, cbox::CboxPtr<TempSensor>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, row, col, label, color)
        , lookup(std::move(ptr))
        , value(lv_label_create(obj))
    {
        lv_obj_add_style(value, &style::number_large, LV_PART_MAIN);
    }

    TemperatureWidget(const TemperatureWidget&) = delete;
    TemperatureWidget& operator=(const TemperatureWidget&) = delete;

    virtual ~TemperatureWidget()
    {
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.lock()) {
            if (ptr->valid()) {
                auto str = temp_to_string(ptr->value(), 1, tempUnit);
                str.append(tempUnit == TempUnit::Fahrenheit ? "°F" : "°C");
                lv_label_set_text(value, str.c_str());
            } else {
                lv_label_set_text(value, "-");
            }
            lv_obj_align(value, LV_ALIGN_CENTER, 0, -10);
            return;
        }
    }

private:
    cbox::CboxPtr<TempSensor> lookup;
    lv_obj_t* value;
};
