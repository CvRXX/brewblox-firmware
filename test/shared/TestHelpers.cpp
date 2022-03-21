#include "TestHelpers.hpp"
#include "cbox/Crc.hpp"
#include "cbox/Hex.hpp"
#include <google/protobuf/message.h>

/*
 * calculates 2 CRC characters to a hex string, used for testing
 */
std::string
crc(const std::string& in)
{
    std::string result;
    uint8_t crc = 0;
    for (auto it = in.begin(); it != in.end() && it + 1 != in.end();) {
        char char1 = *(it++);
        char char2 = *(it++);
        crc = cbox::calc_crc_8(crc, cbox::h2d(char1, char2));
    }
    auto pair = cbox::d2h(crc);
    result += pair.first;
    result += pair.second;

    return result;
}

/*
 * Appends 2 CRC characters to a hex string, used for testing
 */
std::string
addCrc(const std::string& in)
{
    return in + crc(in);
}

std::string hexed(const std::vector<uint8_t>& data)
{
    std::string retv;
    retv.reserve(data.size() * 2);
    for (auto v : data) {
        auto pair = cbox::d2h(v);
        retv += pair.first;
        retv += pair.second;
    }
    return retv;
}

void messageToPayload(cbox::Payload& payload, ::google::protobuf::Message& message)
{
    size_t len = message.ByteSizeLong();
    payload.content.resize(len);
    message.SerializeToArray(payload.content.data(), len);
}

void messageToPayload(cbox::TestCommand& cmd, ::google::protobuf::Message& message)
{
    size_t len = message.ByteSizeLong();
    cmd.request.content.resize(len);
    message.SerializeToArray(cmd.request.content.data(), len);
}

void payloadToMessage(cbox::Payload& payload, ::google::protobuf::Message& message)
{
    message.ParseFromArray(payload.content.data(), payload.content.size());
}

void payloadToMessage(cbox::TestCommand& cmd, ::google::protobuf::Message& message)
{
    return payloadToMessage(cmd.responses.at(0), message);
}
