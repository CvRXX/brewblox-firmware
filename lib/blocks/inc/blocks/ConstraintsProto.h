#pragma once

#include "cbox/ObjectContainer.h"
#include "control/ActuatorAnalogConstrained.h"
#include "control/ActuatorDigitalConstrained.h"
#include "proto/Constraints.pb.h"

void setAnalogConstraints(const blox_Constraints_AnalogConstraints& msg, ActuatorAnalogConstrained& act, cbox::ObjectContainer& objects);

void getAnalogConstraints(blox_Constraints_AnalogConstraints& msg, const ActuatorAnalogConstrained& act);

void setDigitalConstraints(const blox_Constraints_DigitalConstraints& msg, ActuatorDigitalConstrained& act, cbox::ObjectContainer& objects);

void getDigitalConstraints(blox_Constraints_DigitalConstraints& msg, const ActuatorDigitalConstrained& act);
