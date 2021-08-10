#pragma once

#include "ActuatorAnalogConstrained.h"
#include "cbox/ObjectContainer.h"
#include "compiled_proto/src/AnalogConstraints.pb.h"

void setAnalogConstraints(const blox_AnalogConstraints& msg, ActuatorAnalogConstrained& act, cbox::ObjectContainer& objects);

void getAnalogConstraints(blox_AnalogConstraints& msg, const ActuatorAnalogConstrained& act);
