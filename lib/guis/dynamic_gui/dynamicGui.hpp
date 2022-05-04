#pragma once
#include "elements/core/screen.hpp"
#include "elements/layouts/horizontal-split.hpp"
#include "elements/layouts/vertical-split.hpp"
#include "elements/widgets/numeric_value.hpp"
#include "elements/widgets/widget.hpp"
#include "styles/styles.hpp"
#include <array>
#include <lvgl.h>
#include <memory>

namespace gui::dynamic_interface {

/// A structure that holds the layout of the screen and its children.
class DynamicGui {
public:
    DynamicGui()
        : screen(
            Screen(Widget(Color(255, 255, 255), 1)))
    {
        style::init();

        std::unique_ptr<Element> element{new NumericValue(333, "Stout", {0, 0, 255}, 1)};
        bool verticalSplit = false;
        for (int i = 0; i < 7; i++) {
            std::vector<std::unique_ptr<Element>> vector;
            vector.push_back(std::move(element));
            std::unique_ptr<Element> toAddElement{new NumericValue(333, "Stout", {0, 0, 255}, 1)};
            vector.push_back(std::move(toAddElement));
            if (verticalSplit) {
                element.reset({new VerticalSplit(std::move(vector), 1)});
                verticalSplit = false;
            } else {
                element.reset({new HorizontalSplit(std::move(vector), 1)});
                verticalSplit = true;
            }
        }
        screen = Screen(std::move(element));
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
}
