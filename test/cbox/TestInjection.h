#pragma once

#include "cbox/ArrayEepromAccess.h"
#include "cbox/EepromObjectStorage.h"

namespace test {

extern cbox::ArrayEepromAccess<2048> eeprom;

cbox::EepromObjectStorage& getStorage();

}
