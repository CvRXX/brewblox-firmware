#include "blocks/StepperBlock.hpp"
#include "cbox/Application.hpp"
#include "control/Stepper.hpp"
#include "pb_decode.h"
#include "pb_encode.h"
#include "proto/Stepper.pb.h"

constexpr size_t getTargetTag(const blox_Stepper_Instruction instruction)
{
    switch (instruction) {
    case blox_Stepper_Instruction_PROFILE_ENABLE:
    case blox_Stepper_Instruction_PROFILE_RESET:
    case blox_Stepper_Instruction_PROFILE_WAIT:
        return blox_Stepper_Step_profileId_tag;
    case blox_Stepper_Instruction_SETPOINT_ENABLE:
    case blox_Stepper_Instruction_SETPOINT_SETTING:
    case blox_Stepper_Instruction_SETPOINT_WAIT:
        return blox_Stepper_Step_setpointId_tag;
    case blox_Stepper_Instruction_DIGITAL_ENABLE:
    case blox_Stepper_Instruction_DIGITAL_SETTING:
    case blox_Stepper_Instruction_DIGITAL_WAIT:
        return blox_Stepper_Step_digitalId_tag;
    case blox_Stepper_Instruction_ANALOG_ENABLE:
    case blox_Stepper_Instruction_ANALOG_SETTING:
    case blox_Stepper_Instruction_ANALOG_WAIT:
        return blox_Stepper_Step_analogId_tag;
    default:
        return 0;
    }
}

constexpr size_t getValueTag(const blox_Stepper_Instruction instruction)
{
    switch (instruction) {
    case blox_Stepper_Instruction_TIME_WAIT_DURATION:
    case blox_Stepper_Instruction_TIME_WAIT_ABSOLUTE:
        return blox_Stepper_Step_timeValue_tag;
    case blox_Stepper_Instruction_PROFILE_ENABLE:
    case blox_Stepper_Instruction_SETPOINT_ENABLE:
    case blox_Stepper_Instruction_DIGITAL_ENABLE:
    case blox_Stepper_Instruction_ANALOG_ENABLE:
        return blox_Stepper_Step_booleanValue_tag;
    case blox_Stepper_Instruction_SETPOINT_SETTING:
        return blox_Stepper_Step_setpointValue_tag;
    case blox_Stepper_Instruction_SETPOINT_WAIT:
        return blox_Stepper_Step_setpointOffsetValue_tag;
    case blox_Stepper_Instruction_DIGITAL_SETTING:
        return blox_Stepper_Step_digitalValue_tag;
    case blox_Stepper_Instruction_ANALOG_SETTING:
    case blox_Stepper_Instruction_ANALOG_WAIT:
        return blox_Stepper_Step_analogValue_tag;
    default:
        return 0;
    }
}

bool encodeSteps(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    auto* steps = reinterpret_cast<std::vector<Step>*>(*arg);
    for (const auto& step : *steps) {
        auto submsg = blox_Stepper_Step();
        auto instruction = blox_Stepper_Instruction(step.instruction);
        submsg.instruction = instruction;

        // All targets are uint16
        // It doesn't matter which union value we set,
        // as long as which_target_oneof is correct
        submsg.which_target_oneof = getTargetTag(instruction);
        submsg.target_oneof.analogId = step.targetId;

        // We need to convert or unwrap value variants
        submsg.which_value_oneof = getValueTag(instruction);

        switch (submsg.which_value_oneof) {
        case blox_Stepper_Step_booleanValue_tag:
            submsg.value_oneof.booleanValue = std::get<step_value_idx_bool>(step.value);
            break;
        case blox_Stepper_Step_timeValue_tag:
            submsg.value_oneof.timeValue = std::get<step_value_idx_time>(step.value);
            break;
        case blox_Stepper_Step_setpointValue_tag:
            submsg.value_oneof.setpointValue = cnl::unwrap(std::get<step_value_idx_temp>(step.value));
            break;
        case blox_Stepper_Step_setpointOffsetValue_tag:
            submsg.value_oneof.setpointOffsetValue = cnl::unwrap(std::get<step_value_idx_temp>(step.value));
            break;
        case blox_Stepper_Step_digitalValue_tag:
            submsg.value_oneof.digitalValue = blox_IoArray_DigitalState(std::get<step_value_idx_digital>(step.value));
            break;
        case blox_Stepper_Step_analogValue_tag:
            submsg.value_oneof.analogValue = cnl::unwrap(std::get<step_value_idx_analog>(step.value));
            break;
        default:
            break;
        }

        if (!pb_encode_tag_for_field(stream, field)) {
            return false;
        }
        if (!pb_encode_submessage(stream, blox_Stepper_Step_fields, &submsg)) {
            return false;
        }
    }
    return true;
}

