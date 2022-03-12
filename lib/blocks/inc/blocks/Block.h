#pragma once

#include "cbox/Command.h"
#include "cbox/ObjectBase.h"
#include "pb.h"
#include "proto/brewblox.pb.h"
#include <type_traits>

template <uint16_t id>
using Block = cbox::ObjectBase<id>;

/**
 * Parses the payload bytes from cmd.request()
 * into the given nanopb struct.
 *
 * Returns a cbox error if cmd.request() returns a nullptr.
 */
cbox::CboxError
parseRequestPayload(cbox::Command& cmd,
                    void* destStruct,
                    const pb_field_t fields[]);

/**
 * Calls cmd.respond() with a payload where object ids are set,
 * but content is empty.
 */
cbox::CboxError
serializeResponsePayload(cbox::Command& cmd,
                         cbox::obj_id_t objId,
                         cbox::obj_type_t typeId,
                         uint16_t subtype);

/**
 * Calls cmd.respond() with a payload serialized
 * from given nanopb struct and fields.
 */
cbox::CboxError
serializeResponsePayload(cbox::Command& cmd,
                         cbox::obj_id_t objId,
                         cbox::obj_type_t typeId,
                         uint16_t subtype,
                         const void* srcStruct,
                         const pb_field_t fields[],
                         size_t maxSize);
