#include "cbox/Serialization.hpp"
#include "cbox/Base64.hpp"
#include "proto/command.pb.h"
#include <pb_decode.h>
#include <pb_encode.h>

namespace cbox {

bool decodePayloadContent(pb_istream_t* stream, const pb_field_t* field, void** arg)
{
    auto payloadContent = static_cast<std::vector<uint8_t>*>(*arg);
    auto b64Content = std::string(stream->bytes_left, 0);
    if (!pb_read(stream, reinterpret_cast<uint8_t*>(b64Content.data()), b64Content.size())) {
        return false;
    }
    auto protoContent = b64_decode(b64Content);
    payloadContent->swap(protoContent);
    return true;
}

bool encodePayloadContent(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto payload = static_cast<const Payload*>(*arg);
    auto b64Content = b64_encode(payload->content);
    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }
    if (!pb_encode_string(stream, reinterpret_cast<uint8_t*>(b64Content.data()), b64Content.size())) {
        return false;
    }
    return true;
}

bool decodePayloadMask(pb_istream_t* stream, const pb_field_t* field, void** arg)
{
    auto payloadMask = static_cast<std::vector<obj_field_tag_t>*>(*arg);
    uint32_t tag = 0;
    while (stream->bytes_left) {
        if (!pb_decode_varint32(stream, &tag)) {
            return false;
        }
        payloadMask->push_back(tag);
    }
    return true;
}

bool encodePayloadMask(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto payload = static_cast<const Payload*>(*arg);
    for (auto tag : payload->mask) {
        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }
        if (!pb_encode_varint(stream, tag)) {
            return false;
        }
    }
    return true;
}

bool encodePayload(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto payload = static_cast<const Payload*>(*arg);
    command_Payload submsg = command_Payload_init_zero;

    submsg.blockId = payload->blockId;
    submsg.blockType = brewblox_BlockType(payload->blockType);
    submsg.subtype = payload->subtype;

    submsg.content.funcs.encode = &encodePayloadContent;
    submsg.content.arg = *arg;

    submsg.mask.funcs.encode = &encodePayloadMask;
    submsg.mask.arg = *arg;

    if (!pb_encode_tag_for_field(stream, field)) {
        return false;
    }

    if (!pb_encode_submessage(stream, command_Payload_fields, &submsg)) {
        return false;
    }

    return true;
}

CboxExpected<Request> parseRequest(const std::string& b64Bytes)
{
    if (b64Bytes.size() == 0) {
        return tl::make_unexpected(CboxError::NETWORK_READ_ERROR);
    }

    command_Request message = command_Request_init_zero;

    std::vector<uint8_t> payloadBytes;
    message.payload.content.funcs.decode = &decodePayloadContent;
    message.payload.content.arg = &payloadBytes;

    std::vector<obj_field_tag_t> payloadMask;
    message.payload.mask.funcs.decode = &decodePayloadMask;
    message.payload.mask.arg = &payloadMask;

    {
        auto protoBytes = b64_decode(b64Bytes);
        auto stream = pb_istream_from_buffer(protoBytes.data(), protoBytes.size());
        if (!pb_decode(&stream, command_Request_fields, &message)) {
            return tl::make_unexpected(CboxError::NETWORK_DECODING_ERROR);
        }
    }

    auto payload = Payload(message.payload.blockId,
                           message.payload.blockType,
                           message.payload.subtype,
                           static_cast<MaskMode>(message.payload.maskMode),
                           std::move(payloadBytes),
                           std::move(payloadMask));

    auto request = Request(message.msgId,
                           static_cast<Opcode>(message.opcode),
                           std::move(payload));

    return request;
}

CboxExpected<std::string> encodeResponse(const Payload& payload)
{
    command_Response message = command_Response_init_zero;
    size_t actualSize(0);

    // Don't set message ID yet. The response is invalid until finalized
    message.payload.funcs.encode = &encodePayload;
    message.payload.arg = const_cast<Payload*>(&payload); // will be cast to a const ptr in handlers

    if (!pb_get_encoded_size(&actualSize, command_Response_fields, &message)) {
        return tl::make_unexpected(CboxError::NETWORK_ENCODING_ERROR);
    }

    auto protoBytes = std::vector<uint8_t>(actualSize);
    auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());

    if (!pb_encode(&stream, command_Response_fields, &message)) {
        return tl::make_unexpected(CboxError::NETWORK_ENCODING_ERROR);
    }

    return b64_encode(protoBytes);
}

CboxExpected<std::string> encodeResponse(uint32_t msgId, CboxError status)
{
    command_Response message = command_Response_init_zero;
    message.msgId = msgId;
    message.error = command_ErrorCode(status);

    size_t actualSize;
    pb_get_encoded_size(&actualSize, command_Response_fields, &message);

    auto protoBytes = std::vector<uint8_t>(actualSize);
    auto stream = pb_ostream_from_buffer(protoBytes.data(), protoBytes.size());

    if (!pb_encode(&stream, command_Response_fields, &message)) {
        return tl::make_unexpected(CboxError::NETWORK_ENCODING_ERROR);
    }

    return b64_encode(protoBytes);
}

} // end namespace cbox
