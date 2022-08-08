#pragma once

#include "blocks/Block.hpp"
#include "cbox/CboxPtr.hpp"
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

    void state(State v) final
    {
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            pAct->state(v);
        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            pAct->state(v);
        }
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

    void swapImplementation()
    {
        if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            auto channel = pAct->channel();
            act.emplace<ActuatorDigitalSoft>(hwDevice, channel);

        } else if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            auto channel = pAct->channel();
            act.emplace<ActuatorDigital>(hwDevice, channel);
        }
    }

    // returns a time if supported by the hwDevice and channel
    std::optional<duration_millis_t> transitionDuration() const
    {
        if (auto pAct = std::get_if<ActuatorDigitalSoft>(&act)) {
            return pAct->getTransitionTime();
        } else if (auto pAct = std::get_if<ActuatorDigital>(&act)) {
            {
                if (auto dev = hwDevice.lock()) {
                    IoArray::ChannelCapabilities requested{.all = 0};
                    requested.flags.pwm100Hz = 1;
                    if (dev->channelSupports(pAct->channel(), requested)) {
                        return 0;
                    }
                }
            }
        }
        return std::nullopt;
    }

    cbox::CboxPtr<IoArray> hwDevice;

    std::variant<ActuatorDigital, ActuatorDigitalSoft> act = ActuatorDigital(hwDevice, 0);
};

class DigitalActuatorBlock final : public Block<brewblox_BlockType_DigitalActuator> {
private:
    ActuatorDigitalProxy actuator;
    ActuatorDigitalConstrained constrained;
    blox_IoArray_TransitionDurationPreset transitionDurationPreset = blox_IoArray_TransitionDurationPreset_ST_OFF;
    duration_millis_t transitionDurationSetting = 0;

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
