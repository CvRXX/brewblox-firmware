#pragma once

#include "cbox/Command.h"
#include "cbox/ObjectBase.h"
#include "pb.h"
#include "proto/brewblox.pb.h"
#include <type_traits>

template <uint16_t id>
using Block = cbox::ObjectBase<id>;

cbox::CboxError
readProtoFromVector(std::vector<uint8_t>& in, void* destStruct, const pb_field_t fields[]);

cbox::CboxError
readProtoFromCommand(cbox::Command& cmd, void* destStruct, const pb_field_t fields[]);

cbox::CboxError
writeProtoToVector(std::vector<uint8_t>& out, const void* srcStruct, const pb_field_t fields[]);

cbox::CboxError
writeProtoToCommand(cbox::Command& cmd,
                    const void* srcStruct,
                    const pb_field_t fields[],
                    size_t maxSize,
                    cbox::obj_id_t objId,
                    cbox::obj_type_t typeId,
                    uint32_t subtype = 0);

cbox::CboxError
writeEmptyToCommand(cbox::Command& cmd,
                    cbox::obj_id_t objId,
                    cbox::obj_type_t typeId,
                    uint32_t subtype = 0);
