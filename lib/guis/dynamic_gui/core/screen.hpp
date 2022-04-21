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

#include "block.hpp"
#include "lvgl.h"
#include <type_traits>
class Screen {
public:
    template <typename T, typename = std::enable_if_t<std::is_base_of<Block, T>::value>>
    Screen(T&& block)
        : block(std::make_unique<T>(std::move(block)))
    {
        this->block->draw(lv_scr_act(), 480, 320);
    }

    Screen(Screen&& screen)
        : block(std::move(screen.block))
    {
    }

    Screen& operator=(Screen&& screen)
    {
        block = std::move(screen.block);
        return *this;
    }

    Screen(const Screen& screen) = delete;

    Screen& operator=(const Screen& screen) = delete;

    void update()
    {
        block->update();
    }

    std::unique_ptr<Block> block;
};
