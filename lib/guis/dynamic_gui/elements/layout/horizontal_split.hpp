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
#include "proto/ScreenConfig.pb.h"
#include <numeric>

namespace gui::dynamic_interface {

/**
 * A GUI block which takes a set of blocks which are displayed on a horizontal splitted parent.
 */
class HorizontalSplit : public LayoutNode {
public:
    /**
     * Constructs a horizontal split.
     * @param ratioBlocks a list of ratioblocks to be displayed.
     */
    HorizontalSplit(std::vector<std::unique_ptr<LayoutNode>>&& children, uint16_t weight, uint8_t layOutNodeId)
        : children(std::move(children))
        , weight(weight)
        , layOutNodeId(layOutNodeId)
    {
    }

    void serialize(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode>& contentNodes, uint8_t parentId) override final
    {
        layoutNodes.push_back({parentId, layOutNodeId, blox_ScreenConfig_Type_Row, weight});
        for (auto& child : children) {
            child->serialize(layoutNodes, contentNodes, layOutNodeId);
        }
    }

    /**
     * Calls update on all the child blocks.
     */
    void update() override final
    {
        for (auto& child : children) {
            child->update();
        }
    }

    uint16_t getWeight() const override final
    {
        return weight;
    }

    /**
     * Draws the placeholders for it's children and calls their draw function.
     * @param placeholder The parent placeholder.
     * @param width The width of the parent placeholder.
     * @param height The height of the parent placeholder.
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
        std::transform(children.begin(), children.end(), std::back_inserter(placeholders), [&startingY, placeholder, weightTotal, height, width](auto& child) -> LvglObjectWrapper {
            const auto elementHeight = (height / weightTotal) * child->getWeight(); /// first multiply then divide

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(newPlaceholder.get(), width, elementHeight);
            lv_obj_set_style_pad_all(newPlaceholder.get(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.get(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.get(), 0, 0);
            lv_obj_set_pos(newPlaceholder.get(), 0, startingY);
            startingY += elementHeight;
            child->draw(newPlaceholder.get(), width, elementHeight);
            return newPlaceholder;
        });
    }

private:
    std::vector<std::unique_ptr<LayoutNode>> children;
    std::vector<LvglObjectWrapper> placeholders;
    const uint16_t weight = 1;
    uint8_t layOutNodeId;
};
}
