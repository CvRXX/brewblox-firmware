#include "blocks/BlockFactory.hpp"
#include "blocks/OneWireScanningFactory.hpp"
#include "cbox/Application.hpp"
#include "cbox/ArrayEepromAccess.hpp"
#include "cbox/EepromObjectStorage.hpp"
#include "cbox/ObjectFactory.hpp"

namespace cbox {

ObjectStorage& getStorage()
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

std::string handshakeMessage()
{
    return "handshake";
}

} // end namespace cbox
