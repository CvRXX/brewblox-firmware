#pragma once
#include "cbox/Command.h"
#include "cbox/DataStream.h"
#include "cbox/DataStreamConverters.h"
#include "cbox/DataStreamIo.h"
#include <google/protobuf/message.h>
#include <sstream>
#include <string>

namespace cbox {
std::string addCrc(const std::string& in);
std::string crc(const std::string& in);
std::string hexed(const std::vector<uint8_t>& data);

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

class TestCommand : public Command {
private:
    std::unique_ptr<Payload> _request;

public:
    CboxError nextError = CboxError::OK;
    std::vector<Payload> responses;

    TestCommand()
    {
    }

    TestCommand(Payload&& _payload)
        : _request(std::make_unique<Payload>(std::move(_payload)))
    {
    }

    TestCommand(obj_id_t _blockId,
                obj_type_t _blockType,
                std::initializer_list<uint8_t>&& _content = {})
        : _request(std::make_unique<Payload>(_blockId, _blockType, 0, std::move(_content)))
    {
    }

    virtual ~TestCommand() = default;

    virtual Payload* request() override final
    {
        return _request.get();
    }

    virtual CboxError respond(const Payload& payload) override final
    {
        responses.push_back(
            Payload(payload.blockId,
                    payload.blockType,
                    payload.subtype,
                    std::vector<uint8_t>(payload.content)));
        return nextError;
    }
};
} // end namespace cbox

namespace google {
namespace protobuf {
    class Message;
}
}

class ProtoDataOut {
public:
    cbox::EncodedDataOut& out;
    ProtoDataOut(cbox::EncodedDataOut& target)
        : out(target)
    {
    }

    void put(const ::google::protobuf::Message& message);
};

void decodeProtoFromReply(std::stringstream& ss, ::google::protobuf::Message& message);

void serializeToRequest(cbox::Command& cmd, ::google::protobuf::Message& message);

void parseFromResponse(cbox::Payload& payload, ::google::protobuf::Message& message);

void parseFromResponse(cbox::TestCommand& cmd, ::google::protobuf::Message& message);
