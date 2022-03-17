#pragma once
#include "styles.hpp"
#include "widgets/BaseWidget.hpp"
#include <array>
#include <lvgl.h>
#include <memory>

class Bar;
class BaseWidget;

/// A structure that holds the layout of the screen and its children.
class Layout {
public:
    /**
     * Constructs the layout.
     * @param box The Cbox box.
     */
    Layout();
    ~Layout();

    /** Updates the following:
     *   - Checks if a new config is available the layout will be redrawn based on the new config.
     *   - Updates alle the widgets with the latest information about the objects they represent.
     *   - Updates the status bar with the current ip and network status.
     *   - Updates the status bar with the latest time.
     */
    void update();

    /// Updates alle the widgets with the latest information about the objects they represent.
    void updateWidgets();

    /// If a new config is available the layout will be redrawn based on the new config.
    void updateConfig();

    std::unique_ptr<Bar> bar;

private:
    std::unique_ptr<BaseWidget> makeWidget(uint8_t pos);
    std::array<std::unique_ptr<BaseWidget>, 6> sensorWidgets{};
    lv_obj_t* mainContainer = nullptr;
    lv_obj_t* grid = nullptr;
};
