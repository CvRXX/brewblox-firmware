#include "blocks/SequenceBlock.hpp"
#include "AppTicks.hpp"
#include "blocks/ActuatorPwmBlock.hpp"
#include "blocks/SetpointProfileBlock.hpp"
#include "cbox/Application.hpp"
#include "cbox/Cache.hpp"
#include "cbox/PayloadConversion.hpp"
#include "control/ActuatorDigitalBase.hpp"
#include "control/ActuatorDigitalConstrained.hpp"
#include "control/SetpointSensorPair.hpp"
#include "control/TempSensor.hpp"
#include "pb_decode.h"
#include "pb_encode.h"
#include "proto/Sequence.pb.h"

static constexpr utc_seconds_t MIN_VALID_SYSTIME = 1'000'000'000; // mid-2001
static constexpr utc_seconds_t STORAGE_DELAY = 60;
static constexpr temp_t MIN_TEMP = cnl::wrap<temp_t>(std::numeric_limits<int32_t>::min());
static constexpr temp_t MAX_TEMP = cnl::wrap<temp_t>(std::numeric_limits<int32_t>::max());

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
    blox_Sequence_Block message = blox_Sequence_Block_init_zero;
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

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Sequence_Block_fields,
                     blockSize)
        .respond(callback)
        .status();
}

cbox::CboxError
SequenceBlock::readStored(const cbox::PayloadCallback& callback) const
{
    blox_Sequence_Block message = blox_Sequence_Block_init_zero;
    message.enabled = enabler.get();
    message.overrideState = true;
    message.activeInstruction = _state.activeInstruction;
    message.activeInstructionStartedAt = _state.activeInstructionStartedAt;
    message.disabledAt = _state.disabledAt;
    message.disabledDuration = _state.disabledDuration;
    message.instructions.funcs.encode = &encodeInstructions;
    message.instructions.arg = const_cast<std::vector<blox_Sequence_Instruction>*>(&_instructions);

    size_t blockSize = (blox_Sequence_Instruction_size + 1) * _instructions.size()
                       + 3 // enabled
                       + 3 // overrideState
                       + 4 // activeInstruction
                       + 6 // activeInstructionStartedAt
                       + 6 // disabledAt
                       + 6 // disabledDuration
        ;

    return cbox::PayloadBuilder(*this)
        .withContent(&message,
                     blox_Sequence_Block_fields,
                     blockSize)
        .respond(callback)
        .status();
}

cbox::CboxError
SequenceBlock::write(const cbox::Payload& payload)
{
    blox_Sequence_Block message = blox_Sequence_Block_init_zero;
    std::vector<blox_Sequence_Instruction> newInstructions;
    message.instructions.funcs.decode = &decodeInstructions;
    message.instructions.arg = &newInstructions;

    auto parser = cbox::PayloadParser(payload);

    if (parser.fillMessage(&message, blox_Sequence_Block_fields)) {
        if (parser.hasField(blox_Sequence_Block_enabled_tag)) {
            enabler.set(message.enabled);
        }

        bool hasInstructions = parser.hasField(blox_Sequence_Block_instructions_tag);
        bool hasOverrideState = parser.hasField(blox_Sequence_Block_overrideState_tag);
        bool sameOpcodes = false;

        if (hasInstructions) {
            sameOpcodes = _instructions.size() > _state.activeInstruction
                          && std::equal(_instructions.begin(),
                                        _instructions.begin() + std::min(size_t(_state.activeInstruction), _instructions.size()), newInstructions.begin(),
                                        [](const blox_Sequence_Instruction& lhs, const blox_Sequence_Instruction& rhs) {
                                            return lhs.which_instruction_oneof == rhs.which_instruction_oneof;
                                        });
            _instructions.swap(newInstructions);
        }

        if (hasOverrideState && message.overrideState) {
            auto newState = SequenceState(_state);

            if (parser.hasField(blox_Sequence_Block_activeInstruction_tag)) {
                newState.activeInstruction = message.activeInstruction;
            }
            if (parser.hasField(blox_Sequence_Block_activeInstructionStartedAt_tag)) {
                newState.activeInstructionStartedAt = message.activeInstructionStartedAt;
            }
            if (parser.hasField(blox_Sequence_Block_disabledAt_tag)) {
                newState.disabledAt = message.disabledAt;
            }
            if (parser.hasField(blox_Sequence_Block_disabledDuration_tag)) {
                newState.disabledDuration = message.disabledDuration;
            }

            transition(std::move(newState));
        } else if (hasInstructions && sameOpcodes) {
            // Reload active state in case arguments changed
            transition(std::move(_state));
        } else if (hasInstructions) {
            reset();
        }

        // During external write calls the caller is responsible for persisting state to storage
        _state.stored = true;
    }

    return parser.status();
}

