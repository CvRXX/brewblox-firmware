#pragma once

#include "blocks/Block.h"
#include "blocks/FieldTags.h"
#include "control/TempSensorMock.h"
#include "proto/TempSensorMock.pb.h"

class TempSensorMockBlock : public Block<brewblox_BlockType_TempSensorMock> {
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
    virtual ~TempSensorMockBlock() = default;

    virtual cbox::CboxError read(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override final;
    virtual cbox::CboxError write(const cbox::Payload& payload) override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;
    virtual void* implements(cbox::obj_type_t iface) override final;

    TempSensorMock& get()
    {
        return sensor;
    }
};
