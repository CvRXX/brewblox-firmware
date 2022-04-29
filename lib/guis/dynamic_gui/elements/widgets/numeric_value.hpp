/*
 * Copyright 2020 BrewPi B.V./Elco Jacobs.
 *
 * This file is part of Brewblox.
 *
 * Brewblox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewblox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Brewblox.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "dynamic_gui/elements/core/color.hpp"
#include "dynamic_gui/elements/widgets/widget.hpp"
#include "dynamic_gui/fonts/fonts.hpp"
#include "lvgl.h"
#include <iostream>

namespace gui::dynamic_interface {

/**
 * A widget which can display a numeric value.
 */
class NumericValue : public Widget {
public:
    /**
     * Constructs a numeric value.
     * @param value The value to be displayed.
     * @param label The label to be displayed.
     * @param color The background color of the widget.
     */
    NumericValue(uint8_t value, const char* label, Color color, uint16_t weight)
        : Widget(color, weight)
        , value(value)
        , label(label)
    {
    }

    NumericValue(NumericValue&& numericValue) = default;

    void update() override
    {
    }

    /**
     * Draws the numericvalue widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param with The with of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t with, uint16_t height) override
    {
        Widget::draw(placeholder, with, height);
        valueLabel.reset(lv_label_create(contentArea.get()));

        if (with > 120) {
            lv_obj_add_style(valueLabel.get(), &style::number_huge, LV_PART_MAIN);
        } else if (with > 50) {
            lv_obj_add_style(valueLabel.get(), &style::number_large, LV_PART_MAIN);
        }

        lv_label_set_text(valueLabel.get(), std::to_string(value).c_str());
        lv_obj_align(valueLabel.get(), LV_ALIGN_CENTER, 0, 0);

        LabelLabel.reset(lv_label_create(contentArea.get()));
        lv_obj_add_style(LabelLabel.get(), &style::widget_name, LV_PART_MAIN);
        lv_label_set_text(LabelLabel.get(), label.c_str());
        lv_obj_align(LabelLabel.get(), LV_ALIGN_BOTTOM_MID, 0, 0);
    }

private:
    LvglObjectWrapper valueLabel;
    LvglObjectWrapper LabelLabel;
    std::string label;
    uint8_t value;
};
}
