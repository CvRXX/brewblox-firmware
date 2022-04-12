#pragma once

#include "lvgl.h"
#include <iostream>

class LvglObjectWrapper {
public:
    constexpr LvglObjectWrapper(lv_obj_t* lvglObject)
        : lvglObject(lvglObject)
    {
    }

    constexpr LvglObjectWrapper(LvglObjectWrapper&& lvglObjectWrapper)
        : lvglObject(lvglObjectWrapper.lvglObject)
    {
        lvglObjectWrapper.lvglObject = nullptr;
    }

    ~LvglObjectWrapper()
    {
        if (lvglObject) {
            std::cout << "delete happening \n";
            lv_obj_del(lvglObject);
        }
    }

    lv_obj_t* getPtr()
    {
        return lvglObject;
    }

    void reset(lv_obj_t* newPtr)
    {
        if (lvglObject) {
            lv_obj_del(lvglObject);
        }
        lvglObject = newPtr;
    }
    lv_obj_t* lvglObject;
};
