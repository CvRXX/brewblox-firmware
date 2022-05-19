#pragma once

#include "blocks/Block.hpp"
#include "blocks/OneWireDeviceBlock.hpp"
#include "control/DS18B20.hpp"

class TempSensorOneWireBlock final : public Block<brewblox_BlockType_TempSensorOneWire>, public OneWireDeviceBlock {

private:
    DS18B20 sensor;

public:
    TempSensorOneWireBlock();
    TempSensorOneWireBlock(cbox::obj_id_t busId);
    TempSensorOneWireBlock(cbox::obj_id_t busId, OneWireAddress addr);
    ~TempSensorOneWireBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    DS18B20& get()
    {
        return sensor;
    }
};
