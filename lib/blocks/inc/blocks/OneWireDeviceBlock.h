#pragma once
#include "cbox/CboxPtr.h"
#include "cbox/ObjectContainer.h"
#include "control/OneWireAddress.h"

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
