#pragma once

#include "cbox/Payload.hpp"
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

namespace cbox {

enum class Opcode : uint8_t {
    NONE = 0,
    VERSION = 1,

    BLOCK_READ = 10,
    BLOCK_READ_ALL = 11,
    BLOCK_WRITE = 12,
    BLOCK_CREATE = 13,
    BLOCK_DELETE = 14,
    BLOCK_DISCOVER = 15,

    STORAGE_READ = 20,
    STORAGE_READ_ALL = 21,

    REBOOT = 30,
    CLEAR_BLOCKS = 31,
    CLEAR_WIFI = 32,
    FACTORY_RESET = 33,

    FIRMWARE_UPDATE = 40,
};

class Request {
public:
    const uint32_t msgId;
    const Opcode opcode;
    const Payload payload;

    Request(uint32_t msgId_, Opcode opcode_, Payload&& payload_)
        : msgId(msgId_)
        , opcode(opcode_)
        , payload(std::move(payload_))
    {
    }

    Request(Request&) = delete;
    Request& operator=(const Request&) = delete;

    Request(Request&&) = default;
    ~Request() = default;
};

template <typename T>
bool vectorRead(const std::vector<uint8_t>& in, T& v, size_t pos)
{
    if (pos + sizeof(T) > in.size()) {
        return false;
    }
    auto p = reinterpret_cast<uint8_t*>(&v);
    std::memcpy(p, in.data() + pos, sizeof(T));
    return true;
}

template <typename T>
bool vectorWrite(std::vector<uint8_t>& out, const T& v, size_t pos)
{
    if (pos + sizeof(T) > out.size()) {
        return false;
    }
    auto p = reinterpret_cast<const uint8_t*>(std::addressof(v));
    std::memcpy(out.data() + pos, p, sizeof(T));
    return true;
}

template <typename T>
bool vectorAppend(std::vector<uint8_t>& out, const T& v)
{
    auto pos = out.size();
    out.resize(pos + sizeof(T));
    return vectorWrite<T>(out, v, pos);
}

CboxExpected<Request> parseRequest(const std::string& b64Bytes);

CboxExpected<std::string> encodeResponse(const Payload& payload);
CboxExpected<std::string> encodeResponse(uint32_t msgId, CboxError status);
}
