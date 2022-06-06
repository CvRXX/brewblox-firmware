#include "Brewblox.hpp"
#include "cbox/Application.hpp"

namespace cbox {

ObjectContainer& getObjects()
{
    static ObjectContainer objects;
    return objects;
}

ObjectStorage& getStorage()
{
    static ArrayEepromAccess<2048> eeprom;
    static EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

ObjectStorage& getCacheStorage()
{
    static ArrayEepromAccess<2048> eeprom;
    static EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

CboxExpected<std::shared_ptr<Object>> make(obj_type_t t)
{
    return makeBlock(t);
}

std::shared_ptr<Object> scan()
{
    static OneWireScanningFactory oneWireScanner{CboxPtr<OneWire>(4)};
    return oneWireScanner.scan();
}

} // end namespace cbox
