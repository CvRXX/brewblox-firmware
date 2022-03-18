#pragma once

#include "cbox/ObjectBase.hpp"
#include "cbox/Payload.hpp"
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
payloadToMessage(const cbox::Payload& payload,
                 void* destStruct,
                 const pb_field_t fields[]);

/**
 * Calls cmd.respond() with a payload where object ids are set,
 * but content is empty.
 */
cbox::CboxError
callWithMessage(const cbox::PayloadCallback& callback,
                cbox::obj_id_t objId,
                cbox::obj_type_t typeId,
                cbox::obj_subtype_t subtype);

/**
 * Calls cmd.respond() with a payload serialized
 * from given nanopb struct and fields.
 */
cbox::CboxError
callWithMessage(const cbox::PayloadCallback& callback,
                cbox::obj_id_t objId,
                cbox::obj_type_t typeId,
                cbox::obj_subtype_t subtype,
                const void* srcStruct,
                const pb_field_t fields[],
                size_t maxSize);
