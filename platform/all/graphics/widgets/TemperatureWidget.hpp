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
    TemperatureWidget(lv_obj_t* grid, cbox::CboxPtr<TempSensor>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, label, color)
        , lookup(ptr)
        , value(lv_label_create(obj, nullptr))
    {
        lv_obj_add_style(value, LV_LABEL_PART_MAIN, &style::number_large);
        lv_obj_set_auto_realign(value, true);
    }

    TemperatureWidget(const TemperatureWidget&) = delete;
    TemperatureWidget& operator=(const TemperatureWidget&) = delete;

    virtual ~TemperatureWidget()
    {
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.const_lock()) {
            if (ptr->valid()) {
                auto str = temp_to_string(ptr->value(), 1, tempUnit);
                str.append(tempUnit == TempUnit::Fahrenheit ? "°F" : "°C");
                lv_label_set_text(value, str.c_str());
            } else {
                lv_label_set_text(value, "-");
            }
            return;
        }
    }

private:
    cbox::CboxPtr<TempSensor> lookup;
    lv_obj_t* value;
};