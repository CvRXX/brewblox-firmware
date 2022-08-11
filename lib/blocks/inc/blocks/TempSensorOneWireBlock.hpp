#pragma once

#include "blocks/Block.hpp"
#include "blocks/OneWireDeviceBlock.hpp"
#include "control/DS18B20.hpp"

class TempSensorOneWireBlock final : public Block<brewblox_BlockType_TempSensorOneWire>, public OneWireDeviceBlock {

private:
    DS18B20 sensor;

public:
    TempSensorOneWireBlock();
    explicit TempSensorOneWireBlock(cbox::obj_id_t busId);
    TempSensorOneWireBlock(cbox::obj_id_t busId, OneWireAddress addr);
    ~TempSensorOneWireBlock() override = default;

    TempSensorOneWireBlock(const TempSensorOneWireBlock&) = delete;
    TempSensorOneWireBlock(TempSensorOneWireBlock&&) = delete;
    TempSensorOneWireBlock& operator=(const TempSensorOneWireBlock&) = delete;
    TempSensorOneWireBlock& operator=(TempSensorOneWireBlock&&) = delete;

    [[nodiscard]] cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    [[nodiscard]] cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    [[nodiscard]] cbox::CboxError write(const cbox::Payload& payload) override;
    [[nodiscard]] cbox::update_t updateHandler(cbox::update_t now) override;
    [[nodiscard]] void* implements(cbox::obj_type_t iface) override;

    [[nodiscard]] DS18B20& get()
    {
        return sensor;
    }
};
