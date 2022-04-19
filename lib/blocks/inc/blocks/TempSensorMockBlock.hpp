#pragma once

#include "blocks/Block.hpp"
#include "blocks/FieldTags.hpp"
#include "control/TempSensorMock.hpp"
#include "proto/TempSensorMock.pb.h"

class TempSensorMockBlock final : public Block<brewblox_BlockType_TempSensorMock> {
private:
    TempSensorMock sensor;

    using Fluctuation = TempSensorMock::Fluctuation;

protected:
    static bool streamFluctuationsOut(pb_ostream_t* stream, const pb_field_t* field, void* const* arg);
    static bool streamFluctuationsIn(pb_istream_t* stream, const pb_field_t*, void** arg);
    void writeMessage(blox_TempSensorMock_Block& message) const;
    size_t protoSize() const;

public:
    TempSensorMockBlock() = default;
    ~TempSensorMockBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    TempSensorMock& get()
    {
        return sensor;
    }
};
