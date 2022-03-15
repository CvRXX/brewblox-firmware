#include "blocks/Block.h"
#include "cbox/DataStream.h"
#include <pb_decode.h>
#include <pb_encode.h>

cbox::CboxError
parseRequestPayload(cbox::Command& cmd,
                    void* destStruct,
                    const pb_field_t fields[])
{
    if (!cmd.request()) {
        return cbox::CboxError::INVALID_BLOCK;
    }

    auto& protoBytes = cmd.request()->content;
    auto stream = pb_istream_from_buffer(protoBytes.data(), protoBytes.size());
    bool success = pb_decode(&stream, fields, destStruct);

    if (!success) {
        return cbox::CboxError::NETWORK_DECODING_ERROR;
    }

    return cbox::CboxError::OK;
}

cbox::CboxError
serializeResponsePayload(cbox::Command& cmd,
                         cbox::obj_id_t objId,
                         cbox::obj_type_t typeId,
                         uint16_t subtype)
{
    cbox::Payload payload(objId, typeId, subtype);
    return cmd.respond(payload);
}

cbox::CboxError
serializeResponsePayload(cbox::Command& cmd,
                         cbox::obj_id_t objId,
                         cbox::obj_type_t typeId,
                         uint16_t subtype,
                         const void* srcStruct,
                         const pb_field_t fields[],
                         size_t maxSize)
{
    auto payload = cbox::Payload(objId, typeId, subtype);
    payload.content.resize(maxSize);
    auto stream = pb_ostream_from_buffer(payload.content.data(), payload.content.size());
    bool success = pb_encode(&stream, fields, srcStruct);

    if (!success) {
        return cbox::CboxError::NETWORK_ENCODING_ERROR;
    }

    payload.content.resize(stream.bytes_written);
    return cmd.respond(payload);
}
