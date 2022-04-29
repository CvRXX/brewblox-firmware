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
        std::unique_ptr<Element> temp1{new NumericValue(33, "Stout", {0, 0, 255}, 1)};
        std::unique_ptr<Element> temp2 = std::make_unique<NumericValue>(NumericValue(33, "Annaas", {0, 255, 255}, 2));
        std::unique_ptr<Element> temp3 = std::make_unique<NumericValue>(NumericValue(33, "carlos", {0, 255, 255}, 1));

        std::unique_ptr<Element> temp4 = std::make_unique<NumericValue>(NumericValue(33, "IPA", {0, 0, 255}, 1));
        std::unique_ptr<Element> temp5 = std::make_unique<NumericValue>(NumericValue(33, "BLond", {0, 255, 255}, 3));
        std::unique_ptr<Element> temp6 = std::make_unique<NumericValue>(NumericValue(33, "TEST", {0, 255, 255}, 1));

        std::vector<std::unique_ptr<Element>> rows;
        std::vector<std::unique_ptr<Element>> row1;
        std::vector<std::unique_ptr<Element>> row2;

        row1.push_back(std::move(temp1));
        row1.push_back(std::move(temp2));
        row1.push_back(std::move(temp3));

        row2.push_back(std::move(temp4));
        row2.push_back(std::move(temp5));
        row2.push_back(std::move(temp6));

        rows.push_back(std::make_unique<VerticalSplit>(VerticalSplit(std::move(row1), 1)));
        rows.push_back(std::make_unique<VerticalSplit>(VerticalSplit(std::move(row2), 3)));

        screen = Screen(
            HorizontalSplit(std::move(rows), 1));
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
