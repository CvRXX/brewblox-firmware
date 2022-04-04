#pragma once
#include "blocks/core/screen.hpp"
#include "blocks/layouts/horizontal-split.hpp"
#include "blocks/layouts/vertical-split.hpp"
#include "blocks/widgets/color.hpp"
#include <array>
#include <lvgl.h>
#include <memory>

/// A structure that holds the layout of the screen and its children.
class DynamicGui {
public:
    /**
     * Constructs the layout.
     * @param box The Cbox box.
     */
    DynamicGui()
        : screen(
            Screen(
                VerticalSplit(

                    VerticalSplit(
                        Color(0, 255, 255),
                        Color(0, 255, 0), 10),
                    HorizontalSplit(Color(0, 50, 100), Color(255, 255, 0), 75))))
    {
    }
    ~DynamicGui()
    {
    }

    /** Updates the following:
     *   - Checks if a new config is available the layout will be redrawn based on the new config.
     *   - Updates alle the widgets with the latest information about the objects they represent.
     *   - Updates the status bar with the current ip and network status.
     *   - Updates the status bar with the latest time.
     */
    void update()
    {
        screen.update();
    }

private:
    Screen screen;
};
