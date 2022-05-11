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

#include "element.hpp"
#include "lvgl.h"
#include "proto/guiMessage.pb.h"
#include <type_traits>

namespace gui::dynamic_interface {

class Screen {
public:
    template <typename T, typename = std::enable_if_t<std::is_base_of<Element, T>::value>>
    Screen(T&& element)
        : element(std::make_unique<T>(std::move(element)))
    {
    }
    Screen()
        : element(nullptr)
    {
    }

    Screen(std::unique_ptr<Element> element)
        : element(std::move(element))
    {
    }

    Screen(Screen&& screen) = default;

    Screen& operator=(Screen&& screen) = default;

    Screen(const Screen& screen)
        = delete;

    Screen& operator=(const Screen& screen) = delete;

    void update()
    {
        if (element) {
            element->update();
        }
    }
    void draw()
    {
        if (element) {
            element->draw(lv_scr_act(), 480, 320);
        }
    }

    bool serialise(std::vector<guiMessage_LayoutNode>& layoutNodes, std::vector<guiMessage_ContentNode>& contentNodes)
    {
        if (element) {
            return element->serialise(layoutNodes, contentNodes, 0);
        }
        return false;
    }

    std::unique_ptr<Element> element;
};
}
