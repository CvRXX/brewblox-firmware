#include "OneWireScanningFactory.hpp"
#include "brewblox.hpp"
#include "cbox/ArrayEepromAccess.h"
#include "cbox/CboxApplication.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/ObjectFactory.h"

namespace cbox {

ObjectContainer objects;

std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t)
{
    return brewblox::makeBlock(t);
}

std::shared_ptr<Object> scan()
{
    static OneWireScanningFactory oneWireScanner{CboxPtr<OneWire>(4)};
    return oneWireScanner.scan();
}

ObjectStorage& getStorage()
{
    static cbox::ArrayEepromAccess<2048> eeprom;
    static cbox::EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

} // end namespace cbox
