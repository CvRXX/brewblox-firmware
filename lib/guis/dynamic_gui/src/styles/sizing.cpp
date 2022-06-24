#include "dynamic_gui/styles/sizing.hpp"
namespace gui::dynamic_interface::sizing {

// Returns true if there is space for a label.

lv_obj_t* makeBigNumberLabel(lv_obj_t* parent, uint16_t width, uint16_t height)
{
    auto label = lv_label_create(parent);
    if ((width > hugeBreakPointWidth) && (height > hugeBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_huge, LV_PART_MAIN);
    } else if ((width > largeBreakPointWidth) && (height > largeBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_large, LV_PART_MAIN);
    } else if ((width > mediumBreakPointWidth) && (height > mediumBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_medium, LV_PART_MAIN);
    } else if ((width > smallBreakPointWidth) && (height > smallBreakPointHeight)) {
        lv_obj_add_style(label, &style::number_small, LV_PART_MAIN);
    } else {
        lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
    }
    return label;
}
}
