#include "dynamic_gui/blocks/core/block.hpp"
#include "dynamic_gui/blocks/core/ratioBlock.hpp"
#include "dynamic_gui/util/lvgl-object-wrapper.hpp"
#include <numeric>

class HorizontalSplit : public Block {
public:
    HorizontalSplit(std::vector<RatioBlock>&& ratioBlocks)
        : ratioBlocks(std::move(ratioBlocks))
    {
    }

    HorizontalSplit(HorizontalSplit&& horizontalSplit)
        : ratioBlocks(std::move(horizontalSplit.ratioBlocks))
        , placeholders(std::move(horizontalSplit.placeholders))

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

        uint32_t startingY = 0;
        std::transform(ratioBlocks.begin(), ratioBlocks.end(), std::back_inserter(placeholders), [&](const auto& block) -> LvglObjectWrapper {
            const auto elementHeight = (height / ratioTotal) * block.ratio;

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(&newPlaceholder, with, elementHeight);
            lv_obj_set_style_pad_all(&newPlaceholder, 2, 0);
            lv_obj_set_style_border_width(&newPlaceholder, 0, 0);
            lv_obj_set_style_radius(&newPlaceholder, 0, 0);
            lv_obj_set_pos(&newPlaceholder, 0, startingY);
            startingY += elementHeight;
            block.block->draw(&newPlaceholder, with, elementHeight);
            return newPlaceholder;
        });
    }

    std::vector<LvglObjectWrapper> placeholders;
    std::vector<RatioBlock> ratioBlocks;
};
