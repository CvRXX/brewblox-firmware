#pragma once

#include "drivers/Spark4.hpp"
#include <asio.hpp>
#include <initializer_list>
#include <memory>
#include <vector>

struct BeepTone {
    Beep freq;
    uint16_t duration;
};

class BeepTask : public std::enable_shared_from_this<BeepTask> {
public:
    explicit BeepTask(asio::io_context& io, std::vector<BeepTone>&& beeps)
        : m_timer(io)
        , m_beeps(std::move(beeps))
        , m_next_beep(std::begin(m_beeps))
    {
    }

    void run()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_next_beep != std::end(m_beeps)) {
            auto self(shared_from_this());

            auto duration = m_next_beep->duration;
            auto freq = m_next_beep->freq;
            ++m_next_beep;
            spark4::beep(freq);
            m_timer.expires_after(std::chrono::milliseconds(duration));
            m_timer.async_wait(
                [this, self](const asio::error_code& ec) {
                    if (!ec) {
                        run();
                    }
                });
        } else {
            spark4::beep(Beep::OFF);
        }
    }

    void cancel()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_timer.cancel();
    }

private:
    mutable std::mutex m_mutex;
    asio::steady_timer m_timer;
    std::vector<BeepTone> m_beeps;
    decltype(m_beeps)::const_iterator m_next_beep;
};

void start_beep_pattern(asio::io_context& io, std::vector<BeepTone>&& beeps)
{
    auto beeper = std::make_shared<BeepTask>(io, std::move(beeps));
    beeper->run();
}

void start_beep_pattern(asio::io_context& io, std::initializer_list<BeepTone> beeps)
{
    start_beep_pattern(io, std::vector<BeepTone>(beeps));
}
