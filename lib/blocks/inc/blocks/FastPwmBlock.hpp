#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
#include "control/ActuatorAnalogConstrained.hpp"
#include "control/FastPwm.hpp"
#include "proto/FastPwm.pb.h"

class FastPwmBlock final : public Block<brewblox_BlockType_FastPwm> {
private:
    cbox::CboxPtr<IoArray> io;
    FastPwm pwm;
    ActuatorAnalogConstrained constrained;
    blox_IoArray_TransitionDurationPreset transitionDurationPreset = blox_IoArray_TransitionDurationPreset_ST_OFF;
    duration_millis_t transitionDurationSetting = 0;

public:
    FastPwmBlock()
        : pwm(io, 0)
        , constrained(pwm)
    {
    }
    ~FastPwmBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(cbox::update_t now) override;
    void* implements(cbox::obj_type_t iface) override;

private:
    void addPersistedStateToMessage(blox_FastPwm_Block& message) const;
};
