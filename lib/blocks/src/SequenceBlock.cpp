#include "blocks/SequenceBlock.hpp"
#include "AppTicks.hpp"
#include "blocks/ActuatorPwmBlock.hpp"
#include "blocks/SetpointProfileBlock.hpp"
#include "cbox/Application.hpp"
#include "control/ActuatorDigitalBase.hpp"
#include "control/ActuatorDigitalConstrained.hpp"
#include "control/SetpointSensorPair.hpp"
#include "control/TempSensor.hpp"
#include "pb_decode.h"
#include "pb_encode.h"
#include "proto/Sequence.pb.h"

static constexpr utc_seconds_t MIN_VALID_SYSTIME = 1'000'000; // mid-2001

bool encodeInstructions(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto instructions = reinterpret_cast<std::vector<blox_Sequence_Instruction>*>(*arg);
    for (const auto& ins : *instructions) {
        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }
        if (!pb_encode_submessage(stream, blox_Sequence_Instruction_fields, &ins)) {
            return false;
        }
    }

    return true;
}

bool decodeInstructions(pb_istream_t* stream, const pb_field_t*, void** arg)
{
    auto instructions = reinterpret_cast<std::vector<blox_Sequence_Instruction>*>(*arg);

    if (stream->bytes_left) {
        auto submsg = blox_Sequence_Instruction();
        if (!pb_decode(stream, blox_Sequence_Instruction_fields, &submsg)) {
            return false;
        }
        instructions->push_back(std::move(submsg));
    }

    return true;
}

cbox::CboxError
SequenceBlock::read(const cbox::PayloadCallback& callback) const
{
    auto message = blox_Sequence_Block();
    message.enabled = enabler.get();
    message.activeInstruction = _state.activeInstruction;
    message.activeInstructionStartedAt = _state.activeInstructionStartedAt;
    message.disabledAt = _state.disabledAt;
    message.disabledDuration = _state.disabledDuration;
    message.status = _state.status;
    message.error = _state.error;
    message.instructions.funcs.encode = &encodeInstructions;
    message.instructions.arg = const_cast<std::vector<blox_Sequence_Instruction>*>(&_instructions);

    size_t blockSize = (blox_Sequence_Instruction_size + 1) * _instructions.size()
                       + 3 // enabled
                       + 4 // activeInstruction
                       + 6 // activeInstructionStartedAt
                       + 6 // disabledAt
                       + 6 // disabledDuration
                       + 3 // status
                       + 3 // error
        ;

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_Sequence_Block_fields,
                           blockSize);
}

cbox::CboxError
SequenceBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

void SequenceBlock::reset(const uint16_t activeInstruction, const uint32_t activeInstructionStartedAt)
{
    _state = {
        .activeInstruction = activeInstruction,
        .activeInstructionStartedAt = activeInstructionStartedAt,
    };
    _runner = makeRunner();
}

cbox::CboxError
SequenceBlock::write(const cbox::Payload& payload)
{
    auto message = blox_Sequence_Block();
    std::vector<blox_Sequence_Instruction> newInstructions;
    message.instructions.funcs.decode = &decodeInstructions;
    message.instructions.arg = &newInstructions;

    auto res = payloadToMessage(payload, &message, blox_Sequence_Block_fields);

    if (res == cbox::CboxError::OK) {
        enabler.set(message.enabled);
        _instructions.swap(newInstructions);

        if (message.which_reset_oneof == blox_Sequence_Block_reset_tag) {
            reset(message.reset_oneof.reset.activeInstruction,
                  message.reset_oneof.reset.activeInstructionStartedAt);
        }
    }

    return res;
}

InstructionResult errorFunc(const SequenceState&)
{
    return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_ARGUMENT);
}

InstructionResult doneFunc(const SequenceState&)
{
    return blox_Sequence_SequenceStatus_DONE;
}

InstructionResult restartFunc(const SequenceState&)
{
    return blox_Sequence_SequenceStatus_RESTART;
}

InstructionResult setEnablerFunc(const SequenceState&, cbox::CboxPtr<Enabler>& target, bool value)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->set(value);
    target.store();
    return blox_Sequence_SequenceStatus_ACTIVE;
}

