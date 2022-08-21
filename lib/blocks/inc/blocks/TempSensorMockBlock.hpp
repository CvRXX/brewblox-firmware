#pragma once

#include "blocks/Block.hpp"
#include "control/TempSensorMock.hpp"
#include "proto/TempSensorMock.pb.h"

class TempSensorMockBlock final : public Block<brewblox_BlockType_TempSensorMock> {
private:
    TempSensorMock sensor;

    using Fluctuation = TempSensorMock::Fluctuation;

protected:
    static bool encodeFluctuations(pb_ostream_t* stream, const pb_field_t* field, void* const* arg);
    static bool decodeFluctuations(pb_istream_t* stream, const pb_field_t*, void** arg);
    size_t protoSize() const;

public:
    TempSensorMockBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(cbox::update_t now) override;
    void* implements(cbox::obj_type_t iface) override;

    TempSensorMock& get()
    {
        return sensor;
    }
};
