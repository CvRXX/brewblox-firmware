#pragma once

#include "./BaseWidget.hpp"
#include "blox/SetpointSensorPairBlock.h"

/// A widget which represents an analog actuator.
class SetpointWidget : public BaseWidget {
public:
    /**
     * Constructs the widget
     * @param grid The grid placeholder in which the widget will be placed.
     * @param ptr A cboxPtr to the object the widget represents.
     * @param label The user set label of the object.
     * @param color The background color of the widget.
     */
    SetpointWidget(lv_obj_t* grid, cbox::CboxPtr<SetpointSensorPairBlock>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, label, color)
        , lookup(ptr)
    {
        value = lv_label_create(obj, nullptr);
        lv_obj_add_style(value, LV_LABEL_PART_MAIN, &style::number_large);
        lv_label_set_align(value, LV_LABEL_ALIGN_CENTER);

        setting = lv_label_create(obj, nullptr);
        lv_obj_add_style(setting, LV_LABEL_PART_MAIN, &style::number_medium);
        lv_label_set_align(setting, LV_LABEL_ALIGN_CENTER);
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
                setValue(temp_to_string(pair.value(), 2, tempUnit));
            } else {
                setValue("-");
            }
            if (pair.settingValid()) {
                setSetting(temp_to_string(pair.setting(), 2, tempUnit));
            } else {
                setValue("-");
            }
            return;
        }
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

    /**
     * Sets the setting of the widget.
     * @param txt The setting text.
     */
    void setSetting(const std::string& txt)
    {
        lv_label_set_text(setting, txt.c_str());
        lv_obj_align(setting, nullptr, LV_ALIGN_CENTER, 0, -40);
    }

private:
    cbox::CboxPtr<SetpointSensorPairBlock> lookup;
    lv_obj_t* value;
    lv_obj_t* setting;
};