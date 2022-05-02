#pragma once
#include "control/ActuatorAnalog.hpp"
#include "control/ActuatorDigital.hpp"
#include "control/SetpointProfile.hpp"
#include "control/SetpointSensorPair.hpp"
#include "control/TicksTypes.hpp"
#include <cstdint>
#include <functional>
#include <variant>

using step_value_t = std::variant<
    std::monostate,
    bool,
    utc_seconds_t,
    temp_t,
    ActuatorDigitalBase::State,
    ActuatorAnalog::value_t>;

constexpr size_t step_value_idx_bool = 1;
constexpr size_t step_value_idx_time = 2;
constexpr size_t step_value_idx_temp = 3;
constexpr size_t step_value_idx_digital = 4;
constexpr size_t step_value_idx_analog = 5;

enum class StepResult : uint8_t {
    OK = 0,
    WAITING = 1,
    INVALID_TARGET = 2,
    INVALID_ARGUMENT = 3,
    UTC_UNAVAILABLE = 4,
};

enum class Instruction : uint8_t {
    NOOP = 0,
    RESTART = 1,

    TIME_WAIT_DURATION = 2, // timeValue
    TIME_WAIT_ABSOLUTE = 3, // timeValue

    PROFILE_ENABLE = 10, // profileId, booleanValue
    PROFILE_RESET = 11,  // profileId
    PROFILE_WAIT = 12,   // profileId

    SETPOINT_ENABLE = 20,  // setpointId, booleanValue
    SETPOINT_SETTING = 21, // setpointId, setpointValue
    SETPOINT_WAIT = 22,    // setpointId, setpointOffsetValue

    DIGITAL_ENABLE = 30,  // digitalId, booleanValue
    DIGITAL_SETTING = 31, // digitalId, digitalValue
    DIGITAL_WAIT = 32,    // digitalId

    ANALOG_ENABLE = 40,  // analogId, booleanValue
    ANALOG_SETTING = 41, // analogId, analogValue
    ANALOG_WAIT = 42,    // analogId, analogValue
};

typedef struct Step {
    Instruction instruction;
    uint16_t targetId;
    step_value_t value;
} Step;

template <typename ValueIdx, typename ValueT>
Step makeStep(Instruction instruction, uint16_t targetId, ValueT value)
{
    return Step{
        .instruction = instruction,
        .targetId = targetId,
        .value = {std::in_place_index<ValueIdx>,
                  value}};
}

class Stepper final {
private:
    bool _enabled = true;
    uint16_t _activeStep = 0;
    utc_seconds_t _activeStepStartedAt = 0;
    std::vector<Step> _steps;

public:
    Stepper() = default;
    ~Stepper() = default;

    bool enabled() const
    {
        return _enabled;
    }

    uint16_t activeStep() const
    {
        return _activeStep;
    }

    utc_seconds_t activeStepStartedAt() const
    {
        return _activeStepStartedAt;
    }

    const std::vector<Step>& steps() const
    {
        return _steps;
    }

    void setEnabled(bool arg)
    {
        _enabled = arg;
    }

    void setSteps(std::vector<Step>&& arg)
    {
        _steps.swap(arg);
    }

    bool update(const utc_seconds_t now);
};