cbox::CboxError
SequenceBlock::loadFromCache()
{
    if (auto loaded = cbox::loadFromCache<SequenceState>(objectId(), staticTypeId())) {
        transition(std::move(*loaded));
    }
    return cbox::CboxError::OK;
}

InstructionResult errorFunc(SequenceBlock&)
{
    return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_ARGUMENT);
}

InstructionResult endFunc(SequenceBlock&)
{
    return blox_Sequence_SequenceStatus_END;
}

InstructionResult restartFunc(SequenceBlock&)
{
    return blox_Sequence_SequenceStatus_RESTART;
}

InstructionResult setEnablerFunc(SequenceBlock& sequence,
                                 cbox::CboxPtr<Enabler>& target,
                                 bool value)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->set(value);
    sequence.markTargetChanged(target.getId());
    return blox_Sequence_SequenceStatus_NEXT;
}

InstructionResult waitDurationFunc(SequenceBlock& sequence,
                                   utc_seconds_t duration)
{
    auto utc = ticks.utc();
    auto& state = sequence.state();

    if (utc - state.activeInstructionStartedAt >= duration + state.disabledDuration) {
        return blox_Sequence_SequenceStatus_NEXT;
    } else {
        return blox_Sequence_SequenceStatus_WAIT;
    }
}

InstructionResult waitUntilFunc(SequenceBlock&,
                                utc_seconds_t time)
{
    auto utc = ticks.utc();

    if (time <= utc) {
        return blox_Sequence_SequenceStatus_NEXT;
    } else {
        return blox_Sequence_SequenceStatus_WAIT;
    }
}

enum class WaitTempMode {
    BETWEEN,
    NOT_BETWEEN,
    UNEXPECTED,
};

InstructionResult waitTemperatureFunc(SequenceBlock&,
                                      cbox::CboxPtr<TempSensor>& target,
                                      temp_t lower,
                                      temp_t upper,
                                      WaitTempMode mode)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    bool within = false;

    if (!ptr->valid()) {
        if (mode != WaitTempMode::UNEXPECTED) {
            return tl::make_unexpected(blox_Sequence_SequenceError_INACTIVE_TARGET);
        }
    } else {
        auto value = ptr->value();
        within = value >= lower && value <= upper;
    }

    if (within == (mode == WaitTempMode::BETWEEN)) {
        return blox_Sequence_SequenceStatus_NEXT;
    } else {
        return blox_Sequence_SequenceStatus_WAIT;
    }
}

InstructionResult setSetpointFunc(SequenceBlock& sequence,
                                  cbox::CboxPtr<SetpointSensorPair>& target,
                                  temp_t setting)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->setting(setting);
    sequence.markTargetChanged(target.getId());
    return blox_Sequence_SequenceStatus_NEXT;
}

InstructionResult waitSetpointFunc(SequenceBlock&,
                                   cbox::CboxPtr<SetpointSensorPair>& target,
                                   temp_t precision)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    if (!ptr->settingValid()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_DISABLED_TARGET);
    }

    if (!ptr->sensorValid()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INACTIVE_TARGET);
    }

    auto setting = ptr->setting();
    auto value = ptr->value();
    if (value >= setting - precision && value <= setting + precision) {
        return blox_Sequence_SequenceStatus_NEXT;
    } else {
        return blox_Sequence_SequenceStatus_WAIT;
    }
}

InstructionResult setDigitalFunc(SequenceBlock& sequence,
                                 cbox::CboxPtr<ActuatorDigitalConstrained>& target,
                                 ActuatorDigitalBase::State state)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->desiredState(state);
    sequence.markTargetChanged(target.getId());
    return blox_Sequence_SequenceStatus_NEXT;
}

InstructionResult waitDigitalFunc(SequenceBlock&,
                                  cbox::CboxPtr<ActuatorDigitalConstrained>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    if (ptr->desiredState() == ptr->state()) {
        return blox_Sequence_SequenceStatus_NEXT;
    } else {
        return blox_Sequence_SequenceStatus_WAIT;
    }
}

