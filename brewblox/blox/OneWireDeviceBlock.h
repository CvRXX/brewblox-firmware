#pragma once
#include "OneWireAddress.h"
#include "cbox/CboxPtr.h"
#include "cbox/ObjectContainer.h"

class OneWire;

class OneWireDeviceBlock {
protected:
    cbox::CboxPtr<OneWire> owBus;

public:
    OneWireDeviceBlock(cbox::ObjectContainer& objects)
        : owBus(objects)
    {
    }

    OneWireDeviceBlock(cbox::ObjectContainer& objects, cbox::obj_id_t busId)
        : owBus(objects, busId)
    {
    }

    cbox::obj_id_t getBusId()
    {
        return owBus.getId();
    }

    void setBusId(cbox::obj_id_t id)
    {
        owBus.setId(id);
    }
};
