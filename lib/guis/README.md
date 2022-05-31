# GUI composition
GUI's for the brewblox firmware are a composition of a display, a touchscreen and an interface. The composition results into a clear separation of concerns. Because of this, adding new hardware or interface is very easy.

An example composition:
```
using gui = Gui<TFT035, FT6236, StaticGui>;
```

## Displays
The display type represents an output for pixels. This can either be a physical display or an emulated one. The display must implement the following functions/attributes:
  \
  \
**`constructor(void (*finishCallback)(void))`**

The constructor gets passed a lambda which should be called when the writing is complete. This indicates to the gui that a new line can be set.

**`init()`**

Initialises the driver.

**`lock()`**

  Locks the driver for usage. This is usefull for display which have multiple users of which only one can right at the same time.

**`unlock()`**

  Unlocks the driver after usage.

**`writePixels(unsigned int xs, unsigned int xe, unsigned int ys, unsigned int ye, const uint8_t* pixels, uint16_t nPixels)`**

  Writes pixels to the display.

**`horResolution`**

The horizontal resolution of the display in pixels.

**`verResolution`**

The Vertical resolution of the display in pixels.

**`rotation`**

The orientation of the display in degrees.

**`pixelFormat`**

The format in which the driver expects the pixels to be.

### lvlg_screen
The lvgl_screen decorator is used to turn a generic display type into an type which can be used by LVGL. Any type which furfills the above spec can be used.

## Touchscreens
Touchscreens can be used to allow for input. Touchscreen types must implement the following functions/attributes:

**`init()`**

Initialises the driver.

**```getLastTouch()```**

Returns the last touch that happened.

**```getTouch()```**

If a touch is currently happening it will return  the touch. When none are happening a `std::nullopt` is returned.

### lvlg_touchscreen
The lvgl_touchscreen decorator is used to turn a generic touchscreen type into an type which can be used by LVGL. Any type which furfills the above spec can be used.

## Interfaces
The last type required for a gui is the interface type. This type is the interface that is being used. Using an interface type multiple interfaces can be used and developed.

An interface type must include the following functions/attributes:

**```update()```**

Called every gui tick to update it's components.