InstructionResult setPwmFunc(SequenceBlock& sequence,
                             cbox::CboxPtr<ActuatorPwmBlock>& target,
                             ActuatorPwm::value_t setting)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->getConstrained().setting(setting);
    sequence.markTargetChanged(target.getId());
    return blox_Sequence_SequenceStatus_NEXT;
}

InstructionResult startProfileFunc(SequenceBlock& sequence,
                                   cbox::CboxPtr<SetpointProfileBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->get().startTime(ticks.utc());
    sequence.markTargetChanged(target.getId());
    return blox_Sequence_SequenceStatus_NEXT;
}

InstructionResult waitProfileFunc(SequenceBlock&,
                                  cbox::CboxPtr<SetpointProfileBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    auto& profile = ptr->get();

    if (!profile.enabler.get()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_DISABLED_TARGET);
    }

    auto& points = profile.points();

    if (!points.size() || ticks.utc() - points.back().time >= profile.startTime()) {
        return blox_Sequence_SequenceStatus_NEXT;
    } else {
        return blox_Sequence_SequenceStatus_WAIT;
    }
}

InstructionResult startSequenceFunc(SequenceBlock& sequence,
                                    cbox::CboxPtr<SequenceBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    ptr->reset();
    sequence.markTargetChanged(target.getId());
    return blox_Sequence_SequenceStatus_NEXT;
}

InstructionResult waitSequenceFunc(SequenceBlock&,
                                   cbox::CboxPtr<SequenceBlock>& target)
{
    auto ptr = target.lock();
    if (!ptr) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INVALID_TARGET);
    }

    if (!ptr->enabler.get()) {
        return tl::make_unexpected(blox_Sequence_SequenceError_DISABLED_TARGET);
    }

    auto& status = ptr->state().status;

    if (status == blox_Sequence_SequenceStatus_END) {
        return blox_Sequence_SequenceStatus_NEXT;
    } else if (status == blox_Sequence_SequenceStatus_ERROR) {
        return tl::make_unexpected(blox_Sequence_SequenceError_INACTIVE_TARGET);
    } else {
        return blox_Sequence_SequenceStatus_WAIT;
    }
}

