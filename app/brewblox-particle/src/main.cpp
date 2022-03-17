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

#include "AppTicks.h"
#include "blocks/stringify.h"
#include "blox_hal/hal_i2c.h"
#include "brewblox_particle.hpp"
#include "cbox/Box.h"
#include "cbox/Object.h"
#include "connectivity.h"
#include "control/TimerInterrupts.h"
#include "d4d_display/d4d.hpp"
#include "d4d_display/screens/WidgetsScreen.h"
#include "d4d_display/screens/listening_screen.h"
#include "d4d_display/screens/startup_screen.h"
#include "delay_hal.h"
#include "eeprom_hal.h"
#include "reset.h"
#include "spark/Board.h"
#include "spark/Buzzer.h"
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
    System.reset(RESET_USER_REASON::WATCHDOG, RESET_NO_WAIT);
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
    brewbloxBox().unloadAllObjects();
    brewbloxBox().disconnect();
    HAL_Delay_Milliseconds(100);
}

void onSetupModeEnd()
{
    System.reset(RESET_USER_REASON::LISTENING_MODE_EXIT, RESET_NO_WAIT);
}

void onOutOfMemory(system_event_t event, int param)
{
    // reboot when out of memory, better than undefined behavior
    System.reset(RESET_USER_REASON::OUT_OF_MEMORY, RESET_NO_WAIT);
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
    cbox::tracing::pause(); // ensure tracing is paused until service resumes it

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
    brewbloxBox();

    HAL_Delay_Milliseconds(1);

    StartupScreen::setProgress(70);
    StartupScreen::setStep("Loading blocks");
    brewbloxBox().loadObjectsFromStorage(); // init box and load stored objects
    HAL_Delay_Milliseconds(1);

    StartupScreen::setProgress(90);
    StartupScreen::setStep("Scanning for new devices");
    brewbloxBox().discoverNewObjects();

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

    brewbloxBox().startConnectionSources();
    WidgetsScreen::activate();
}

void loop()
{
    ticks.switchTaskTimer(TicksClass::TaskId::DisplayUpdate);
    cbox::tracing::add(AppTrace::UPDATE_DISPLAY);
    displayTick();
    if (!listeningModeEnabled()) {
        ticks.switchTaskTimer(TicksClass::TaskId::Communication);
        manageConnections(ticks.millis());
        brewbloxBox().hexCommunicate();

        ticks.switchTaskTimer(TicksClass::TaskId::BlocksUpdate);
        updateBrewbloxBox();

        watchdogCheckin(); // not done while listening, so 60s timeout for stuck listening mode
    }
    ticks.switchTaskTimer(TicksClass::TaskId::System);
    cbox::tracing::add(AppTrace::SYSTEM_TASKS);
    HAL_Delay_Milliseconds(1);
}

void handleReset(bool exitFlag, uint8_t reason)
{
    if (exitFlag) {
#if PLATFORM_ID == PLATFORM_GCC
        exit(0);
#else
        System.reset(reason, RESET_NO_WAIT);
#endif
    }
}
