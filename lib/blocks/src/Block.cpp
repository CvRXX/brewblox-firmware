/*
 * Block.cpp TODO
 *
 *  Created on: Jul 23, 2018
 *      Author: elco
 */

#include "blocks/Block.h"
#include "cbox/DataStream.h"
#include "nanopb_callbacks.h"

cbox::CboxError
readProtoFromVector(std::vector<uint8_t>& in, void* destStruct, const pb_field_t fields[])
{
    pb_istream_t stream = {dataInStreamCallback, in.data(), in.size()};
    bool success = pb_decode(&stream, fields, destStruct);

    return (success) ? cbox::CboxError::OK : cbox::CboxError::INPUT_STREAM_DECODING_ERROR;
}

cbox::CboxError
readProtoFromCommand(cbox::Command& cmd, void* destStruct, const pb_field_t fields[])
{
    if (!cmd.requestPayload.has_value()) {
        return cbox::CboxError::OBJECT_DATA_NOT_ACCEPTED;
    }

    auto payload = cmd.requestPayload.value();
    return readProtoFromVector(payload.content, destStruct, fields);
}

cbox::CboxError
writeProtoToVector(std::vector<uint8_t>& out, const void* srcStruct, const pb_field_t fields[])
{
    pb_ostream_t stream = {dataOutStreamCallback, out.data(), out.size(), 0};
    bool success = pb_encode(&stream, fields, srcStruct);
    out.resize(stream.bytes_written);

    return (success) ? cbox::CboxError::OK : cbox::CboxError::OUTPUT_STREAM_ENCODING_ERROR;
}

cbox::CboxError
writeProtoToCommand(cbox::Command& cmd,
                    const void* srcStruct,
                    const pb_field_t fields[],
                    size_t maxSize,
                    cbox::obj_id_t objId,
                    cbox::obj_type_t typeId,
                    uint16_t subtype)
{
    cbox::CboxError res = cbox::CboxError::OK;
    std::vector<uint8_t> outContent(maxSize);
    res = writeProtoToVector(outContent, srcStruct, fields);

    if (res != cbox::CboxError::OK) {
        return res;
    }

    cbox::Payload outPayload(objId, typeId, subtype, std::move(outContent));
    res = cmd.respond(outPayload);

    return res;
}

cbox::CboxError
writeEmptyToCommand(cbox::Command& cmd,
                    cbox::obj_id_t objId,
                    cbox::obj_type_t typeId,
                    uint16_t subtype)
{
    cbox::Payload outPayload(objId, typeId, subtype);
    return cmd.respond(outPayload);
}
