#include "OneWireScanningFactory.hpp"
#include "SparkEepromAccess.h"
#include "blocks/OneWireBusBlock.h"
#include "brewblox.hpp"
#include "cbox/CboxPtr.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/Injection.h"
#include "cbox/ObjectFactory.h"
#include "control/OneWire.h"

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
    static SparkEepromAccess eeprom;
    static EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

} // end namespace cbox
