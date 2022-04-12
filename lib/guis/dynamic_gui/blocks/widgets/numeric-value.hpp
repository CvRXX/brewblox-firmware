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

    NumericValue(NumericValue&& numericValue)
        : Widget(std::move(numericValue))
        , valueLabel(std::move(numericValue.valueLabel))
        , LabelLabel(std::move(numericValue.LabelLabel))
        , label(numericValue.label)
        , value(numericValue.value)

    {
    }

    void update() override
    {
        // if (lv_obj_get_width(contentArea.getPtr()) > 100) {
        //     lv_obj_add_style(valueLabel.getPtr(), &style::number_huge, LV_PART_MAIN);
        // }
    }

    void draw(lv_obj_t* placeholder) override
    {
        Widget::draw(placeholder);
        valueLabel.reset(lv_label_create(contentArea.getPtr()));

        if (lv_obj_get_width(contentArea.getPtr()) > 25) {
            lv_obj_add_style(valueLabel.getPtr(), &style::number_huge, LV_PART_MAIN);
        }

        lv_label_set_text(valueLabel.getPtr(), std::to_string(value).c_str());
        lv_obj_align(valueLabel.getPtr(), LV_ALIGN_CENTER, 0, 0);

        LabelLabel.reset(lv_label_create(contentArea.getPtr()));
        lv_obj_add_style(LabelLabel.getPtr(), &style::widget_name, LV_PART_MAIN);
        lv_label_set_text(LabelLabel.getPtr(), label.c_str());
        lv_obj_align(LabelLabel.getPtr(), LV_ALIGN_BOTTOM_MID, 0, 0);
    }

    LvglObjectWrapper valueLabel = nullptr;
    LvglObjectWrapper LabelLabel = nullptr;
    std::string label;
    uint8_t value;
};
