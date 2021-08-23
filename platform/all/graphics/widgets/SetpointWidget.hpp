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
    SetpointWidget(lv_obj_t* grid, cbox::CboxPtr<SetpointSensorPairBlock>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, label, color)
        , lookup(ptr)
        , value(lv_label_create(obj, nullptr))
        , setting(lv_label_create(obj, nullptr))
    {
        lv_obj_add_style(value, LV_LABEL_PART_MAIN, &style::number_large);
        lv_obj_align(value, nullptr, LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_auto_realign(value, true);

        lv_obj_add_style(setting, LV_LABEL_PART_MAIN, &style::number_medium);
        lv_obj_align(setting, nullptr, LV_ALIGN_CENTER, 0, -40);
        lv_obj_set_auto_realign(setting, true);
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