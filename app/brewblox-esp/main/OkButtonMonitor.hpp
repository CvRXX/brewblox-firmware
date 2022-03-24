#pragma once

#include "BeepTask.hpp"
#include "RecurringTask.hpp"
#include "drivers/Spark4.hpp"
#include <asio.hpp>
#include <functional>
#include <memory>
#include <vector>

// The OK button shares a pin with the ADC input to read the 5V rail to save a pin.
// When the button is pressed, the voltage is out of the normal range.
// The ADC is read continuously and button presses are registered. When the button is not pressed, the 5V rail voltage is updated.

class OkButtonMonitor {
private:
    asio::chrono::steady_clock::time_point lowToHigh;
    asio::chrono::steady_clock::time_point highToLow;
    asio::chrono::steady_clock::time_point lastBeep;
    static constexpr auto actionInterval = uint32_t(5000);
    asio::io_context& io;
    RecurringTask adcReader;
    const std::vector<std::function<void()>> actions;

public:
    OkButtonMonitor(asio::io_context& ioc, std::initializer_list<decltype(actions)::value_type> handlers)
        : io(ioc)
        , adcReader{ioc, asio::chrono::milliseconds(30),
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
                // high to low transition (press)
                highToLow = now;
            } else {
                // stayed low (hold)
                auto sinceBeep = asio::chrono::duration_cast<asio::chrono::milliseconds>(now - lastBeep).count();
                if (sinceBeep >= actionInterval) {
                    lastBeep = now;
                    auto sincePress = asio::chrono::duration_cast<asio::chrono::milliseconds>(now - highToLow).count();
                    auto beeps = std::vector<BeepTone>{{Beep::MID, 200}};
                    // add extra beep for every interval
                    while (sincePress > actionInterval) {
                        beeps.push_back({Beep::OFF, 200});
                        beeps.push_back({Beep::MID, 200});
                        sincePress -= actionInterval;
                    }

                    start_beep_pattern(io, std::move(beeps));
                }
            }
        } else if (lowToHigh <= highToLow) {
            // low to high transition (release)
            lowToHigh = asio::chrono::steady_clock::now();
            uint32_t duration = asio::chrono::duration_cast<asio::chrono::milliseconds>(lowToHigh - highToLow).count();

            // set last beep time in the past to start with a beep when pressed
            lastBeep = lowToHigh - std::chrono::milliseconds(actionInterval);

            // perform action
            auto actionIdx = duration / actionInterval;
            auto action_it = std::begin(actions) + actionIdx;
            if (action_it < std::end(actions)) {
                (*action_it)();
            }
        }
    }
};
