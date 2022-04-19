#include "ntp/Ntp.hpp"
#include "AppTicks.hpp"
#include "blox_hal/hal_delay.hpp"
#include "spark_wiring_network.h"
#include "spark_wiring_udp.h"
#include <memory>

namespace platform::particle {

static constexpr const char* serverName = "pool.ntp.org";
static constexpr uint16_t serverPort = 123;
static constexpr uint16_t localPort = 2123;
static constexpr uint16_t receiveTimeoutMs = 10 * 1000;
static constexpr uint32_t ntpEpochStart = 2208988800UL; // NTP time starts on 1-1-1900

struct __attribute__((packed)) NtpPacket {
    uint8_t flags{0x1B}; // Protocol version 3, client request
    uint32_t rootDispersion{0};
    uint32_t referenceIdentifier{0};
    uint64_t referenceTimeStamp{0};
    uint64_t originateTimeStamp{0};
    uint64_t receiveTimestamp{0};
    uint32_t seconds{0};
    uint32_t fractions{0};
};

utc_seconds_t requestUtcSeconds()
{
    auto client = UDP();
    NtpPacket packet;
    uint8_t* packetPtr = reinterpret_cast<uint8_t*>(std::addressof(packet));

    auto network = spark::Network.from(0);
    // while (!network.ready()) {
    //     hal_yield();
    //     ticks.delayMillis(500);
    // }

    auto serverAddr = network.resolve(serverName);

    auto beginOk = client.begin(localPort);
    auto sent = client.sendPacket(packetPtr, sizeof(packet), serverAddr, serverPort);

    // ticks.delayMillis(1000);
    ticks_millis_t recvStartAt = ticks.millis();
    auto recv = client.receivePacket(packetPtr, sizeof(packet), 1000);
    ticks_millis_t recvEndAt = ticks.millis();
    client.stop();

    if (packet.seconds == 0) {
        return 0;
    }

    uint32_t ntp_millis = static_cast<uint32_t>(packet.fractions / 0xffffffff * 1000);
    ntp_millis += (recvEndAt - recvStartAt) / 2;
    packet.seconds += (ntp_millis / 1000);

    return packet.seconds - ntpEpochStart;
}

} // end namespace platform::particle
