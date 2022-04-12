#include "dynamic_gui/blocks/core/block.hpp"
#include "dynamic_gui/util/lvgl-object-wrapper.hpp"
template <typename... Ts>
class Grid : public Block {
public:
    static constexpr std::size_t size = sizeof...(Ts);

    Grid(Ts&&... blocks)
        : blocks{
            std::make_unique<Ts>(std::move(blocks))...}
    {
    }

    Grid(Grid&& verticalSplit)
        : blocks(std::move(verticalSplit.blocks))
        , container(std::move(container))
    {
    }

    void update() override
    {
    }

    void draw(lv_obj_t* placeholder) override
    {

        // lv_coord_t leftMemberWith = lv_pct(this->deviderPosition);
        // lv_coord_t rightMemberWith = lv_pct(100 - this->deviderPosition);
        // lv_coord_t memberHeight = lv_pct(100);

        // col_dsc[0] = leftMemberWith;
        // col_dsc[1] = rightMemberWith;
        // col_dsc[2] = LV_COORD_MAX;
        // row_dsc[0] = memberHeight;
        // row_dsc[1] = LV_COORD_MAX;

        // container.reset(lv_obj_create(placeholder));
        // lv_obj_clear_flag(container.getPtr(), LV_OBJ_FLAG_SCROLLABLE);
        // lv_obj_set_style_grid_column_dsc_array(container.getPtr(), col_dsc, 0);
        // lv_obj_set_style_grid_row_dsc_array(container.getPtr(), row_dsc, 0);
        // lv_obj_set_size(container.getPtr(), lv_pct(100), lv_pct(100));
        // lv_obj_set_style_pad_gap(container.getPtr(), 0, 0);
        // lv_obj_set_style_pad_all(container.getPtr(), 0, 0);
        // lv_obj_set_style_border_width(container.getPtr(), 0, 0);
        // lv_obj_center(container.getPtr());
        // lv_obj_set_layout(container.getPtr(), LV_LAYOUT_GRID);

        // placeHolderLeft.reset(lv_obj_create(container.getPtr()));
        // lv_obj_set_size(placeHolderLeft.getPtr(), leftMemberWith, memberHeight);
        // lv_obj_set_style_pad_all(placeHolderLeft.getPtr(), 0, 0);
        // lv_obj_set_style_border_width(placeHolderLeft.getPtr(), 0, 0);
        // lv_obj_set_style_radius(placeHolderLeft.getPtr(), 0, 0);

        // placeHolderRight.reset(lv_obj_create(container.getPtr()));
        // lv_obj_set_style_pad_all(placeHolderRight.getPtr(), 0, 0);
        // lv_obj_set_size(placeHolderRight.getPtr(), rightMemberWith, memberHeight);
        // lv_obj_set_style_border_width(placeHolderRight.getPtr(), 0, 0);
        // lv_obj_set_style_radius(placeHolderRight.getPtr(), 0, 0);

        // lv_obj_set_grid_cell(placeHolderLeft.getPtr(), LV_GRID_ALIGN_STRETCH, 0, 1,
        //                      LV_GRID_ALIGN_STRETCH, 0, 1);
        // lv_obj_set_grid_cell(placeHolderRight.getPtr(), LV_GRID_ALIGN_STRETCH, 1, 1,
        //                      LV_GRID_ALIGN_STRETCH, 0, 1);

        // blockLeft->draw(placeHolderLeft.getPtr());
        // blockRight->draw(placeHolderRight.getPtr());
    }
    lv_coord_t col_dsc[3];
    lv_coord_t row_dsc[2];

    LvglObjectWrapper container = nullptr;
    // std::array<LvglObjectWrapper, size> placeholders;
    std::array<std::unique_ptr<Block>, size> blocks;
};