InstructionFunctor SequenceBlock::makeRunner()
{
    if (_state.activeInstruction >= _instructions.size()) {
        return endFunc;
    }

    auto& ins = _instructions.at(_state.activeInstruction);

    switch (ins.which_instruction_oneof) {
    case blox_Sequence_Instruction_RESTART_tag:
        return restartFunc;
    case blox_Sequence_Instruction_DISABLE_tag:
        return [target = cbox::CboxPtr<Enabler>(ins.instruction_oneof.DISABLE.target)](SequenceBlock& sequence) mutable {
            return setEnablerFunc(sequence, target, false);
        };
    case blox_Sequence_Instruction_ENABLE_tag:
        return [target = cbox::CboxPtr<Enabler>(ins.instruction_oneof.ENABLE.target)](SequenceBlock& sequence) mutable {
            return setEnablerFunc(sequence, target, true);
        };
    case blox_Sequence_Instruction_WAIT_DURATION_tag:
        return [duration = ins.instruction_oneof.WAIT_DURATION.duration](SequenceBlock& sequence) mutable {
            return waitDurationFunc(sequence, duration);
        };
    case blox_Sequence_Instruction_WAIT_UNTIL_tag:
        return [time = ins.instruction_oneof.WAIT_UNTIL.time](SequenceBlock& sequence) mutable {
            return waitUntilFunc(sequence, time);
        };
    case blox_Sequence_Instruction_WAIT_TEMP_BETWEEN_tag:
        return [target = cbox::CboxPtr<TempSensor>(ins.instruction_oneof.WAIT_TEMP_BETWEEN.target),
                lower = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_BETWEEN.lower),
                upper = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_BETWEEN.upper)](SequenceBlock& sequence) mutable {
            return waitTemperatureFunc(sequence, target, lower, upper, WaitTempMode::BETWEEN);
        };
    case blox_Sequence_Instruction_WAIT_TEMP_NOT_BETWEEN_tag:
        return [target = cbox::CboxPtr<TempSensor>(ins.instruction_oneof.WAIT_TEMP_NOT_BETWEEN.target),
                lower = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_NOT_BETWEEN.lower),
                upper = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_NOT_BETWEEN.upper)](SequenceBlock& sequence) mutable {
            return waitTemperatureFunc(sequence, target, lower, upper, WaitTempMode::NOT_BETWEEN);
        };
    case blox_Sequence_Instruction_WAIT_TEMP_UNEXPECTED_tag:
        return [target = cbox::CboxPtr<TempSensor>(ins.instruction_oneof.WAIT_TEMP_UNEXPECTED.target),
                lower = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_UNEXPECTED.lower),
                upper = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_UNEXPECTED.upper)](SequenceBlock& sequence) mutable {
            return waitTemperatureFunc(sequence, target, lower, upper, WaitTempMode::UNEXPECTED);
        };
    case blox_Sequence_Instruction_WAIT_TEMP_ABOVE_tag:
        return [target = cbox::CboxPtr<TempSensor>(ins.instruction_oneof.WAIT_TEMP_ABOVE.target),
                value = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_ABOVE.value)](SequenceBlock& sequence) mutable {
            return waitTemperatureFunc(sequence, target, value, MAX_TEMP, WaitTempMode::BETWEEN);
        };
    case blox_Sequence_Instruction_WAIT_TEMP_BELOW_tag:
        return [target = cbox::CboxPtr<TempSensor>(ins.instruction_oneof.WAIT_TEMP_BELOW.target),
                value = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_TEMP_BELOW.value)](SequenceBlock& sequence) mutable {
            return waitTemperatureFunc(sequence, target, MIN_TEMP, value, WaitTempMode::BETWEEN);
        };
    case blox_Sequence_Instruction_SET_SETPOINT_tag:
        return [target = cbox::CboxPtr<SetpointSensorPair>(ins.instruction_oneof.SET_SETPOINT.target),
                setting = cnl::wrap<temp_t>(ins.instruction_oneof.SET_SETPOINT.setting)](SequenceBlock& sequence) mutable {
            return setSetpointFunc(sequence, target, setting);
        };
    case blox_Sequence_Instruction_WAIT_SETPOINT_tag:
        return [target = cbox::CboxPtr<SetpointSensorPair>(ins.instruction_oneof.WAIT_SETPOINT.target),
                precision = cnl::wrap<temp_t>(ins.instruction_oneof.WAIT_SETPOINT.precision)](SequenceBlock& sequence) mutable {
            return waitSetpointFunc(sequence, target, precision);
        };
    case blox_Sequence_Instruction_SET_DIGITAL_tag:
        return [target = cbox::CboxPtr<ActuatorDigitalConstrained>(ins.instruction_oneof.SET_DIGITAL.target),
                setting = ActuatorDigitalBase::State(ins.instruction_oneof.SET_DIGITAL.setting)](SequenceBlock& sequence) mutable {
            return setDigitalFunc(sequence, target, setting);
        };
    case blox_Sequence_Instruction_WAIT_DIGITAL_tag:
        return [target = cbox::CboxPtr<ActuatorDigitalConstrained>(ins.instruction_oneof.WAIT_DIGITAL.target)](SequenceBlock& sequence) mutable {
            return waitDigitalFunc(sequence, target);
        };
    case blox_Sequence_Instruction_SET_PWM_tag:
        return [target = cbox::CboxPtr<ActuatorPwmBlock>(ins.instruction_oneof.SET_PWM.target),
                setting = cnl::wrap<ActuatorPwm::value_t>(ins.instruction_oneof.SET_PWM.setting)](SequenceBlock& sequence) mutable {
            return setPwmFunc(sequence, target, setting);
        };
    case blox_Sequence_Instruction_START_PROFILE_tag:
        return [target = cbox::CboxPtr<SetpointProfileBlock>(ins.instruction_oneof.START_PROFILE.target)](SequenceBlock& sequence) mutable {
            return startProfileFunc(sequence, target);
        };
    case blox_Sequence_Instruction_WAIT_PROFILE_tag:
        return [target = cbox::CboxPtr<SetpointProfileBlock>(ins.instruction_oneof.WAIT_PROFILE.target)](SequenceBlock& sequence) mutable {
            return waitProfileFunc(sequence, target);
        };
    case blox_Sequence_Instruction_START_SEQUENCE_tag:
        return [target = cbox::CboxPtr<SequenceBlock>(ins.instruction_oneof.START_SEQUENCE.target)](SequenceBlock& sequence) mutable {
            return startSequenceFunc(sequence, target);
        };
    case blox_Sequence_Instruction_WAIT_SEQUENCE_tag:
        return [target = cbox::CboxPtr<SequenceBlock>(ins.instruction_oneof.WAIT_SEQUENCE.target)](SequenceBlock& sequence) mutable {
            return waitSequenceFunc(sequence, target);
        };
    default:
        return errorFunc;
    }
}

