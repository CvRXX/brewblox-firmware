#pragma once

#include "blocks/Block.hpp"
#include "control/Enabler.hpp"
#include "control/TempSensor.hpp"
#include "control/TicksTypes.hpp"
#include "proto/TempSensorExternal.pb.h"

class TempSensorExternalBlock final : public Block<brewblox_BlockType_TempSensorExternal>, public TempSensor {
private:
    Enabler _enabler;
    temp_t _setting = 0;
    duration_seconds_t _timeout = 0;
    utc_seconds_t _lastUpdated = 0;
    bool _settingValid = false;

    blox_TempSensorExternal_Block baseMessage() const;

public:
    TempSensorExternalBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(const cbox::update_t& now) override;
    void* implements(cbox::obj_type_t iface) override;

    [[nodiscard]] bool valid() const override
    {
        return _settingValid && _enabler.get();
    }

    [[nodiscard]] temp_t value() const override
    {
        return _setting;
    }
};
