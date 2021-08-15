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
        : BaseWidget(grid, color)
        , lookup(ptr)
    {
        makeObj(grid, label, "-", "-");
    }

    SetpointWidget(const SetpointWidget&) = delete;
    SetpointWidget& operator=(const SetpointWidget&) = delete;

    ~SetpointWidget()
    {
        lv_obj_del(obj);
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
    void makeObj(lv_obj_t* grid, const char* labelTxt, const char* valueTxt, const char* settingTxt)
    {
        label = lv_label_create(obj, nullptr);
        lv_obj_reset_style_list(label, LV_LABEL_PART_MAIN);
        lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style::block_text);
        lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
        setLabel(labelTxt);

        value = lv_label_create(obj, nullptr);
        setValue(valueTxt);
        lv_obj_reset_style_list(value, LV_LABEL_PART_MAIN);
        lv_obj_add_style(value, LV_LABEL_PART_MAIN, &style::bigNumber_text);
        lv_label_set_align(value, LV_LABEL_ALIGN_CENTER);

        setting = lv_label_create(obj, nullptr);
        setSetting(settingTxt);
        lv_obj_reset_style_list(setting, LV_LABEL_PART_MAIN);
        lv_obj_add_style(setting, LV_LABEL_PART_MAIN, &style::block_text);
        lv_label_set_align(setting, LV_LABEL_ALIGN_CENTER);

        lv_obj_set_style_local_text_color(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(value, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(setting, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
    }

    cbox::CboxPtr<SetpointSensorPairBlock> lookup;
    lv_obj_t* label;
    lv_obj_t* value;
    lv_obj_t* setting;
};