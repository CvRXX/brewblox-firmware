#pragma once

#include "cbox/ObjectBase.hpp"
#include "cbox/Payload.hpp"
#include "pb.h"
#include "proto/brewblox.pb.h"
#include <type_traits>

template <uint16_t id>
using Block = cbox::ObjectBase<id>;

/**
 * Parses the payload bytes into the given nanopb struct.
 */
cbox::CboxError
payloadToMessage(const cbox::Payload& payload,
                 void* destStruct,
                 const pb_field_t fields[]);

/**
 * Call the response callback with a payload where metadata is set,
 * but content is empty.
 */
cbox::CboxError
callWithMessage(const cbox::PayloadCallback& callback,
                cbox::obj_id_t objId,
                cbox::obj_type_t typeId,
                cbox::obj_subtype_t subtype);

/**
 * Call the response callback with payload
 * serialized from given nanopb struct.
 */
cbox::CboxError
callWithMessage(const cbox::PayloadCallback& callback,
                cbox::obj_id_t objId,
                cbox::obj_type_t typeId,
                cbox::obj_subtype_t subtype,
                const void* srcStruct,
                const pb_field_t fields[],
                size_t maxSize);
