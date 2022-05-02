#include "control/Stepper.hpp"

bool stepTimeWaitDuration(const Step& step, const utc_seconds_t now)
{
    return false;
}

bool stepTimeWaitAbsolute(const Step& step, const utc_seconds_t now)
{
    return false;
}

bool stepProfileEnable(const Step& step)
{
    return false;
}

bool stepProfileReset(const Step& step)
{
    return false;
}

bool stepProfileWait(const Step& step)
{
    return false;
}

bool stepSetpointEnable(const Step& step)
{
    return false;
}

bool stepSetpointSetting(const Step& step)
{
    return false;
}

bool stepSetpointWait(const Step& step)
{
    return false;
}

bool stepDigitalEnable(const Step& step)
{
    return false;
}

bool stepDigitalSetting(const Step& step)
{
    return false;
}

bool stepDigitalWait(const Step& step)
{
    return false;
}

bool stepAnalogEnable(const Step& step)
{
    return false;
}

bool stepAnalogSetting(const Step& step)
{
    return false;
}

bool stepAnalogWait(const Step& step)
{
    return false;
}

bool Stepper::update(const utc_seconds_t now)
{
    if (!_enabled || _activeStep >= _steps.size()) {
        return false;
    }

    auto& step = _steps.at(_activeStep);
    bool changed = false;

    switch (step.instruction) {
    case Instruction::NOOP:
        changed = true;
        break;
    case Instruction::RESTART:
        _activeStep = 0;
        _activeStepStartedAt = now;
        return true; // special case - changed, but don't increment activeStep
    case Instruction::TIME_WAIT_DURATION:
        changed = stepTimeWaitDuration(step, now);
        break;
    case Instruction::TIME_WAIT_ABSOLUTE:
        changed = stepTimeWaitAbsolute(step, now);
        break;
    case Instruction::PROFILE_ENABLE:
        changed = stepProfileEnable(step);
        break;
    case Instruction::PROFILE_RESET:
        changed = stepProfileReset(step);
        break;
    case Instruction::PROFILE_WAIT:
        changed = stepProfileWait(step);
        break;
    case Instruction::SETPOINT_ENABLE:
        changed = stepSetpointEnable(step);
        break;
    case Instruction::SETPOINT_SETTING:
        changed = stepSetpointSetting(step);
        break;
    case Instruction::SETPOINT_WAIT:
        changed = stepSetpointWait(step);
        break;
    case Instruction::DIGITAL_ENABLE:
        changed = stepDigitalEnable(step);
        break;
    case Instruction::DIGITAL_SETTING:
        changed = stepDigitalSetting(step);
        break;
    case Instruction::DIGITAL_WAIT:
        changed = stepDigitalWait(step);
        break;
    case Instruction::ANALOG_ENABLE:
        changed = stepAnalogEnable(step);
        break;
    case Instruction::ANALOG_SETTING:
        changed = stepAnalogSetting(step);
        break;
    case Instruction::ANALOG_WAIT:
        changed = stepAnalogWait(step);
        break;
    default:
        // TODO(Bob) error state?
        _enabled = false;
        break;
    }

    if (changed) {
        _activeStep++;
        _activeStepStartedAt = now;
    }

    return changed;
}
