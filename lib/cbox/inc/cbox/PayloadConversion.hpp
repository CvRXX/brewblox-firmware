#pragma once
#include "cbox/Object.hpp"
#include "cbox/Payload.hpp"
#include "pb.h"

namespace cbox {

/*
 * Handles convenience functions for extracting Protobuf message data from a payload.
 */
class PayloadParser final {
private:
    CboxError _status = CboxError::OK;
    const cbox::Payload& _payload;

public:
    explicit PayloadParser(const cbox::Payload& payload_)
        : _payload(payload_)
    {
    }

    CboxError status() const
    {
        return _status;
    }

    bool fillMessage(void* destStruct,
                     const pb_field_t fields[]);

    bool hasField(cbox::obj_field_tag_t tag) const;
};

/**
 * Incrementally construct a payload,
 * and use it to respond to a callback.
 */
class PayloadBuilder final {
private:
    CboxError _status = CboxError::OK;
    Payload _payload;

public:
    explicit PayloadBuilder(const cbox::Object& obj,
                            cbox::obj_subtype_t subtype = 0)
        : _payload(obj.objectId(), obj.typeId(), subtype)
    {
    }

    PayloadBuilder(cbox::obj_id_t objId,
                   cbox::obj_type_t typeId,
                   cbox::obj_subtype_t subtype)
        : _payload(objId, typeId, subtype)
    {
    }

    CboxError status() const
    {
        return _status;
    }

    PayloadBuilder& withStatus(cbox::CboxError status);

    PayloadBuilder& withContent(const void* srcStruct,
                                const pb_field_t fields[],
                                size_t maxSize);

    PayloadBuilder& withMask(MaskMode mode,
                             std::vector<obj_field_tag_t>&& mask);

    PayloadBuilder& respond(const PayloadCallback& callback);
};

} // end namespace cbox
