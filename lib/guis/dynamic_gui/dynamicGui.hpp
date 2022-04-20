#pragma once
#include "blocks/core/screen.hpp"
#include "blocks/layouts/horizontal-split.hpp"
#include "blocks/layouts/vertical-split.hpp"
#include "blocks/widgets/numeric-value.hpp"
#include "blocks/widgets/widget.hpp"
#include "styles/styles.hpp"
#include <array>
#include <iostream>
#include <lvgl.h>
#include <memory>

/// A structure that holds the layout of the screen and its children.
class DynamicGui {
public:
    DynamicGui()
        : screen(
            Screen(Widget(Color(255, 255, 255))))
    {
        style::init();
        std::unique_ptr<Block> temp1 = std::make_unique<NumericValue>(NumericValue(33, "Stout", {0, 0, 255}));
        std::unique_ptr<Block> temp2 = std::make_unique<NumericValue>(NumericValue(33, "Annaas", {0, 255, 255}));
        std::unique_ptr<Block> temp3 = std::make_unique<NumericValue>(NumericValue(33, "carlos", {0, 255, 255}));

        std::vector<RatioBlock> splits;
        splits.push_back(RatioBlock{std::move(temp1), 2});
        splits.push_back(RatioBlock{std::move(temp2), 2});
        splits.push_back(RatioBlock{std::move(temp3), 1});

        auto thing = Screen(
            VerticalSplit(
                std::move(splits)));
        screen = std::move(thing);
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
