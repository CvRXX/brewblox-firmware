#include "dynamic_gui/blocks/core/block.hpp"
#include "dynamic_gui/util/lvgl-object-wrapper.hpp"

class VerticalSplit : public Block {
public:
    VerticalSplit(std::vector<RatioBlock>&& ratioBlocks)
        : ratioBlocks(std::move(ratioBlocks))
    {
    }

    VerticalSplit(VerticalSplit&& verticalSplit)
        : ratioBlocks(std::move(verticalSplit.ratioBlocks))
        , placeholders(std::move(verticalSplit.placeholders))
    {
    }

    void update() override
    {
        for (auto& block : ratioBlocks) {
            block.block->update();
        }
    }

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
            lv_obj_set_size(newPlaceholder.getPtr(), elementWidth, height);
            lv_obj_set_style_pad_all(newPlaceholder.getPtr(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.getPtr(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.getPtr(), 0, 0);
            lv_obj_set_pos(newPlaceholder.getPtr(), startingX, 0);
            startingX += elementWidth;
            block.block->draw(newPlaceholder.getPtr(), elementWidth, height);
            return newPlaceholder;
        });
    }

    std::vector<LvglObjectWrapper> placeholders;
    std::vector<RatioBlock> ratioBlocks;
};
