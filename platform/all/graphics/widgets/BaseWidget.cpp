#include "./BaseWidget.hpp"

uint8_t luminance(const lv_color_t& color)
{
    return (uint16_t{54} * color.ch.red + uint16_t{183} * color.ch.green + uint16_t{18} * color.ch.blue) / 256;
}

BaseWidget::BaseWidget(lv_obj_t* grid, uint8_t row, uint8_t col, const char* labelText, lv_color_t color)
    : obj(lv_obj_create(grid))
    , label(lv_label_create(obj))
    , bg_color(color)
{
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(obj, 148, 134);
    lv_obj_add_style(obj, &style::block, LV_STATE_DEFAULT);
    lv_obj_add_style(obj, &style::block_disabled, LV_STATE_DISABLED);

    lv_obj_set_style_bg_color(obj, color, LV_STATE_DEFAULT);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, 1,
                         LV_GRID_ALIGN_STRETCH, row, 1);

    // set styling of object and its children based on luminance of background color
    lv_obj_add_style(obj, luminance(color) < 128 ? &style::bg_dark : &style::bg_light, 0);

    lv_obj_add_style(label, &style::widget_name, 0);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, LV_ALIGN_BOTTOM_MID, 0, 4);
}

BaseWidget::~BaseWidget()
{
    lv_obj_del(obj);
}

TempUnit BaseWidget::tempUnit = TempUnit::Celsius;
