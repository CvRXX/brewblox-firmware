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
     * @param label The user set label of the object.
     * @param color The background color of the widget.
     */
    TemperatureWidget(lv_obj_t* grid, cbox::CboxPtr<TempSensor>&& ptr, const char* label, lv_color_t color)
        : BaseWidget(grid, color)
        , lookup(ptr)
    {
        makeObj(grid, label, "-");
    }

    TemperatureWidget(const TemperatureWidget&) = delete;
    TemperatureWidget& operator=(const TemperatureWidget&) = delete;

    ~TemperatureWidget()
    {
        lv_obj_del(obj);
    }

    /// Updates the widget with information from the object it's representing.
    void update()
    {
        if (auto ptr = lookup.const_lock()) {
            if (ptr->valid()) {
                setValue(temp_to_string(ptr->value(), 2, tempUnit));
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
    void makeObj(lv_obj_t* grid, const char* labelTxt, const char* valueTxt)
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

        lv_obj_set_style_local_text_color(value, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
        lv_obj_set_style_local_text_color(label, LV_LABEL_PART_MAIN, LV_STATE_DEFAULT, textColor);
    }

    cbox::CboxPtr<TempSensor> lookup;
    lv_obj_t* label;
    lv_obj_t* value;
    TempUnit tempUnit;
};