#pragma once
#include "cbox/Payload.hpp"
#include <google/protobuf/message.h>
#include <sstream>
#include <string>

namespace cbox {
/* Wrapper class around std::stringstream that clears error flags when new data is added.
 * Otherwise EOF flag is still set after data has been added to the stream
 */
class StringStreamAutoClear : public std::stringstream {
public:
    template <typename T>
    StringStreamAutoClear& operator<<(T& v)
    {
        std::stringstream& s = *this;
        s.clear(); // clear error flags
        s << v;
        return *this;
    }
};

class TestCommand {
public:
    Payload request;
    std::vector<Payload> responses;
    std::function<cbox::CboxError(const cbox::Payload&)> callback;

    TestCommand()
        : request(0, 0, 0)
    {
        initCallback();
    }

    explicit TestCommand(Payload&& request_)
        : request(std::move(request_))
    {
        initCallback();
    }

    TestCommand(obj_id_t blockId_,
                obj_type_t blockType_,
                std::initializer_list<uint8_t>&& content_ = {})
        : request(blockId_, blockType_, 0, std::move(content_))
    {
        initCallback();
    }

    void initCallback()
    {
        callback = [this](const cbox::Payload& payload) {
            responses.push_back(
                Payload(payload.blockId,
                        payload.blockType,
                        payload.subtype,
                        std::vector<uint8_t>(payload.content)));
            return CboxError::OK;
        };
    }

    virtual ~TestCommand() = default;
};
} // end namespace cbox

std::string hexed(const std::vector<uint8_t>& data);

void decodeProtoFromReply(std::stringstream& ss, ::google::protobuf::Message& message);

void messageToPayload(cbox::Payload& payload, ::google::protobuf::Message& message);

void messageToPayload(cbox::TestCommand& cmd, ::google::protobuf::Message& message);

void payloadToMessage(cbox::Payload& payload, ::google::protobuf::Message& message);

void payloadToMessage(cbox::TestCommand& cmd, ::google::protobuf::Message& message);
