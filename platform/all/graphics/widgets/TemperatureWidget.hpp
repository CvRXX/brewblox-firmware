#pragma once

#include "../styles.hpp"
#include "./BaseWidget.hpp"
#include "lvgl.h"

/// A widget which represents an temperature.
class TemperatureWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid placeholder in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The name printed at the bottom of the widget.
     * @param color The background color of the widget.
     */
    TemperatureWidget(lv_obj_t* grid, cbox::CboxPtr<TempSensor>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, label, color)
        , lookup(ptr)
    {
        value = lv_label_create(obj, nullptr);
        lv_obj_add_style(value, LV_LABEL_PART_MAIN, &style::number_large);
        lv_label_set_align(value, LV_LABEL_ALIGN_CENTER);
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
                auto v = temp_to_string(ptr->value(), 1, tempUnit);
                v.append(tempUnit == TempUnit::Fahrenheit ? "°F" : "°C");
                setValue(v);
            } else {
                setValue("-");
            }
            return;
        }
    }

    /**
     * Sets the label of the widget.
     * @param txt The label text.
     */
    void setLabel(const std::string& txt)
    {
        lv_label_set_text(label, txt.c_str());
        lv_obj_align(label, nullptr, LV_ALIGN_CENTER, 0, 50);
    }

    /**
     * Sets the value of the widget.
     * @param txt The value text.
     */
    void setValue(const std::string& txt)
    {
        lv_label_set_text(value, txt.c_str());
        lv_obj_align(value, nullptr, LV_ALIGN_CENTER, 0, 0);
    }

private:
    cbox::CboxPtr<TempSensor> lookup;
    lv_obj_t* value;
};