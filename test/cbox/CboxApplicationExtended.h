#pragma once

#include "cbox/ArrayEepromAccess.h"
#include "cbox/EepromObjectStorage.h"

namespace test {

cbox::ArrayEepromAccess<2048>& getEeprom();

cbox::EepromObjectStorage& getStorage();

}
