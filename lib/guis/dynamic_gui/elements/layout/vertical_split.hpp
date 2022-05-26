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
#include "dynamic_gui/util/lvgl_wrapper.hpp"
#include <numeric>

namespace gui::dynamic_interface {

/**
 * An edgenode for the layout tree which contains a children.
 * The children will be drawn vertically.
 */
class VerticalSplit : public LayoutNode {
public:
    /**
     * Constructs a vertical split.
     * @param children The children of the split
     * @param weight The numerator in the ratio which will be used in it's parent.
     * @param layoutNodeId The id of the layoutNode.
     */
    VerticalSplit(std::vector<std::unique_ptr<LayoutNode>>&& children, uint16_t weight, uint8_t layOutNodeId)
        : children(std::move(children))
        , weight(weight)
        , layOutNodeId(layOutNodeId)

    {
    }

    /**
     * Serializes the vertical split node and it's children.
     * @param layoutNodes This class will be serialized into this vector.
     * @param contentNodes The widgets of children will be serialized into this vector.
     */
    void serialize(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode>& contentNodes, uint8_t parentId) override
    {
        layoutNodes.push_back({parentId, layOutNodeId, blox_ScreenConfig_Type_Column, weight});
        for (auto& child : children) {
            child->serialize(layoutNodes, contentNodes, layOutNodeId);
        }
    }

    /**
     * Calls update on all the childs.
     */
    void update() override
    {
        for (auto& child : children) {
            child->update();
        }
    }

    /**
     * Returns the weight of the vertical split.
     * Weights are used for deciding the ratio in which nodes are displayed.
     */
    uint16_t getWeight() const override final
    {
        return weight;
    }

    /**
     * Creates placeholders for it's children and calls draw on these children with these placeholders.
     * @param placeholder The lvgl placeholder in which the children will be drawn.
     * @param width the width of the available space in the placeholder.
     * @param height the height of the available space in the placeholder.
     */
    void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) override
    {
        lv_obj_set_style_pad_gap(placeholder, 0, 0);
        lv_obj_set_style_pad_all(placeholder, 0, 0);
        lv_obj_set_style_border_width(placeholder, 0, 0);

        const auto weightTotal = std::accumulate(children.begin(), children.end(), uint32_t(0), [](auto& sum, auto& child) -> uint32_t {
            return sum + child->getWeight();
        });

        uint32_t startingX = 0;

        for (auto& child : children) {
            const auto elementWidth = (width / weightTotal) * child->getWeight();

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(newPlaceholder.get(), elementWidth, height);
            lv_obj_set_style_pad_all(newPlaceholder.get(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.get(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.get(), 0, 0);
            lv_obj_set_pos(newPlaceholder.get(), startingX, 0);
            startingX += elementWidth;
            child->draw(newPlaceholder.get(), elementWidth, height);
            placeholders.push_back(std::move(newPlaceholder));
        }
    }

private:
    const std::vector<std::unique_ptr<LayoutNode>> children;
    std::vector<LvglObjectWrapper> placeholders;
    const uint16_t weight = 1;
    const uint8_t layOutNodeId;
};
}
