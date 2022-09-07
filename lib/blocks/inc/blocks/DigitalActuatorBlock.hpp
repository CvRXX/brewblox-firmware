#pragma once

#include "blocks/Block.hpp"
#include "blocks/IoChannelPtr.hpp"
#include "control/ActuatorDigital.hpp"
#include "control/ActuatorDigitalConstrained.hpp"
#include "control/ActuatorDigitalSoft.hpp"
#include "proto/DigitalActuator.pb.h"
#include <optional>
#include <variant>

class ActuatorDigitalProxy : public ActuatorDigitalBase {
public:
    ActuatorDigitalProxy()
        : hwDevice{}
    {
    }

    [[nodiscard]] State state() const final
    {
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            return pAct->state();
        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            return pAct->state();
        }
        return State::Unknown;
    }

    void state(State v) final
    {
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            pAct->state(v);
        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            pAct->state(v);
        }
    }

    [[nodiscard]] bool invert() const
    {
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            return pAct->invert();
        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            return pAct->invert();
        }
        return false;
    }

    void invert(bool v)
    {
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            pAct->invert(v);
        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            pAct->invert(v);
        }
    }

    [[nodiscard]] uint8_t channel() const
    {
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            return pAct->channel();
        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            return pAct->channel();
        }
        return false;
    }

    void channel(uint8_t v)
    {
        hwDevice.setChannel(v);
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            pAct->channel(v);
        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            pAct->channel(v);
        }
    }

    void swapImplementation();

    bool softStartSupported(uint8_t channel) const
    {
        if (auto dev = hwDevice.lock()) {
            IoArray::ChannelCapabilities requested{.all = 0};
            requested.flags.pwm100Hz = 1;
            return dev->channelSupports(channel, requested);
        }
        return false;
    }

    // returns a time if supported by the hwDevice and channel
    std::optional<duration_millis_t> transitionDuration() const
    {
        if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            return pAct->getTransitionTime();
        }
        return std::nullopt;
    }

    IoChannelPtr hwDevice;

    std::variant<ActuatorDigital, ActuatorDigitalSoft> act = ActuatorDigital(hwDevice, 0);
};

class DigitalActuatorBlock final : public Block<brewblox_BlockType_DigitalActuator> {
private:
    cbox::Claimable claim;
    ActuatorDigitalProxy actuator;
    ActuatorDigitalConstrained constrained;
    blox_IoArray_TransitionDurationPreset transitionDurationPreset = blox_IoArray_TransitionDurationPreset_ST_OFF;
    duration_millis_t transitionDurationSetting = 0;
    duration_millis_t transitionDurationDesired = 0;

public:
    DigitalActuatorBlock()
        : actuator{}
        , constrained{actuator}
    {
    }
    ~DigitalActuatorBlock() = default;

    cbox::CboxError read(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError readStored(const cbox::PayloadCallback& callback) const override;
    cbox::CboxError write(const cbox::Payload& payload) override;
    cbox::update_t updateHandler(cbox::update_t now) override;
    void* implements(cbox::obj_type_t iface) override;

    ActuatorDigitalConstrained& getConstrained()
    {
        return constrained;
    }

private:
    void addPersistedStateToMessage(blox_DigitalActuator_Block& message) const;
};
