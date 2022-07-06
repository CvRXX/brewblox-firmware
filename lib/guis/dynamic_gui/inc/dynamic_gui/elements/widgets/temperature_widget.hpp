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

#include "cbox/CboxPtr.hpp"
#include "control/TempSensor.hpp"
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
 * A widget which can display a temperature.
 */
class TemperatureWidget : public ColorWidget {
public:
    /**
     * Constructs a temperature widget..
     * @param value The value to be displayed.
     * @param label The label to be displayed.
     * @param color The background color of the widget.
     */
    explicit TemperatureWidget(screen_TemperatureWidget& temperatureWidget)
        : ColorWidget({temperatureWidget.color.r, temperatureWidget.color.g, temperatureWidget.color.b})
        , settings(temperatureWidget)
        , lookup(cbox::CboxPtr<TempSensor>(cbox::obj_id_t(temperatureWidget.tempSensor)))
    {
    }

    /**
     * Serializes the widget and adds it to a vector.
     * @param contentNodes The vector to which the serialized widget will be added.
     * @param layOutNodeId The id of it's matching layoutNode.
     */
    void serialize(std::vector<screen_ContentNode>& contentNodes, uint8_t layOutNodeId) final
    {
        screen_ContentNode node = screen_ContentNode_init_default;
        node.layoutNodeId = layOutNodeId;
        node.which_content = screen_ContentNode_temperatureWidget_tag;
        node.content.temperatureWidget = settings;

        contentNodes.push_back(node);
    }

    void update() final
    {
        if (auto ptr = lookup.lock()) {
            if (ptr->valid()) {
                auto str = temp_to_string(ptr->value(), 1, TempUnit::Celsius);
                str.append(TempUnit::Celsius == TempUnit::Fahrenheit ? "°F" : "°C");
                setValue(str);
            } else {
                setValue("-");
            }
        }
    }

    /**
     * Draws the numericvalue widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param width The width of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) final
    {
        ColorWidget::draw(placeholder, width, height);
        valueLabel.reset(sizing::makeBigNumberLabel(contentArea.get(), width, height));

        update();

        if (sizing::spaceForNameLabel(width, height)) {
            LabelLabel.reset(lv_label_create(contentArea.get()));
            lv_obj_add_style(LabelLabel.get(), &style::widget_name, LV_PART_MAIN);
            lv_label_set_text(LabelLabel.get(), settings.label);
            lv_obj_align(LabelLabel.get(), LV_ALIGN_BOTTOM_MID, 0, 0);
        }
    }

private:
    void setValue(const std::string& value)
    {
        lv_label_set_text(valueLabel.get(), value.c_str());
        lv_obj_align(valueLabel.get(), LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_pad_all(valueLabel.get(), 0, 0);
    }
    screen_TemperatureWidget settings;
    cbox::CboxPtr<TempSensor> lookup;

    LvglObjectWrapper valueLabel;
    LvglObjectWrapper LabelLabel;
};
}
