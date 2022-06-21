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
#include "dynamic_gui/util/lvgl_object_wrapper.hpp"
#include "proto/Screen.pb.h"
#include <numeric>

namespace gui::dynamic_interface {

/**
 * An edgenode for the layout tree which contains a children.
 * The children will be drawn horizontally.
 */
class HorizontalSplit final : public LayoutNode {
public:
    /**
     * Constructs a horizontal split.
     * @param children The children of the split
     * @param weight The numerator in the ratio which will be used in it's parent.
     * @param layoutNodeId The id of the layoutNode.
     */
    HorizontalSplit(std::vector<std::unique_ptr<LayoutNode>>&& children, uint16_t weight, uint8_t layOutNodeId)
        : children(std::move(children))
        , weight(weight)
        , layOutNodeId(layOutNodeId)
    {
    }

    /**
     * Serializes the horizontal split node and it's children.
     * @param layoutNodes This class will be serialized into this vector.
     * @param contentNodes The widgets of children will be serialized into this vector.
     */
    void serialize(std::vector<screen_LayoutNode>& layoutNodes, std::vector<screen_ContentNode>& contentNodes, uint8_t parentId) override final
    {
        layoutNodes.push_back({parentId, layOutNodeId, screen_LayoutNode_Type_Row, weight});
        for (auto& child : children) {
            child->serialize(layoutNodes, contentNodes, layOutNodeId);
        }
    }

    /**
     * Calls update on all the childs.
     */
    void update() override final
    {
        for (auto& child : children) {
            child->update();
        }
    }

    /**
     * Returns the weight of the horizontal split.
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
    void draw(lv_obj_t* placeholder, uint16_t width, uint16_t height) override final
    {
        lv_obj_set_style_pad_gap(placeholder, 0, 0);
        lv_obj_set_style_pad_all(placeholder, 0, 0);
        lv_obj_set_style_border_width(placeholder, 0, 0);

        const auto weightTotal = std::accumulate(children.begin(), children.end(), uint16_t(0), [](uint16_t sum, const auto& child) -> uint16_t {
            return sum + child->getWeight();
        });

        uint32_t startingY = 0;
        for (auto& child : children) {
            const auto elementHeight = (height / weightTotal) * child->getWeight();

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(newPlaceholder.get(), width, elementHeight);
            lv_obj_set_style_pad_all(newPlaceholder.get(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.get(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.get(), 0, 0);
            lv_obj_set_pos(newPlaceholder.get(), 0, startingY);
            startingY += elementHeight;
            child->draw(newPlaceholder.get(), width, elementHeight);
            placeholders.push_back(std::move(newPlaceholder));
        }
    }

private:
    std::vector<LvglObjectWrapper> placeholders;
    const std::vector<std::unique_ptr<LayoutNode>> children;
    const uint16_t weight;
    const uint8_t layOutNodeId;
};
}
