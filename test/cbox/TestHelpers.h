// helper function for testing. Appends the CRC to a hex string, the same way CrcDataOut would do
#pragma once
#include "cbox/Command.h"
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
