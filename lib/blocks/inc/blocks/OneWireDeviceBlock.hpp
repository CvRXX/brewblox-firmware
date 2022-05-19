#pragma once
#include "cbox/CboxPtr.hpp"
#include "cbox/ObjectContainer.hpp"
#include "control/OneWireAddress.hpp"

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

    cbox::obj_id_t getBusId() const
    {
        return owBus.getId();
    }

    void setBusId(cbox::obj_id_t id)
    {
        owBus.setId(id);
    }
};
