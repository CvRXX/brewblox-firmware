#include "TestHelpers.h"
#include "cbox/Crc.h"
#include "cbox/hex_utility.h"
#include <google/protobuf/message.h>

namespace cbox {
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
        uint8_t data = (h2d(char1) << 4) | h2d(char2);
        crc = calc_crc(crc, data);
    }
    result.push_back(d2h(uint8_t(crc & 0xF0) >> 4));
    result.push_back(d2h(uint8_t(crc & 0xF)));

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
        retv += d2h(uint8_t(v & 0xF0) >> 4);
        retv += d2h(uint8_t(v & 0xF));
    }
    return retv;
}

} // end namespace cbox

void ProtoDataOut::put(const ::google::protobuf::Message& message)
{
    for (auto& c : message.SerializeAsString()) {
        out.write(c);
    }
    out.write(0); // zero terminate protobuf message
}

void decodeProtoFromReply(std::stringstream& ss, ::google::protobuf::Message& message)
{
    cbox::IStreamDataIn hex(ss);
    cbox::HexTextToBinaryIn decoder(hex);
    while (hex.read() != '|') { // spool command echo
    }
    // spool status, id, groups and object type
    uint8_t header[6];
    decoder.readBytes(header, 6);

    // pass the rest to the protobuf decoder
    std::stringstream ssProto;
    cbox::OStreamDataOut protoData(ssProto);
    decoder.push(protoData);
    message.ParseFromIstream(&ssProto);
}

void serializeToRequest(cbox::Command& cmd, ::google::protobuf::Message& message)
{
    size_t len = message.ByteSizeLong();
    cmd.request()->content.resize(len);
    message.SerializeToArray(cmd.request()->content.data(), len);
    cmd.request()->content.push_back(0);
}

void parseFromResponse(cbox::Payload& payload, ::google::protobuf::Message& message)
{
    message.ParseFromArray(payload.content.data(), payload.content.size());
}

void parseFromResponse(cbox::TestCommand& cmd, ::google::protobuf::Message& message)
{
    return parseFromResponse(cmd.responses.at(0), message);
}
