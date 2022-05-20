#pragma once
#include "cbox/CboxPtr.hpp"
#include "cbox/ObjectContainer.hpp"
#include "control/OneWireAddress.hpp"

class OneWire;

class OneWireDeviceBlock {
private:
    cbox::CboxPtr<OneWire> owBus;

protected:
    [[nodiscard]] auto& busPtr()
    {
        return owBus;
    }

public:
    OneWireDeviceBlock(cbox::obj_id_t busId)
        : owBus(busId)
    {
    }

    [[nodiscard]] cbox::obj_id_t getBusId() const
    {
        return owBus.getId();
    }

    void setBusId(cbox::obj_id_t id)
    {
        owBus.setId(id);
    }
};
