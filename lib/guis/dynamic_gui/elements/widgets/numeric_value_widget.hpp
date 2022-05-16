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
#include "dynamic_gui/elements/widgets/color_widget.hpp"
#include "dynamic_gui/fonts/fonts.hpp"
#include "dynamic_gui/styles/sizing.hpp"
#include "proto/ScreenConfig.pb.h"

#include "lvgl.h"
#include <iostream>
#include <vector>

namespace gui::dynamic_interface {

/**
 * A widget which can display a numeric value.
 */
class NumericValueWidget : public ColorWidget {
public:
    /**
     * Constructs a numeric value.
     * @param value The value to be displayed.
     * @param label The label to be displayed.
     * @param color The background color of the widget.
     */
    NumericValueWidget(blox_ScreenConfig_NumericValueWidget& numericValueWidget)
        : ColorWidget({numericValueWidget.color.r, numericValueWidget.color.g, numericValueWidget.color.b})
        , settings(numericValueWidget)
    {
    }

    bool serialise(std::vector<blox_ScreenConfig_ContentNode>& contentnodes, uint8_t layOutNodeId) override final
    {
        contentnodes.push_back({layOutNodeId, blox_ScreenConfig_ContentNode_numericValueWidget_tag, settings});
        return true;
    }

    void update() override final
    {
    }

    /**
     * Draws the numericvalue widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param with The with of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t with, uint16_t height) override final
    {
        ColorWidget::draw(placeholder, with, height);
        valueLabel.reset(sizing::bigNumber(contentArea.get(), with, height));

        lv_label_set_text(valueLabel.get(), std::to_string(settings.value).c_str());
        lv_obj_align(valueLabel.get(), LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_pad_all(valueLabel.get(), 0, 0);

        if (sizing::toDrawLabel(with, height)) {
            LabelLabel.reset(lv_label_create(contentArea.get()));
            lv_obj_add_style(LabelLabel.get(), &style::widget_name, LV_PART_MAIN);
            lv_label_set_text(LabelLabel.get(), settings.label);
            lv_obj_align(LabelLabel.get(), LV_ALIGN_BOTTOM_MID, 0, 0);
        }
    }

private:
    blox_ScreenConfig_NumericValueWidget settings;
    LvglObjectWrapper valueLabel;
    LvglObjectWrapper LabelLabel;
};
}
