#pragma once
#include "websocketserver.hpp"
#include <atomic>
#include <optional>
extern std::shared_ptr<listener> webSocketServer;

/**
 * A driver for the FT6236 touchscreen controller
 */
class VirtualTouchScreen {
public:
    /**
     * Constructs the driver
     *
     * @param address The lower address of the i2c device
     */
    VirtualTouchScreen(uint8_t address){};

    enum class Gesture {
        moveUp,
        moveRight,
        moveDown,
        moveLeft,
        zoomIn,
        zoomOut,
        noGesture
    };

    /// A structure to represent a touch event
    struct Touch {
        uint16_t x;      // The x position of where the touch happened on the screen
        uint16_t y;      // The y position of where the touch happened on the screen
        Gesture gesture; // A possible gesture that occurred during the touch
    };

    /// Initialises the driver, needs to be called before other functions
    void init() {}

    /** Returns the lastTouch that occurred.
     *  If no touch has happened it will return a touch at {0,0} with no gesture.
     */
    Touch getLastTouch()
    {
        return Touch{webSocketServer->touch.x, webSocketServer->touch.y, Gesture::noGesture};
    };

    /**
     * Checks if a touch is happening or happened.
     * @returns If a touch happened the touch otherwise std::nullopt
     */
    std::optional<Touch> getTouch()
    {
        if (webSocketServer->touch.touchAvailable) {
            webSocketServer->touch.touchAvailable = false;
            return Touch{webSocketServer->touch.x, webSocketServer->touch.y, Gesture::noGesture};
        }
        return std::nullopt;
    };

private:
    Gesture getGesture()
    {
        return Gesture::noGesture;
    }
};
