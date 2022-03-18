/* 
 * File:   SensorPin.h
 * Author: mat
 *
 * Created on 22 August 2013, 19:36
 */

#pragma once

#include "Board.h"
#include "Brewpi.h"

class DigitalPinSensor final : public SwitchSensor {
private:
    bool invert;
    uint8_t pin;

public:
    DigitalPinSensor(uint8_t pin, bool invert)
    {
        pinMode(pin, USE_INTERNAL_PULL_UP_RESISTORS ? INPUT_PULLUP : INPUT);
        this->invert = invert;
        this->pin = pin;
    }
    DigitalPinSensor(const DigitalPinSensor&) = delete;
    DigitalPinSensor& operator=(const DigitalPinSensor&) = delete;
    virtual ~DigitalPinSensor() = default;

    virtual bool sense() override final
    {
        return digitalRead(pin) ^ invert;
    }
};
