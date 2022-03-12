/*
 * Copyright 2017 BrewPi
 *
 * This file is part of BrewPi.
 *
 * BrewPi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BrewPi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BrewPi.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AppBox.h"
#include "AppTicks.h"
#include "blox_hal/hal_i2c.h"
#include "cbox/Box.h"
#include "cbox/Object.h"
#include "control/TimerInterrupts.h"
#include "d4d_display/d4d.hpp"
#include "d4d_display/screens/WidgetsScreen.h"
#include "d4d_display/screens/listening_screen.h"
#include "d4d_display/screens/startup_screen.h"
#include "delay_hal.h"
#include "eeprom_hal.h"
#include "proto/proto_version.h"
#include "spark/Board.h"
#include "spark/Brewblox.h"
#include "spark/Buzzer.h"
#include "spark/Connectivity.h"
#include "spark_wiring_startup.h"
#include "spark_wiring_system.h"
#include "spark_wiring_timer.h"

#if PLATFORM_ID == PLATFORM_GCC
#include <csignal>
#endif

#if PLATFORM_THREADING
#include "spark_wiring_watchdog.h"
#else
class ApplicationWatchdog {
public:
    ApplicationWatchdog(unsigned /*timeout_ms*/, std::function<void(void)> /*fn*/, unsigned /*stack_size*/) {}
    void checkin() {}
};
#endif

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);
STARTUP(
    System.enableFeature(FEATURE_RESET_INFO);
    System.enableFeature(FEATURE_RETAINED_MEMORY);
    System.disableFeature(FEATURE_WIFI_POWERSAVE_CLOCK););

#if PLATFORM_ID == PLATFORM_GCC
void signal_handler(int signal)
{
    exit(signal);
}
#endif

ApplicationWatchdog* appWatchdog = nullptr;

void watchdogReset()
{
    app::reset(true, UserResetReason::WATCHDOG);
}

inline void watchdogCheckin()
{
    if (appWatchdog) {
        appWatchdog->checkin();
    }
}

void displayTick()
{
    static ticks_millis_t lastTick = -40;
    auto now = ticks.millis();
    if (now > lastTick + 40) {
        lastTick = now;
        D4D_Poll();
        D4D_CheckTouchScreen();
        D4D_TimeTickPut();
        D4D_FlushOutput();
    }
}

void onSetupModeBegin()
{
    ListeningScreen::activate();
    manageConnections(ticks.millis()); // stop http server
    cbox::unloadAllObjects();
    getConnectionPool().disconnect();
    HAL_Delay_Milliseconds(100);
}

void onSetupModeEnd()
{
    app::reset(true, UserResetReason::LISTENING_MODE_EXIT);
}

void onOutOfMemory(system_event_t event, int param)
{
    // reboot when out of memory, better than undefined behavior
    app::reset(true, UserResetReason::OUT_OF_MEMORY);
}

void setup()
{
// Install a signal handler
#if PLATFORM_ID == PLATFORM_GCC
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);
    // pin map is not initialized properly in gcc build before setup runs
    boardInit();
    manageConnections(0); // init network early to websocket display emulation works during setup()
#else
    boardInit();
    Buzzer.beep(2, 50);
    HAL_Delay_Milliseconds(1);
#endif
    appWatchdog = new ApplicationWatchdog(60000, watchdogReset, 256);
    hal_i2c_master_init();

    // init display
    D4D_Init(nullptr);
    D4D_TOUCHSCREEN_CALIB defaultCalib = {1, 0, 0, 64, 64};
    D4D_TCH_SetCalibration(defaultCalib);

    StartupScreen::activate();
    HAL_Delay_Milliseconds(1);

    StartupScreen::setProgress(10);
    StartupScreen::setStep("Power cycling peripherals");

    do {
        StartupScreen::setProgress(ticks.millis() / 40); // up to 50
        displayTick();
    } while (ticks.millis() < ((PLATFORM_ID != PLATFORM_GCC) ? 2000 : 0));

    enablePheripheral5V(true);

    HAL_Delay_Milliseconds(1);
    StartupScreen::setProgress(60);
    StartupScreen::setStep("Init Brewblox framework");
    setupSystemBlocks();
    HAL_Delay_Milliseconds(1);

    StartupScreen::setProgress(70);
    StartupScreen::setStep("Loading blocks");
    cbox::loadObjectsFromStorage();
    HAL_Delay_Milliseconds(1);

    StartupScreen::setProgress(90);
    StartupScreen::setStep("Scanning for new devices");
    cbox::discoverNewObjects();

    StartupScreen::setProgress(90);
    StartupScreen::setStep("Enabling WiFi and mDNS");
    wifiInit();
    HAL_Delay_Milliseconds(1);

    StartupScreen::setProgress(100);
    StartupScreen::setStep("Ready!");

    // perform pending EEPROM erase while we're waiting. Can take up to 500ms and stalls all code execution
    // This avoids having to do it later when writing to EEPROM
    HAL_EEPROM_Perform_Pending_Erase();

#if PLATFORM_ID != PLATFORM_GCC
    TimerInterrupts::init();
    System.on(setup_begin, onSetupModeBegin);
    System.on(setup_end, onSetupModeEnd);
    System.on(out_of_memory, onOutOfMemory);
#endif

    getConnectionPool().startAll();
    WidgetsScreen::activate();
}

void loop()
{
    ticks.switchTaskTimer(TicksClass::TaskId::DisplayUpdate);
    displayTick();
    if (!listeningModeEnabled()) {
        ticks.switchTaskTimer(TicksClass::TaskId::Communication);
        manageConnections(ticks.millis());
        app::communicate();

        ticks.switchTaskTimer(TicksClass::TaskId::BlocksUpdate);
        app::update();

        watchdogCheckin(); // not done while listening, so 60s timeout for stuck listening mode
    }
    ticks.switchTaskTimer(TicksClass::TaskId::System);
    HAL_Delay_Milliseconds(1);
}

constexpr bool equal(char const* lhs, char const* rhs)
{
    while (*lhs || *rhs)
        if (*lhs++ != *rhs++)
            return false;
    return true;
}

// Intellisense fails to include the quotes in PROTO_VERSION
#ifndef __INTELLISENSE__
static_assert(equal(PROTO_VERSION, COMPILED_PROTO_VERSION));
#endif
