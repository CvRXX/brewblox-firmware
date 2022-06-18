#include "cbox/PayloadConversion.hpp"
#include <algorithm>
#include <pb_decode.h>
#include <pb_encode.h>

namespace cbox {

bool PayloadParser::fillMessage(void* destStruct,
                                const pb_field_t fields[])
{
    auto& protoBytes = _payload.content;
    auto stream = pb_istream_from_buffer(protoBytes.data(), protoBytes.size());
    bool success = pb_decode(&stream, fields, destStruct);

    if (!success) {
        _status = cbox::CboxError::NETWORK_DECODING_ERROR;
    }
    return _status == cbox::CboxError::OK;
}

bool PayloadParser::hasField(cbox::obj_field_tag_t tag) const
{
    auto mode = _payload.maskMode;
    auto& mask = _payload.mask;

    // No need to check the mask
    if (mode == MaskMode::ANY) {
        return true;
    }

    // Find the tag in the mask
    // Whether this includes or excludes the field depends on the mode
    auto masked = std::find(mask.cbegin(), mask.cend(), tag) != mask.cend();

    if (mode == MaskMode::EXCLUSIVE) {
        return !masked;
    }

    // inclusive
    return masked;
}

PayloadBuilder& PayloadBuilder::withStatus(cbox::CboxError status)
{
    _status = status;
    return *this;
}

PayloadBuilder& PayloadBuilder::withContent(const void* srcStruct,
                                            const pb_field_t fields[],
                                            size_t maxSize)
{
    auto& protoBytes = _payload.content;
    protoBytes.resize(maxSize);
    auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());
    bool success = pb_encode(&stream, fields, srcStruct);

    if (success) {
        protoBytes.resize(stream.bytes_written);
    } else {
        _status = CboxError::NETWORK_ENCODING_ERROR;
    }

    return *this;
}

PayloadBuilder& PayloadBuilder::withMask(MaskMode mode,
                                         std::vector<obj_field_tag_t>&& mask)
{
    _payload.maskMode = mode;
    _payload.mask.swap(mask);
    return *this;
}

PayloadBuilder& PayloadBuilder::respond(const PayloadCallback& callback)
{
    if (_status == CboxError::OK) {
        _status = callback(_payload);
    }
    return *this;
}

} // end namespace cbox