InstructionResult waitDurationFunc(const SequenceState& state, const utc_seconds_t duration)
{
    auto utc = ticks.utc();

    if (utc < MIN_VALID_SYSTIME) {
        return tl::make_unexpected(blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE);
    }

    if (utc - state.activeInstructionStartedAt > duration) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

InstructionResult waitUntilFunc(const SequenceState&, const utc_seconds_t time)
{
    auto utc = ticks.utc();

    if (utc < MIN_VALID_SYSTIME) {
        return tl::make_unexpected(blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE);
    }

    if (time < utc) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

InstructionResult waitTemperatureFunc(const SequenceState&,
                                      const cbox::CboxPtr<TempSensor>& target,
                                      const temp_t lower,
                                      const temp_t upper)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    auto value = ptr->value();
    if (value >= lower && value <= upper) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

InstructionResult setSetpointFunc(const SequenceState&,
                                  cbox::CboxPtr<SetpointSensorPair>& target,
                                  const temp_t setting)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->setting(setting);
    target.store();
    return blox_Sequence_SequenceStatus_DONE;
}

InstructionResult waitSetpointFunc(const SequenceState&,
                                   const cbox::CboxPtr<SetpointSensorPair>& target,
                                   const temp_t precision)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    if (!ptr->settingValid()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_TARGET_DISABLED);
    }

    auto setting = ptr->setting();
    auto value = ptr->value();
    if (value > setting - precision && value < setting + precision) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

InstructionResult setDigitalFunc(const SequenceState&,
                                 cbox::CboxPtr<ActuatorDigitalConstrained>& target,
                                 ActuatorDigitalBase::State state)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->desiredState(state);
    target.store();
    return blox_Sequence_SequenceStatus_DONE;
}

InstructionResult waitDigitalFunc(const SequenceState&,
                                  const cbox::CboxPtr<ActuatorDigitalConstrained>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    if (ptr->desiredState() == ptr->state()) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

InstructionResult setPwmFunc(const SequenceState&,
                             cbox::CboxPtr<ActuatorPwmBlock>& target,
                             const ActuatorPwm::value_t setting)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->getPwm().setting(setting);
    target.store();
    return blox_Sequence_SequenceStatus_DONE;
}

InstructionResult waitPwmFunc(const SequenceState&,
                              const cbox::CboxPtr<ActuatorPwmBlock>& target,
                              const ActuatorPwm::value_t precision)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    auto& pwm = ptr->getPwm();

    if (!pwm.settingValid()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_TARGET_DISABLED);
    }

    auto setting = pwm.setting();
    auto value = pwm.value();
    if (value > setting - precision && value < setting + precision) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

InstructionResult startProfileFunc(const SequenceState&,
                                   cbox::CboxPtr<SetpointProfileBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->get().startTime(ticks.utc());
    target.store();
    return blox_Sequence_SequenceStatus_ACTIVE;
}

InstructionResult waitProfileFunc(const SequenceState& state,
                                  const cbox::CboxPtr<SetpointProfileBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    auto& profile = ptr->get();

    if (!profile.enabler.get()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_TARGET_DISABLED);
    }

    auto& points = profile.points();

    if ((!points.size()) || (ticks.utc() - points.back().time < profile.startTime())) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

InstructionResult startSequenceFunc(const SequenceState&,
                                    cbox::CboxPtr<SequenceBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->reset(0, 0);
    target.store();
    return blox_Sequence_SequenceStatus_ACTIVE;
}

InstructionResult waitSequenceFunc(const SequenceState&,
                                   const cbox::CboxPtr<SequenceBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    if (!ptr->enabler.get()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_TARGET_DISABLED);
    }

    if (ptr->done()) {
        return blox_Sequence_SequenceStatus_ACTIVE;
    } else {
        return blox_Sequence_SequenceStatus_WAITING;
    }
}

