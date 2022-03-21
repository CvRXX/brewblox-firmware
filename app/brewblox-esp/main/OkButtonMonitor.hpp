#pragma once

#include "RecurringTask.hpp"
#include "drivers/Spark4.hpp"
#include <asio.hpp>
#include <functional>
#include <vector>

// The OK button shares a pin with the ADC input to read the 5V rail to save a pin.
// When the button is pressed, the voltage is out of the normal range.
// The ADC is read continuously and button presses are registered. When the button is not pressed, the 5V rail voltage is updated.

class OkButtonMonitor {
public:
    struct handler {
        uint32_t held_min;
        uint32_t held_max;
        std::function<void()> callback;
    };

private:
    asio::chrono::steady_clock::time_point lowToHigh;
    asio::chrono::steady_clock::time_point highToLow;
    asio::chrono::steady_clock::time_point lastBeep;
    RecurringTask adcReader;
    const std::vector<handler> actions;

public:
    OkButtonMonitor(asio::io_context& io, std::initializer_list<handler> handlers)
        : adcReader{io, asio::chrono::milliseconds(30),
                    RecurringTask::IntervalType::FROM_EXPIRY,
                    [this]() -> bool {
                        this->update();
                        return true;
                    }}
        , actions(handlers)
    {
        auto now = asio::chrono::steady_clock::now();
        lowToHigh = now;
        highToLow = now;
        lastBeep = now;
    }

    void start()
    {
        adcReader.start();
    }

    void stop()
    {
        adcReader.stop();
    }

private:
    void update()
    {
        auto voltage = spark4::adcRead5V();
        auto now = asio::chrono::steady_clock::now();

        if (voltage < 2000u) {
            if (lowToHigh >= highToLow) {
                // high to low transition
                lastBeep = now;
                highToLow = now;
            } else {
                // low hold
                auto now = asio::chrono::steady_clock::now();
                auto sinceBeep = asio::chrono::duration_cast<asio::chrono::milliseconds>(now - lastBeep).count();
                if (sinceBeep >= 5000) {
                    spark4::startup_beep();
                    lastBeep = now;
                }
            }
        } else if (lowToHigh <= highToLow) {
            // low to high transition
            lowToHigh = asio::chrono::steady_clock::now();
            uint32_t duration = asio::chrono::duration_cast<asio::chrono::milliseconds>(lowToHigh - highToLow).count();

            handleRelease(duration);
        }
    }

    void handleRelease(uint32_t duration)
    {
        for (auto& action : actions) {
            if (duration >= action.held_min && duration < action.held_max) {
                action.callback();
                return;
            }
        }
    }
};
