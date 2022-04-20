#pragma once

#include "cbox/EepromAccess.hpp"
#include "cbox/EepromObjectStorage.hpp"

namespace test {

cbox::ArrayEepromAccess<2048>& getEeprom();

cbox::EepromObjectStorage& getStorage();

}
