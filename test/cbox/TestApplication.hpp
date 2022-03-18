#pragma once

#include "cbox/ArrayEepromAccess.hpp"
#include "cbox/EepromObjectStorage.hpp"

namespace test {

cbox::ArrayEepromAccess<2048>& getEeprom();

cbox::EepromObjectStorage& getStorage();

}
