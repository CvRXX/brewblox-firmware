#pragma once
#include "lvgl.h"

inline void update_label(lv_obj_t* obj, const char* text)
{
    auto old = lv_label_get_text(obj);
    if (strcmp(old, text) != 0) {
        lv_label_set_text(obj, text);
    }
}
