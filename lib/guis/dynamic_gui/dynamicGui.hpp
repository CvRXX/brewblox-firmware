#pragma once
#include "elements/layout/screen.hpp"
#include "proto/Screen.pb.h"
#include "styles/styles.hpp"
#include <array>
#include <iostream>
#include <lvgl.h>
#include <memory>

namespace gui::dynamic_interface {

/// A structure that holds the layout of the screen and its children.
class DynamicGui {
public:
    DynamicGui()
    {
        style::init();
    }

    ~DynamicGui()
    {
    }

    void update()
    {
        screen.update();
    }

    void setNewScreen(Screen&& newScreen)
    {
        screen = std::move(newScreen);
        screen.draw(lv_scr_act(), 480, 320);
    }

private:
    Screen screen;
};
}