SequenceBlock::RunnerFunc
SequenceBlock::makeRunner()
{
    using namespace std::placeholders;

    if (_state.activeInstruction >= _instructions.size()) {
        return doneFunc;
    }

    auto& ins = _instructions.at(_state.activeInstruction);

    switch (ins.which_instruction_oneof) {
    case blox_Sequence_Instruction_restart_tag:
        return restartFunc;
    case blox_Sequence_Instruction_disable_tag:
        return std::bind(setEnablerFunc, _1,
                         cbox::CboxPtr<Enabler>(ins.instruction_oneof.disable.target),
                         false);
    case blox_Sequence_Instruction_enable_tag:
        return std::bind(setEnablerFunc, _1,
                         cbox::CboxPtr<Enabler>(ins.instruction_oneof.enable.target),
                         true);
    case blox_Sequence_Instruction_waitDuration_tag:
        return std::bind(waitDurationFunc, _1,
                         ins.instruction_oneof.waitDuration.duration);
    case blox_Sequence_Instruction_waitUntil_tag:
        return std::bind(waitUntilFunc, _1,
                         ins.instruction_oneof.waitUntil.time);
    case blox_Sequence_Instruction_waitTemperature_tag:
        return std::bind(waitTemperatureFunc, _1,
                         cbox::CboxPtr<TempSensor>(ins.instruction_oneof.waitTemperature.target),
                         cnl::wrap<temp_t>(ins.instruction_oneof.waitTemperature.lower),
                         cnl::wrap<temp_t>(ins.instruction_oneof.waitTemperature.upper));
    case blox_Sequence_Instruction_waitTemperatureAbove_tag:
        return std::bind(waitTemperatureFunc, _1,
                         cbox::CboxPtr<TempSensor>(ins.instruction_oneof.waitTemperatureAbove.target),
                         cnl::wrap<temp_t>(ins.instruction_oneof.waitTemperatureAbove.value),
                         cnl::wrap<temp_t>(std::numeric_limits<int32_t>::max()));
    case blox_Sequence_Instruction_waitTemperatureBelow_tag:
        return std::bind(waitTemperatureFunc, _1,
                         cbox::CboxPtr<TempSensor>(ins.instruction_oneof.waitTemperatureBelow.target),
                         cnl::wrap<temp_t>(std::numeric_limits<int32_t>::min()),
                         cnl::wrap<temp_t>(ins.instruction_oneof.waitTemperatureBelow.value));
    case blox_Sequence_Instruction_setSetpoint_tag:
        return std::bind(setSetpointFunc, _1,
                         cbox::CboxPtr<SetpointSensorPair>(ins.instruction_oneof.setSetpoint.target),
                         cnl::wrap<temp_t>(ins.instruction_oneof.setSetpoint.setting));
    case blox_Sequence_Instruction_waitSetpoint_tag:
        return std::bind(setSetpointFunc, _1,
                         cbox::CboxPtr<SetpointSensorPair>(ins.instruction_oneof.waitSetpoint.target),
                         cnl::wrap<temp_t>(ins.instruction_oneof.waitSetpoint.precision));
    case blox_Sequence_Instruction_setDigital_tag:
        return std::bind(setDigitalFunc, _1,
                         cbox::CboxPtr<ActuatorDigitalConstrained>(ins.instruction_oneof.setDigital.target),
                         ActuatorDigitalBase::State(ins.instruction_oneof.setDigital.setting));
    case blox_Sequence_Instruction_waitDigital_tag:
        return std::bind(waitDigitalFunc, _1,
                         cbox::CboxPtr<ActuatorDigitalConstrained>(ins.instruction_oneof.waitDigital.target));
    case blox_Sequence_Instruction_setPwm_tag:
        return std::bind(setPwmFunc, _1,
                         cbox::CboxPtr<ActuatorPwmBlock>(ins.instruction_oneof.setPwm.target),
                         cnl::wrap<ActuatorPwm::value_t>(ins.instruction_oneof.setPwm.setting));
    case blox_Sequence_Instruction_waitPwm_tag:
        return std::bind(waitPwmFunc, _1,
                         cbox::CboxPtr<ActuatorPwmBlock>(ins.instruction_oneof.waitPwm.target),
                         cnl::wrap<ActuatorPwm::value_t>(ins.instruction_oneof.waitPwm.precision));
    case blox_Sequence_Instruction_startProfile_tag:
        return std::bind(startProfileFunc, _1,
                         cbox::CboxPtr<SetpointProfileBlock>(ins.instruction_oneof.startProfile.target));
    case blox_Sequence_Instruction_waitProfile_tag:
        return std::bind(waitProfileFunc, _1,
                         cbox::CboxPtr<SetpointProfileBlock>(ins.instruction_oneof.waitProfile.target));
    case blox_Sequence_Instruction_startSequence_tag:
        return std::bind(startSequenceFunc, _1,
                         cbox::CboxPtr<SequenceBlock>(ins.instruction_oneof.startSequence.target));
    case blox_Sequence_Instruction_waitSequence_tag:
        return std::bind(waitSequenceFunc, _1,
                         cbox::CboxPtr<SequenceBlock>(ins.instruction_oneof.waitSequence.target));
    default:
        return errorFunc;
    }
}

cbox::update_t
SequenceBlock::updateHandler(const cbox::update_t& now)
{
    if (!enabler.get()) {
        _state.status = blox_Sequence_SequenceStatus_DISABLED;
        return next_update_never(now);
    }

    auto result = _runner(_state);

    if (!result) {
        _state.status = blox_Sequence_SequenceStatus_ERROR;
        _state.error = result.error();
        return next_update_1s(now);
    }

    auto status = result.value();
    if (status == blox_Sequence_SequenceStatus_ACTIVE) {
        _state = {
            .activeInstruction = uint16_t(_state.activeInstruction + 1),
            .activeInstructionStartedAt = ticks.utc(),
            .status = status,
        };
        _runner = makeRunner();
        return now;
    } else if (status == blox_Sequence_SequenceStatus_RESTART) {
        _state = {
            .activeInstruction = 0,
            .activeInstructionStartedAt = ticks.utc(),
        };
        _runner = makeRunner();
        return next_update_1s(now);
    } else {
        _state.status = status;
        return next_update_1s(now);
    }
}

void* SequenceBlock::implements(cbox::obj_type_t iface)
{
    if (iface == brewblox_BlockType_Sequence) {
        return this; // me!
    }
    if (iface == cbox::interfaceIdImpl<Enabler>()) {
        Enabler* ptr = &enabler;
        return ptr;
    }
    return nullptr;
}
