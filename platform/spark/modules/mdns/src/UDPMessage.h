#pragma once
#include "spark_wiring_udp.h"
#include <string>

class UDPMessage {
private:
    std::string buf;

public:
    UDPMessage() {}
    ~UDPMessage() = default;

    uint16_t writeOffset()
    {
        return buf.size();
    }

    void put(uint8_t v)
    {
        buf.push_back(v);
    }

    void put(uint16_t v)
    {
        buf.push_back(uint8_t(v >> 8 & 0xff));
        buf.push_back(uint8_t(v & 0xff));
    }

    void put(uint32_t v)
    {
        buf.push_back(uint8_t((v >> 24) & 0xff));
        buf.push_back(uint8_t((v >> 16) & 0xff));
        buf.push_back(uint8_t((v >> 8) & 0xff));
        buf.push_back(uint8_t(v & 0xff));
    }

    void put(const std::string& s)
    {
        if (!s.empty()) {
            buf.append(s);
        }
    }

    int send(UDP& udp, IPAddress ip, uint16_t port)
    {
        if (buf.empty()) {
            return 0;
        }
        const uint8_t* data = reinterpret_cast<const uint8_t*>(buf.data());
        size_t size = buf.size();
        return udp.sendPacket(data, size, ip, port);
    }
};