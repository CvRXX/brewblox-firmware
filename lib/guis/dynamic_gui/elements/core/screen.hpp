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
#include <type_traits>

namespace gui::dynamic_interface {

class Screen {
public:
    template <typename T, typename = std::enable_if_t<std::is_base_of<Element, T>::value>>
    Screen(T&& element)
        : element(std::make_unique<T>(std::move(element)))
    {
        this->element->draw(lv_scr_act(), 480, 320);
    }

    Screen(std::unique_ptr<Element> element)
        : element(std::move(element))
    {
        this->element->draw(lv_scr_act(), 480, 320);
    }

    Screen(Screen&& screen)
        : element(std::move(screen.element))
    {
    }

    Screen& operator=(Screen&& screen)
    {
        element = std::move(screen.element);
        return *this;
    }

    Screen(const Screen& screen) = delete;

    Screen& operator=(const Screen& screen) = delete;

    void update()
    {
        element->update();
    }

    std::unique_ptr<Element> element;
};
}
