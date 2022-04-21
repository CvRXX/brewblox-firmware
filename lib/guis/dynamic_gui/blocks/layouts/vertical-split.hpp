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

#include "dynamic_gui/blocks/core/block.hpp"
#include "dynamic_gui/blocks/core/ratioBlock.hpp"
#include "dynamic_gui/util/lvgl-object-wrapper.hpp"
#include <numeric>

/**
 * A GUI block which takes a set of blocks which are displayed on a vertical splitted parent.
 */
class VerticalSplit : public Block {
public:
    /**
     * Constructs a vertical split.
     * @param ratioBlocks a list of ratioblocks to be displayed.
     */
    VerticalSplit(std::vector<RatioBlock>&& ratioBlocks)
        : ratioBlocks(std::move(ratioBlocks))
    {
    }

    VerticalSplit(VerticalSplit&& verticalSplit)
        : ratioBlocks(std::move(verticalSplit.ratioBlocks))
        , placeholders(std::move(verticalSplit.placeholders))
    {
    }

    /**
     * Calls update on all the child blocks.
     */
    void update() override
    {
        for (auto& block : ratioBlocks) {
            block.block->update();
        }
    }

    /**
     * Draws the placeholders for it's children and calls their draw function.
     * @param placeholder The parent placeholder.
     * @param with The with of the parent placeholder.
     * @param height The height of the parent placeholder.
     */
    void draw(lv_obj_t* placeholder, uint32_t with, uint32_t height) override
    {
        lv_obj_set_style_pad_gap(placeholder, 0, 0);
        lv_obj_set_style_pad_all(placeholder, 0, 0);
        lv_obj_set_style_border_width(placeholder, 0, 0);

        const auto ratioTotal = std::accumulate(ratioBlocks.begin(), ratioBlocks.end(), uint32_t(0), [](auto& sum, auto& ratio) -> uint32_t {
            return sum + ratio.ratio;
        });

        uint32_t startingX = 0;
        std::transform(ratioBlocks.begin(), ratioBlocks.end(), std::back_inserter(placeholders), [&](const auto& block) -> LvglObjectWrapper {
            const auto elementWidth = (with / ratioTotal) * block.ratio;

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(newPlaceholder.get(), elementWidth, height);
            lv_obj_set_style_pad_all(newPlaceholder.get(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.get(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.get(), 0, 0);
            lv_obj_set_pos(newPlaceholder.get(), startingX, 0);
            startingX += elementWidth;
            block.block->draw(newPlaceholder.get(), elementWidth, height);
            return newPlaceholder;
        });
    }

private:
    std::vector<LvglObjectWrapper> placeholders;
    std::vector<RatioBlock> ratioBlocks;
};
