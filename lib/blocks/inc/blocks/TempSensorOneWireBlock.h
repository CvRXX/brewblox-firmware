#pragma once

#include "blocks/Block.h"
#include "blocks/OneWireDeviceBlock.h"
#include "control/DS18B20.h"

class TempSensorOneWireBlock : public Block<brewblox_BlockType_TempSensorOneWire>, public OneWireDeviceBlock {

private:
    DS18B20 sensor;

public:
    TempSensorOneWireBlock();
    TempSensorOneWireBlock(cbox::obj_id_t busId);
    TempSensorOneWireBlock(cbox::obj_id_t busId, const OneWireAddress& addr);

    virtual cbox::CboxError streamFrom(cbox::DataIn& in) override final;
    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final;
    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final;
    virtual cbox::update_t update(const cbox::update_t& now) override final;

    virtual void* implements(const cbox::obj_type_t& iface) override final;

    DS18B20& get()
    {
        return sensor;
    }
};
