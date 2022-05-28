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

#include "dynamic_gui/elements/layout/layout_node.hpp"
#include "dynamic_gui/elements/widgets/widget.hpp"
#include "proto/ScreenConfig.pb.h"

namespace gui::dynamic_interface {

/**
 * A leafnode for the layout tree which contains a widget as content.
 */
class Content final : public LayoutNode {
public:
    /**
     * Constructs a content node.
     */
    Content(uint16_t weight, uint8_t layOutNodeId, std::unique_ptr<Widget> widget)
        : weight(weight)
        , layOutNodeId(layOutNodeId)
        , widget(std::move(widget))
    {
    }

    // Calls update on it's widget.
    void update() override
    {
        widget->update();
    }

    /**
     * Returns the weight of the contentnode.
     * Weights are used for deciding the ratio in which nodes are displayed.
     */
    uint16_t getWeight() const override
    {
        return weight;
    }
    /**
     * Serializes the content node and it's widget.
     * @param layoutNodes This class will be serialized into this vector.
     * @param contentNodes The child of this class will be serialized into this vector.
     */
    void serialize(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode>& contentNodes, uint8_t parentId) override
    {
        layoutNodes.push_back({parentId, layOutNodeId, blox_ScreenConfig_Type_Content, weight});
        widget->serialize(contentNodes, layOutNodeId);
    }

    /**
     * Calls draw on the widget forwarding the parameters.
     * @param placeholder The lvgl placeholder in which the widget will be drawn.
     * @param width the width of the available space in the placeholder.
     * @param height the height of the available space in the placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) override
    {
        widget->draw(placeholder, width, height);
    }

private:
    const uint16_t weight;
    const uint8_t layOutNodeId;
    std::unique_ptr<Widget> widget;
};
}
