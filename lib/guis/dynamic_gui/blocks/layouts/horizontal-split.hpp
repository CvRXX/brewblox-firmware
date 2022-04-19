#include "dynamic_gui/blocks/core/block.hpp"
#include "dynamic_gui/util/lvgl-object-wrapper.hpp"
#include <numeric>

class HorizontalSplit : public Block {
public:
    HorizontalSplit(std::vector<std::unique_ptr<Block>>&& blocks, std::vector<uint32_t>&& ratios)
        : blocks(std::move(blocks))
        , ratios(std::move(ratios))
    {
    }

    HorizontalSplit(HorizontalSplit&& horizontalSplit)
        : blocks(std::move(horizontalSplit.blocks))
        , placeholders(std::move(horizontalSplit.placeholders))
        , ratios(horizontalSplit.ratios)

    {
        assert(blocks.size() == ratios.size());
    }

    void update() override
    {
        for (auto& block : blocks) {
            block->update();
        }
    }

    void draw(lv_obj_t* placeholder, uint32_t with, uint32_t height) override
    {

        lv_obj_set_style_pad_gap(placeholder, 0, 0);
        lv_obj_set_style_pad_all(placeholder, 0, 0);
        lv_obj_set_style_border_width(placeholder, 0, 0);

        const auto ratioTotal = std::accumulate(ratios.begin(), ratios.end(), uint32_t(0));

        uint32_t startingY = 0;
        std::transform(blocks.begin(), blocks.end(), ratios.begin(), std::back_inserter(placeholders), [&](const auto& block, const auto ratio) -> LvglObjectWrapper {
            const auto elementHeight = (height / ratioTotal) * ratio;

            auto newPlaceholder = LvglObjectWrapper(lv_obj_create(placeholder));
            lv_obj_set_size(newPlaceholder.getPtr(), with, elementHeight);
            lv_obj_set_style_pad_all(newPlaceholder.getPtr(), 2, 0);
            lv_obj_set_style_border_width(newPlaceholder.getPtr(), 0, 0);
            lv_obj_set_style_radius(newPlaceholder.getPtr(), 0, 0);
            lv_obj_set_pos(newPlaceholder.getPtr(), 0, startingY);
            startingY += elementHeight;
            block->draw(newPlaceholder.getPtr(), with, elementHeight);
            return newPlaceholder;
        });
    }

    std::vector<LvglObjectWrapper> placeholders;
    std::vector<std::unique_ptr<Block>> blocks;
    std::vector<uint32_t> ratios;
};
