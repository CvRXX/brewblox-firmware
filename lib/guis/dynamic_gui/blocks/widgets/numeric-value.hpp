#include "dynamic_gui/blocks/core/color.hpp"
#include "dynamic_gui/blocks/widgets/widget.hpp"
#include "dynamic_gui/fonts/fonts.hpp"
#include "lvgl.h"
#include <iostream>

class NumericValue : public Widget {
public:
    NumericValue(uint8_t value, const char* label, Color color)
        : Widget(color)
        , value(value)
        , label(label)
    {
    }

    NumericValue(NumericValue&& numericValue) = default;

    void update() override
    {
        // if (lv_obj_get_width(contentArea) > 100) {
        //     lv_obj_add_style(valueLabel, &style::number_huge, LV_PART_MAIN);
        // }
    }

    void draw(lv_obj_t* placeholder, uint32_t with, uint32_t height) override
    {
        Widget::draw(placeholder, with, height);
        valueLabel.reset(lv_label_create(&contentArea));

        if (lv_obj_get_width(&contentArea) > 25) {
            lv_obj_add_style(&valueLabel, &style::number_huge, LV_PART_MAIN);
        }

        lv_label_set_text(&valueLabel, std::to_string(value).c_str());
        lv_obj_align(&valueLabel, LV_ALIGN_CENTER, 0, 0);

        LabelLabel.reset(lv_label_create(&contentArea));
        lv_obj_add_style(&LabelLabel, &style::widget_name, LV_PART_MAIN);
        lv_label_set_text(&LabelLabel, label.c_str());
        lv_obj_align(&LabelLabel, LV_ALIGN_BOTTOM_MID, 0, 0);
    }

    LvglObjectWrapper valueLabel = nullptr;
    LvglObjectWrapper LabelLabel = nullptr;
    std::string label;
    uint8_t value;
};
