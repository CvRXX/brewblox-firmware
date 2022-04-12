#include "dynamic_gui/blocks/core/block.hpp"
#include "dynamic_gui/util/lvgl-object-wrapper.hpp"

class HorizontalSplit : public Block {
public:
    template <typename T1, typename T2>
    HorizontalSplit(T1&& blockUp, T2&& blockDown, uint8_t deviderPosition = 50)
        : blockUp(std::make_unique<T1>(std::move(blockUp)))
        , blockDown(std::make_unique<T2>(std::move(blockDown)))
        , deviderPosition(deviderPosition)
    {
    }

    HorizontalSplit(HorizontalSplit&& horizontalSplit)
        : blockUp(std::move(horizontalSplit.blockUp))
        , blockDown(std::move(horizontalSplit.blockDown))
        , deviderPosition(horizontalSplit.deviderPosition)
        , container(std::move(horizontalSplit.container))
        , placeHolderUp(std::move(horizontalSplit.placeHolderUp))
        , placeHolderDown(std::move(horizontalSplit.placeHolderDown))

    {
    }

    void update() override
    {
        blockUp->update();
        blockDown->update();
    }

    void draw(lv_obj_t* placeholder) override
    {
        lv_coord_t upMemberHeight = lv_pct(this->deviderPosition);
        lv_coord_t downMemberHeight = lv_pct(100 - this->deviderPosition);
        lv_coord_t memberWidth = lv_pct(100);

        col_dsc[0] = memberWidth;
        col_dsc[1] = LV_COORD_MAX;
        row_dsc[0] = upMemberHeight;
        row_dsc[1] = downMemberHeight;
        row_dsc[2] = LV_COORD_MAX;

        container.reset(lv_obj_create(placeholder));
        lv_obj_clear_flag(container.getPtr(), LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_grid_column_dsc_array(container.getPtr(), col_dsc, 0);
        lv_obj_set_style_grid_row_dsc_array(container.getPtr(), row_dsc, 0);
        lv_obj_set_size(container.getPtr(), lv_pct(100), lv_pct(100));
        lv_obj_set_style_pad_gap(container.getPtr(), 0, 0);
        lv_obj_set_style_pad_all(container.getPtr(), 0, 0);
        lv_obj_set_style_border_width(container.getPtr(), 0, 0);
        lv_obj_center(container.getPtr());
        lv_obj_set_layout(container.getPtr(), LV_LAYOUT_GRID);

        placeHolderUp.reset(lv_obj_create(container.getPtr()));
        lv_obj_set_size(placeHolderUp.getPtr(), memberWidth, upMemberHeight);
        lv_obj_set_style_pad_all(placeHolderUp.getPtr(), 0, 0);
        lv_obj_set_style_border_width(placeHolderUp.getPtr(), 0, 0);
        lv_obj_set_style_radius(placeHolderUp.getPtr(), 0, 0);

        placeHolderDown.reset(lv_obj_create(container.getPtr()));
        lv_obj_set_style_pad_all(placeHolderDown.getPtr(), 0, 0);
        lv_obj_set_size(placeHolderDown.getPtr(), memberWidth, downMemberHeight);
        lv_obj_set_style_border_width(placeHolderDown.getPtr(), 0, 0);
        lv_obj_set_style_radius(placeHolderDown.getPtr(), 0, 0);

        lv_obj_set_grid_cell(placeHolderUp.getPtr(), LV_GRID_ALIGN_STRETCH, 0, 1,
                             LV_GRID_ALIGN_STRETCH, 0, 1);
        lv_obj_set_grid_cell(placeHolderDown.getPtr(), LV_GRID_ALIGN_STRETCH, 0, 1,
                             LV_GRID_ALIGN_STRETCH, 1, 1);

        blockUp->draw(placeHolderUp.getPtr());
        blockDown->draw(placeHolderDown.getPtr());
    }
    lv_coord_t col_dsc[2];
    lv_coord_t row_dsc[3];

    LvglObjectWrapper container = nullptr;
    LvglObjectWrapper placeHolderUp = nullptr;
    LvglObjectWrapper placeHolderDown = nullptr;

    std::unique_ptr<Block> blockUp;
    std::unique_ptr<Block> blockDown;
    const uint8_t deviderPosition;
};
