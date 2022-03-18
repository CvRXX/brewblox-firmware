#include "blocks/Block.hpp"
#include "cbox/DataStream.hpp"
#include <pb_decode.h>
#include <pb_encode.h>

cbox::CboxError
payloadToMessage(const cbox::Payload& payload,
                 void* destStruct,
                 const pb_field_t fields[])
{
    auto& protoBytes = payload.content;
    auto stream = pb_istream_from_buffer(protoBytes.data(), protoBytes.size());
    bool success = pb_decode(&stream, fields, destStruct);

    if (!success) {
        return cbox::CboxError::NETWORK_DECODING_ERROR;
    }

    return cbox::CboxError::OK;
}

cbox::CboxError
callWithMessage(const cbox::PayloadCallback& callback,
                cbox::obj_id_t objId,
                cbox::obj_type_t typeId,
                cbox::obj_subtype_t subtype)
{
    cbox::Payload payload(objId, typeId, subtype);
    return callback(payload);
}

cbox::CboxError
callWithMessage(const cbox::PayloadCallback& callback,
                cbox::obj_id_t objId,
                cbox::obj_type_t typeId,
                cbox::obj_subtype_t subtype,
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
    return callback(payload);
}
