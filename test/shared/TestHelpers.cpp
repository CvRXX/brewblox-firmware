#include "TestHelpers.hpp"
#include "cbox/Hex.hpp"
#include <google/protobuf/message.h>

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
