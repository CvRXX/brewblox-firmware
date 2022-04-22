#include "ntp/Ntp.hpp"
#include "AppTicks.hpp"
#include "blox_hal/hal_delay.hpp"
#include "endian_util.h"
#include "random.h"
#include "rtc_hal.h"
#include "spark_wiring_network.h"
#include "spark_wiring_udp.h"
#include <memory>

namespace platform::particle {

using ::particle::bigEndianToNative;
using ::particle::nativeToBigEndian;

static constexpr const char* SERVER_NAME = "pool.ntp.org";
static constexpr uint16_t SERVER_PORT = 123;
static constexpr uint16_t LOCAL_PORT = 2123;

static constexpr uint8_t NTP_VERSION_4 = 4 << 3;
static constexpr uint8_t NTP_MODE_CLIENT = 3;
static constexpr uint32_t SECONDS_FROM_1970_TO_1900 = 2208988800UL;
static constexpr uint32_t USEC_IN_SEC = 1000000;
static constexpr uint32_t FRACTIONS_IN_SEC_POW = 32;

struct Timestamp {
    uint32_t seconds;
    uint32_t fraction;

    // // 64-bit NTP timestamp consists of 32-bit seconds field since 1900/01/01 00:00:00
    // // and 32-bit fractional field with a resolution of 2^(-32) seconds (232.830644 picoseconds).
    // // Both fields are represented in network order on the wire.

    // 1. Convert seconds epoch from NTP (Jan 1 1900) to Unixtime (Jan 1 1970) by subtracting the number of
    //    seconds that have passed since Jan 1 1900 till Jan 1 1970 (SECONDS_FROM_1970_TO_1900)
    // 2. For the fraction part, we are converting from 2^(-32) fractional seconds to microseconds (10^(-6))
    //    M * 10^(-6) = F * 2^(-32)
    //    M = F * 2^(-32) / 10^(-6) = F * 10^6 / 2^32
    uint64_t toUnixtime() const
    {
        uint64_t unixMicros = (uint64_t)(bigEndianToNative(seconds) - SECONDS_FROM_1970_TO_1900) * USEC_IN_SEC;
        uint64_t frac = (((uint64_t)bigEndianToNative(fraction)) * USEC_IN_SEC) >> FRACTIONS_IN_SEC_POW;
        return unixMicros + frac;
    }
} __attribute__((packed));

struct __attribute__((packed)) NtpPacket {
    // | LI  | VN    | Mode  |
    // | - - | - - - | - - - |
    uint8_t flags = NTP_MODE_CLIENT | NTP_VERSION_4;
    uint8_t stratum{0};
    uint8_t pollInterval{0};
    int8_t precision{0};
    int32_t rootDelay{0};
    uint32_t rootDispersion{0};
    uint32_t referenceIdentifier{0};
    Timestamp referenceTimestamp{0};
    Timestamp originTimestamp{0};
    Timestamp receiveTimestamp{0};
    Timestamp serverTimestamp{0};
};

void setRtcTime(uint64_t unixMicros)
{
    struct timeval tv = {
        .tv_sec = static_cast<time_t>(unixMicros / USEC_IN_SEC),
        .tv_usec = static_cast<suseconds_t>(unixMicros % USEC_IN_SEC),
    };
    hal_rtc_set_time(&tv, nullptr);
}

bool synchronizeTime()
{
    auto client = UDP();
    if (!client.begin(LOCAL_PORT)) {
        return false;
    }

    NtpPacket packet;
    uint8_t* packetPtr = reinterpret_cast<uint8_t*>(std::addressof(packet));
    auto serverAddr = spark::Network.from(0).resolve(SERVER_NAME);

    // Send packet without allocating a buffer in the UDP client
    client.sendPacket(packetPtr, sizeof(packet), serverAddr, SERVER_PORT);

    for (auto i = 0; i < 50; i++) {
        // Read packet directly from socket into `packet`
        // Again, this prevents having to allocate a buffer in the UDP client
        if (client.receivePacket(packetPtr, sizeof(packet))) {
            break;
        }
        ticks.delayMillis(10);
    }

    client.stop();

    // Check if (valid) data was received
    if (packet.stratum == 0) {
        return false;
    }

    setRtcTime(packet.serverTimestamp.toUnixtime());
    return true;
}

} // end namespace platform::particle
