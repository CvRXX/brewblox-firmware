#pragma once
#include "cbox/CboxPtr.h"
#include "cbox/ObjectContainer.h"
#include "control/OneWireAddress.h"

class OneWire;

class OneWireDeviceBlock {
protected:
    cbox::CboxPtr<OneWire> owBus;

public:
    OneWireDeviceBlock()
    {
    }

    OneWireDeviceBlock(cbox::obj_id_t busId)
        : owBus(busId)
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
