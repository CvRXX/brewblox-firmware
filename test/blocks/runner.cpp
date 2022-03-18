#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_CONSOLE_WIDTH 300 // workaround for compatiblity with vscode Test Explorer

#include "deviceid_hal.h"
#include <catch.hpp>

/* mock implementation for device ID */
unsigned
HAL_device_ID(uint8_t* dest, unsigned destLen)
{
    if (dest != nullptr && destLen != 0)
        memset(dest, '9', destLen);
    return destLen;
}
