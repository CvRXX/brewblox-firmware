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

#include "dynamic_gui/elements/widgets/widget.hpp"
#include "dynamic_gui/styles/styles.hpp"
#include "dynamic_gui/util/color.hpp"
#include "dynamic_gui/util/lvgl_object_wrapper.hpp"
#include "proto/Screen.pb.h"

namespace gui::dynamic_interface {

// A widget that displays a singe color.
class ColorWidget : public Widget {
public:
    /**
     * Constructs the ColorWidget.
     * @param color The background color of the widget.
     */
    constexpr ColorWidget(screen_ColorWidget colorWidget)
        : settings(colorWidget)
        , color({colorWidget.color.r, colorWidget.color.g, colorWidget.color.b})
    {
    }

    /**
     * Serializes the widget and adds it to a vector.
     * @param contentNodes The vector to which the serialized widget will be added.
     * @param layOutNodeId The id of it's matching layoutNode.
     */
    void serialize(std::vector<screen_ContentNode>& contentNodes, uint8_t layOutNodeId) override
    {
        screen_ContentNode node = screen_ContentNode_init_default;
        node.layoutNodeId = layOutNodeId;
        node.which_content = screen_ContentNode_colorWidget_tag;
        node.content.colorWidget = settings;

        contentNodes.push_back(node);
    }

    void update() override
    {
    }

    /**
     * Draws the widget in its parent placeholder.
     * @param placeholder The parent placeholder.
     * @param width The width of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) override
    {
        contentArea.reset(lv_obj_create(placeholder));
        lv_obj_clear_flag(placeholder, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(contentArea.get(), LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_size(contentArea.get(), lv_pct(100), lv_pct(100));
        lv_obj_add_style(placeholder, &style::block, LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(contentArea.get(), color, LV_STATE_DEFAULT);
        lv_obj_add_style(contentArea.get(), luminance() < 128 ? &style::bg_dark : &style::bg_light, 0);
    }

    /**
     * Returns the luminance of the background color.
     * This is useful for choosing font colors with readable contrast.
     * @return The luminance
     */
    constexpr uint8_t luminance()
    {
        return (uint16_t{54} * color.r + uint16_t{183} * color.g + uint16_t{18} * color.b) / 256;
    }

protected:
    screen_ColorWidget settings;
    Color color;
    LvglObjectWrapper contentArea = nullptr;
};
}
