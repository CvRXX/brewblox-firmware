#include "./BaseWidget.hpp"

uint8_t luminance(const lv_color_t& color)
{
    return (uint16_t{54} * color.ch.red + uint16_t{183} * color.ch.green + uint16_t{18} * color.ch.blue) / 256;
}

BaseWidget::BaseWidget(lv_obj_t* grid, const char* labelText, lv_color_t color)
    : obj(lv_obj_create(grid, nullptr))
    , label(lv_label_create(obj, nullptr))
    , bg_color(color)
{
    lv_obj_set_size(obj, 148, 135);
    lv_obj_add_style(obj, LV_OBJ_PART_MAIN, &style::block);
    lv_obj_set_style_local_bg_color(obj, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, color);

    // set styling of object and its children based on luminance of background color
    lv_obj_add_style(obj, LV_OBJ_PART_MAIN, luminance(color) < 128 ? &style::bg_dark : &style::bg_light);

    lv_obj_add_style(label, LV_LABEL_PART_MAIN, &style::widget_name);
    lv_label_set_text(label, labelText);
    lv_obj_align(label, nullptr, LV_ALIGN_IN_BOTTOM_MID, 0, -4);
}

BaseWidget::~BaseWidget()
{
    lv_obj_del(obj);
}

TempUnit BaseWidget::tempUnit = TempUnit::Celsius;