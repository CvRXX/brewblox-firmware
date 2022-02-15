#pragma once

#include "./BaseWidget.hpp"
#include "blox/SetpointSensorPairBlock.h"

/// A widget which represents an analog actuator.
class SetpointWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The user set label of the object.
     * @param color The background color of the widget.
     */
    SetpointWidget(lv_obj_t* grid, uint8_t row, uint8_t col, cbox::CboxPtr<SetpointSensorPairBlock>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, row, col, label, color)
        , lookup(ptr)
        , value(lv_label_create(obj))
        , setting(lv_label_create(obj))
    {
        lv_obj_add_style(value, &style::number_large, 0);
        lv_obj_align(value, LV_ALIGN_CENTER, 0, 0);

        lv_obj_add_style(setting, &style::number_medium, 0);
        lv_obj_align(setting, LV_ALIGN_CENTER, 0, -40);
    }

    virtual ~SetpointWidget()
    {
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.const_lock()) {
            auto& pair = ptr->get();

            if (pair.valueValid()) {
                auto str = temp_to_string(pair.value(), 1, tempUnit);
                str.append(tempUnit == TempUnit::Fahrenheit ? "°F" : "°C");
                lv_label_set_text(value, str.c_str());
            } else {
                lv_label_set_text(value, "-");
            }
            if (pair.settingValid()) {
                auto str = temp_to_string(pair.setting(), 1, tempUnit);
                lv_label_set_text(setting, str.c_str());
            } else {
                lv_label_set_text(setting, "-");
            }
            return;
        }
    }

private:
    cbox::CboxPtr<SetpointSensorPairBlock> lookup;
    lv_obj_t* value;
    lv_obj_t* setting;
};
