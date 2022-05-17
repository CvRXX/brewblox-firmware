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
#include "lvgl.h"
#include "proto/ScreenConfig.pb.h"
#include <type_traits>

namespace gui::dynamic_interface {

class Screen : public LayoutNode {
public:
    template <typename T, typename = std::enable_if_t<std::is_base_of<LayoutNode, T>::value>>
    Screen(T&& child)
        : child(std::make_unique<T>(std::move(child)))
    {
    }

    Screen(std::unique_ptr<LayoutNode>&& child)
        : child(std::move(child))
    {
    }

    Screen() = default;

    void update() override
    {
        if (child) {
            child->update();
        }
    }
    void draw(lv_obj_t* screen, uint16_t width, uint16_t height) override
    {
        if (child) {
            child->draw(screen, width, height);
        }
    }

    uint16_t getWeight() const override
    {
        return 0;
    }

    void serialize(std::vector<blox_ScreenConfig_LayoutNode>& layoutNodes, std::vector<blox_ScreenConfig_ContentNode>& contentNodes, uint8_t parentId = 0) override
    {
        return child->serialize(layoutNodes, contentNodes, 0);
    }

    std::unique_ptr<LayoutNode> child;
};
}
