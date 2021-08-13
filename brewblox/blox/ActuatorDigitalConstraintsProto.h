#pragma once

#include "ActuatorDigitalConstrained.h"
#include "cbox/ObjectContainer.h"
#include "compiled_proto/src/DigitalConstraints.pb.h"

void setDigitalConstraints(const blox_DigitalConstraints& msg, ActuatorDigitalConstrained& act, cbox::ObjectContainer& objects);

void getDigitalConstraints(blox_DigitalConstraints& msg, const ActuatorDigitalConstrained& act);
