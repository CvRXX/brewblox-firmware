#include "blocks/BlockFactory.h"
#include "blocks/OneWireBusBlock.h"
#include "blocks/OneWireScanningFactory.hpp"
#include "cbox/Application.h"
#include "cbox/CboxPtr.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/ObjectFactory.h"
#include "control/OneWire.h"
#include "spark/SparkEepromAccess.h"

namespace cbox {

ObjectContainer& getObjects()
{
    static ObjectContainer objects;
    return objects;
}

ObjectStorage& getStorage()
{
    static SparkEepromAccess eeprom;
    static EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t)
{
    return makeBlock(t);
}

std::shared_ptr<Object> scan()
{
    static OneWireScanningFactory oneWireScanner{CboxPtr<OneWire>(4)};
    return oneWireScanner.scan();
}

} // end namespace cbox
