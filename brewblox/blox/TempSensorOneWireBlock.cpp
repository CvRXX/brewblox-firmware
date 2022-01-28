#include "TempSensorOneWireBlock.h"
#include "blox/FieldTags.h"
#include "compiled_proto/src/TempSensorOneWire.pb.h"

TempSensorOneWireBlock::TempSensorOneWireBlock(cbox::ObjectContainer& objects)
    : OneWireDeviceBlock(objects)
    , sensor(owBus.lockFunctor())
{
}

TempSensorOneWireBlock::TempSensorOneWireBlock(cbox::ObjectContainer& objects, cbox::obj_id_t busId)
    : OneWireDeviceBlock(objects, busId)
    , sensor(owBus.lockFunctor())
{
}

TempSensorOneWireBlock::TempSensorOneWireBlock(cbox::ObjectContainer& objects, cbox::obj_id_t busId, const OneWireAddress& addr)
    : OneWireDeviceBlock(objects, busId)
    , sensor(owBus.lockFunctor(), addr)
{
}

cbox::CboxError TempSensorOneWireBlock::streamFrom(cbox::DataIn& in)
{
    blox_TempSensorOneWire_Block newData = blox_TempSensorOneWire_Block_init_zero;
    cbox::CboxError res = streamProtoFrom(in, &newData, blox_TempSensorOneWire_Block_fields, blox_TempSensorOneWire_Block_size);
    /* if no errors occur, write new settings to wrapped object */
    if (res == cbox::CboxError::OK) {
        if (newData.oneWireBusId) {
            owBus.setId(newData.oneWireBusId);
        }
        sensor.address(OneWireAddress(newData.address));
        sensor.setCalibration(cnl::wrap<temp_t>(newData.offset));
    }
    return res;
}

cbox::CboxError TempSensorOneWireBlock::streamTo(cbox::DataOut& out) const
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;
    FieldTags stripped;

    if (sensor.valid()) {
        message.value = cnl::unwrap((sensor.value()));
    } else {
        stripped.add(blox_TempSensorOneWire_Block_value_tag);
    }

    message.oneWireBusId = owBus.getId();
    message.address = sensor.address();
    message.offset = cnl::unwrap(sensor.getCalibration());

    stripped.copyToMessage(message.strippedFields, message.strippedFields_count, 1);
    return streamProtoTo(out, &message, blox_TempSensorOneWire_Block_fields, blox_TempSensorOneWire_Block_size);
}

cbox::CboxError TempSensorOneWireBlock::streamPersistedTo(cbox::DataOut& out) const
{
    blox_TempSensorOneWire_Block message = blox_TempSensorOneWire_Block_init_zero;
    message.oneWireBusId = owBus.getId();
    message.address = sensor.address();
    message.offset = cnl::unwrap(sensor.getCalibration());
    return streamProtoTo(out, &message, blox_TempSensorOneWire_Block_fields, blox_TempSensorOneWire_Block_size);
}

cbox::update_t TempSensorOneWireBlock::update(const cbox::update_t& now)
{
    sensor.update();
    return update_1s(now);
}

void* TempSensorOneWireBlock::implements(const cbox::obj_type_t& iface)
{
    if (iface == brewblox_BlockType_TempSensorOneWire) {
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
