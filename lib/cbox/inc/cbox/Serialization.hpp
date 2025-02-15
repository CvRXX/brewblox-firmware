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
bool readFromByteVector(const std::vector<uint8_t>& in, T& v, int pos)
{
    if (pos + sizeof(T) > in.size()) {
        return false;
    }
    memcpy(reinterpret_cast<uint8_t*>(std::addressof(v)),
           std::addressof(in[pos]),
           sizeof(T));

    return true;
}

template <typename T>
bool appendToByteVector(std::vector<uint8_t>& out, const T& v)
{
    out.reserve(out.size() + sizeof(T));
    auto* ptr = reinterpret_cast<const uint8_t*>(std::addressof(v));
    auto* dataEnd = ptr + sizeof(T);
    while (ptr < dataEnd) {
        out.push_back(*ptr);
        ++ptr;
    }
    return true;
}

CboxExpected<Request> parseRequest(const std::string& b64Bytes);

CboxExpected<std::string> encodeResponse(const Payload& payload);
CboxExpected<std::string> encodeResponse(uint32_t msgId, CboxError status);
}