void SequenceBlock::transition(SequenceState&& state)
{
    _state = state;
    _runner = makeRunner();
}

void SequenceBlock::markTargetChanged(cbox::obj_id_t objId)
{
    if (std::find(_changedTargets.cbegin(), _changedTargets.cend(), objId) == _changedTargets.cend()) {
        _changedTargets.push_back(objId);
    }
}

void SequenceBlock::saveChanges(utc_seconds_t utc)
{
    if (_state.stored
        || utc == 0
        || _state.activeInstructionStartedAt == 0) {
        return;
    }

    // State can always be saved to cache
    cbox::saveToCache(objectId(), staticTypeId(), _state);

    // To reduce EEPROM write calls, state is only saved if
    // the current instruction takes a significant amount of time.
    // This avoids saving every single (idempotent) SET to EEPROM.
    if (utc - STORAGE_DELAY >= _state.activeInstructionStartedAt) {
        // Store targets
        for (auto objId : _changedTargets) {
            cbox::getObjects().store(objId);
        }
        _changedTargets.clear();

        // Store self
        readStored(cbox::getStorage().saveObjectCallback);
        _state.stored = true;
    }
}

cbox::update_t
SequenceBlock::updateHandler(const cbox::update_t& now)
{
    auto utc = ticks.utc();

    // We can't even track instruction start time without a valid system time value.
    if (utc < MIN_VALID_SYSTIME) {
        _state.status = blox_Sequence_SequenceStatus_ERROR;
        _state.error = blox_Sequence_SequenceError_SYSTEM_TIME_NOT_AVAILABLE;
        return next_update_1s(now);
    }

    if (_state.activeInstructionStartedAt == 0) {
        _state.activeInstructionStartedAt = utc;
    }

    if (!enabler.get()) {
        if (!_state.disabledAt) {
            _state.disabledAt = utc;
        }
        _state.status = _state.activeInstruction > 0
                                || _state.disabledAt > _state.activeInstructionStartedAt
                            ? blox_Sequence_SequenceStatus_PAUSED
                            : blox_Sequence_SequenceStatus_DISABLED;
        saveChanges(utc);
        return next_update_1s(now);
    } else if (_state.disabledAt) {
        // Used to be disabled.
        // Increment disabled duration to have a correct total value
        // if block is toggled multiple times during the same instruction.
        _state.disabledDuration += utc - _state.disabledAt;
        _state.disabledAt = 0;
    }

    auto result = _runner(*this);

    // Instruction encountered an error.
    // Many errors are resolved automatically (system time),
    // or by changes to other blocks (invalid / disabled target).
    // We'll need to keep retrying the instruction.
    if (!result) {
        _state.status = blox_Sequence_SequenceStatus_ERROR;
        _state.error = result.error();
        saveChanges(utc);
        return next_update_1s(now);
    }

    auto status = result.value();

    // Instruction completed normally.
    // The next instruction can start immediately.
    if (status == blox_Sequence_SequenceStatus_NEXT) {
        transition({
            .activeInstruction = uint16_t(_state.activeInstruction + 1),
            .status = status,
        });
        return now;
    }

    // Instruction restarted the entire sequence.
    // Go to the first instruction.
    // Enforce a 1s update pause to avoid overloading the controller
    // in a sequence that only consists of SET instructions.
    if (status == blox_Sequence_SequenceStatus_RESTART) {
        transition({
            .activeInstruction = 0,
            .status = status,
        });
        return next_update_1s(now);
    }

    // Instruction is not yet done.
    // Try again next time.
    _state.status = status;
    saveChanges(utc);
    return next_update_1s(now);
}

void* SequenceBlock::implements(cbox::obj_type_t iface)
{
    if (iface == staticTypeId()) {
        return this; // me!
    }
    if (iface == cbox::interfaceIdImpl<Enabler>()) {
        Enabler* ptr = &enabler;
        return ptr;
    }
    return nullptr;
}
