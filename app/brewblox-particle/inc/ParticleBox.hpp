#pragma once

enum UserResetReason {
    NOT_SPECIFIED = 0,
    WATCHDOG = 1,
    CBOX_RESET = 2,
    CBOX_FACTORY_RESET = 3,
    FIRMWARE_UPDATE_FAILED = 4,
    LISTENING_MODE_EXIT = 5,
    FIRMWARE_UPDATE_SUCCESS = 6,
    OUT_OF_MEMORY = 7,
};

namespace app {

void update();

void communicate();

void reset(bool exit,
           UserResetReason reason = UserResetReason::NOT_SPECIFIED);

} // end namespace app
