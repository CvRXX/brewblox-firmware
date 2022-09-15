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
#include <ctime>

#include "lvgl.h"
#include <vector>

namespace gui::dynamic_interface {

/**
 * A widget which can display a digital clock.
 */
class DigitalClockWidget : public ColorWidget {
public:
    /**
     * Constructs a DigitalClockWidget.
     * @param value The value to be displayed.
     * @param label The label to be displayed.
     * @param color The background color of the widget.
     */
    DigitalClockWidget(screen_DigitalClockWidget& digitalClock)
        : ColorWidget({digitalClock.color.r, digitalClock.color.g, digitalClock.color.b})
        , settings(digitalClock)
    {
    }

    /**
     * Serializes the widget and adds it to a vector.
     * @param contentNodes The vector to which the serialized widget will be added.
     * @param layOutNodeId The id of it's matching layoutNode.
     */
    void serialize(std::vector<screen_ContentNode>& contentNodes, uint8_t layOutNodeId) override final
    {
        screen_ContentNode node = screen_ContentNode_init_default;
        node.layoutNodeId = layOutNodeId;
        node.which_content = screen_ContentNode_digitalClockWidget_tag;
        node.content.digitalClockWidget = settings;

        contentNodes.push_back(node);
    }

    void update() override final
    {
        struct timeval tv;
        time_t nowtime;
        struct tm* nowtm;
        char time[10] = "00:00";

        gettimeofday(&tv, nullptr);
        nowtime = tv.tv_sec;
        nowtm = localtime(&nowtime);
        if (settings.showSeconds) {
            strftime(time, sizeof(time), "%H:%M:%S", nowtm);
        } else {
            strftime(time, sizeof(time), "%H:%M", nowtm);
        }
        lv_label_set_text(valueLabel.get(), time);
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

        lv_label_set_text(valueLabel.get(), "00:00");
        lv_obj_align(valueLabel.get(), LV_ALIGN_CENTER, 0, 0);
        lv_obj_set_style_pad_all(valueLabel.get(), 0, 0);
    }

private:
    screen_DigitalClockWidget settings;
    LvglObjectWrapper valueLabel;
    LvglObjectWrapper LabelLabel;
};
}
