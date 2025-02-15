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

#include "dynamic_gui/elements/widgets/color_widget.hpp"
#include "dynamic_gui/fonts/fonts.hpp"
#include "dynamic_gui/styles/sizing.hpp"
#include "dynamic_gui/util/color.hpp"
#include "dynamic_gui/util/lvgl_object_wrapper.hpp"
#include "proto/Screen.pb.h"

#include "lvgl.h"
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
    NumericValueWidget(screen_NumericValueWidget& numericValueWidget)
        : ColorWidget({numericValueWidget.color.r, numericValueWidget.color.g, numericValueWidget.color.b})
        , settings(numericValueWidget)
    {
    }

    /**
     * Serializes the widget and adds it to a vector.
     * @param contentNodes The vector to which the serialized widget will be added.
     * @param layOutNodeId The id of it's matching layoutNode.
     */
    void serialize(std::vector<screen_ContentNode>& contentnodes, uint8_t layOutNodeId) override final
    {
        contentnodes.push_back({layOutNodeId, screen_ContentNode_numericValueWidget_tag, settings});
    }

    void update() override final
    {
    }

    /**
     * Draws the numericvalue widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param width The width of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) override final
    {
        ColorWidget::draw(placeholder, width, height);
        valueLabel.reset(sizing::makeBigNumberLabel(contentArea.get(), width, height));

        lv_label_set_text(valueLabel.get(), std::to_string(settings.value).c_str());
        lv_obj_align(valueLabel.get(), LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_pad_all(valueLabel.get(), 0, 0);

        if (sizing::spaceForNameLabel(width, height)) {
            LabelLabel.reset(lv_label_create(contentArea.get()));
            lv_obj_add_style(LabelLabel.get(), &style::widget_name, LV_PART_MAIN);
            lv_label_set_text(LabelLabel.get(), settings.label);
            lv_obj_align(LabelLabel.get(), LV_ALIGN_BOTTOM_MID, 0, 0);
        }
    }

private:
    screen_NumericValueWidget settings;
    LvglObjectWrapper valueLabel;
    LvglObjectWrapper LabelLabel;
};
}
