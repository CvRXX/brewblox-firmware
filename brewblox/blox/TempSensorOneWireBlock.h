#pragma once

#include "DS18B20.h"
#include "OneWireDeviceBlock.h"
#include "Temperature.h"
#include "blox/Block.h"
#include "blox/FieldTags.h"
#include "proto/cpp/TempSensorOneWire.pb.h"

class OneWire;

class TempSensorOneWireBlock : public Block<BrewBloxTypes_BlockType_TempSensorOneWire>, public OneWireDeviceBlock {

private:
    DS18B20 sensor;

public:
    TempSensorOneWireBlock(cbox::ObjectContainer& objects)
        : OneWireDeviceBlock(objects)
        , sensor(owBus.lockFunctor())
    {
    }

    TempSensorOneWireBlock(cbox::ObjectContainer& objects, cbox::obj_id_t busId)
        : OneWireDeviceBlock(objects, busId)
        , sensor(owBus.lockFunctor())
    {
    }

    virtual cbox::CboxError streamFrom(cbox::DataIn& in) override final
    {
        blox_TempSensorOneWire newData = blox_TempSensorOneWire_init_zero;
        cbox::CboxError res = streamProtoFrom(in, &newData, blox_TempSensorOneWire_fields, blox_TempSensorOneWire_size);
        /* if no errors occur, write new settings to wrapped object */
        if (res == cbox::CboxError::OK) {
            owBus.setId(newData.oneWireBusId);
            sensor.address(OneWireAddress(newData.address));
            sensor.setCalibration(cnl::wrap<temp_t>(newData.offset));
        }
        return res;
    }

    virtual cbox::CboxError streamTo(cbox::DataOut& out) const override final
    {
        blox_TempSensorOneWire message = blox_TempSensorOneWire_init_zero;
        FieldTags stripped;

        if (sensor.valid()) {
            message.value = cnl::unwrap((sensor.value()));
        } else {
            stripped.add(blox_TempSensorOneWire_value_tag);
        }

        message.oneWireBusId = owBus.getId();
        message.address = sensor.address();
        message.offset = cnl::unwrap(sensor.getCalibration());

        stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 1);
        return streamProtoTo(out, &message, blox_TempSensorOneWire_fields, blox_TempSensorOneWire_size);
    }

    virtual cbox::CboxError streamPersistedTo(cbox::DataOut& out) const override final
    {
        blox_TempSensorOneWire message = blox_TempSensorOneWire_init_zero;
        message.oneWireBusId = owBus.getId();
        message.address = sensor.address();
        message.offset = cnl::unwrap(sensor.getCalibration());
        return streamProtoTo(out, &message, blox_TempSensorOneWire_fields, blox_TempSensorOneWire_size);
    }

    virtual cbox::update_t update(const cbox::update_t& now) override final
    {
        sensor.update();
        return update_1s(now);
    }

    virtual void* implements(const cbox::obj_type_t& iface) override final
    {
        if (iface == BrewBloxTypes_BlockType_TempSensorOneWire) {
            return this; // me!
        }
        if (iface == cbox::interfaceId<TempSensor>()) {
            // return the member that implements the interface in this case
            DS18B20* dallasPtr = &sensor;
            TempSensor* sensorPtr = dallasPtr;
            return sensorPtr;
        }
        if (iface == cbox::interfaceId<OneWireDevice>()) {
            // return the member that implements the interface in this case
            DS18B20* dallasPtr = &sensor;
            OneWireDevice* devicePtr = dallasPtr;
            return devicePtr;
        }
        if (iface == cbox::interfaceId<OneWireDeviceBlock>()) {
            // return the base that implements the interface
            OneWireDeviceBlock* ptr = this;
            return ptr;
        }
        return nullptr;
    }

    DS18B20& get()
    {
        return sensor;
    }
};
