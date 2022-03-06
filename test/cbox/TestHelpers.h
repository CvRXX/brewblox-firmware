// helper function for testing. Appends the CRC to a hex string, the same way CrcDataOut would do
#pragma once
#include "cbox/Command.h"
#include <sstream>
#include <string>

namespace cbox {
std::string addCrc(const std::string& in);
std::string crc(const std::string& in);

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
public:
    std::vector<Payload> responses;
    CboxError nextError = CboxError::OK;

    TestCommand(CboxOpcode _opcode,
                std::optional<Payload>&& _requestPayload = std::nullopt)
        : Command(1, _opcode, std::move(_requestPayload))
    {
    }

    TestCommand(CboxOpcode _opcode,
                obj_id_t _blockId,
                obj_type_t _blockType)
        : Command(1, _opcode, std::move(Payload(_blockId, _blockType, 0)))
    {
    }

    virtual ~TestCommand() = default;

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
}