bool decodeSteps(pb_istream_t* stream, const pb_field_t*, void** arg)
{
    if (!stream->bytes_left) {
        return true;
    }

    auto* steps = reinterpret_cast<std::vector<Step>*>(*arg);

    auto submsg = blox_Stepper_Step();
    if (!pb_decode(stream, blox_Stepper_Step_fields, &submsg)) {
        return false;
    }

    size_t targetTag = getTargetTag(submsg.instruction);
    size_t valueTag = getValueTag(submsg.instruction);

    if ((targetTag && submsg.which_target_oneof != targetTag)
        || (valueTag && submsg.which_value_oneof != valueTag)) {
        return false;
    }

    step_value_t value;

    switch (valueTag) {
    case blox_Stepper_Step_booleanValue_tag:
        value.emplace<step_value_idx_bool>(submsg.value_oneof.booleanValue);
        break;
    case blox_Stepper_Step_timeValue_tag:
        value.emplace<step_value_idx_time>(submsg.value_oneof.timeValue);
        break;
    case blox_Stepper_Step_setpointValue_tag:
        value.emplace<step_value_idx_temp>(
            cnl::wrap<temp_t>(submsg.value_oneof.setpointValue));
        break;
    case blox_Stepper_Step_setpointOffsetValue_tag:
        value.emplace<step_value_idx_temp>(
            submsg.value_oneof.setpointOffsetValue);
        break;
    case blox_Stepper_Step_digitalValue_tag:
        value.emplace<step_value_idx_digital>(
            ActuatorDigitalBase::State(submsg.value_oneof.digitalValue));
        break;
    case blox_Stepper_Step_analogValue_tag:
        value.emplace<step_value_idx_analog>(
            cnl::wrap<ActuatorAnalog::value_t>(submsg.value_oneof.analogValue));
        break;
    }

    steps->push_back({
        .instruction = Instruction(submsg.instruction),
        // Target is always uint16, so it doesn't matter which union field we use
        .targetId = submsg.target_oneof.analogId,
        .value = std::move(value),
    });

    return true;
}

cbox::CboxError
StepperBlock::read(const cbox::PayloadCallback& callback) const
{
    auto message = blox_Stepper_Block();
    message.enabled = stepper.enabled();
    message.activeStep = stepper.activeStep();
    message.activeStepStartedAt = stepper.activeStepStartedAt();
    message.steps.funcs.encode = &encodeSteps;
    message.steps.arg = const_cast<std::vector<Step>*>(&stepper.steps());

    size_t blockSize = (blox_Stepper_Step_size + 1) * stepper.steps().size()
                       + 3 // enabled
                       + 4 // activeStep
                       + 6 // activeStepStartedAt
        ;

    return callWithMessage(callback,
                           objectId(),
                           staticTypeId(),
                           0,
                           &message,
                           blox_Stepper_Block_fields,
                           blockSize);
}

cbox::CboxError
StepperBlock::readStored(const cbox::PayloadCallback& callback) const
{
    return read(callback);
}

cbox::CboxError
StepperBlock::write(const cbox::Payload& payload)
{
    auto message = blox_Stepper_Block();
    std::vector<Step> newSteps;
    message.steps.funcs.decode = &decodeSteps;
    message.steps.arg = &newSteps;

    auto res = payloadToMessage(payload, &message, blox_Stepper_Block_fields);

    if (res == cbox::CboxError::OK) {
        stepper.setEnabled(message.enabled);
        stepper.setSteps(std::move(newSteps));
    }

    return res;
}

cbox::update_t
StepperBlock::updateHandler(const cbox::update_t& now)
{
    if (stepper.update(now)) {
        readStored(cbox::getStorage().saveObjectCallback);
    }
    return next_update_1s(now);
}
