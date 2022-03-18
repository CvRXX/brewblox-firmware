#include "blocks/BlockFactory.hpp"
#include "blocks/OneWireBusBlock.hpp"
#include "blocks/OneWireScanningFactory.hpp"
#include "cbox/Application.hpp"
#include "cbox/CboxPtr.hpp"
#include "cbox/EepromObjectStorage.hpp"
#include "cbox/ObjectFactory.hpp"
#include "control/OneWire.hpp"
#include "spark/SparkEepromAccess.hpp"

namespace cbox {

ObjectStorage& getStorage()
{
    static SparkEepromAccess eeprom;
    static EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

tl::expected<std::shared_ptr<cbox::Object>, cbox::CboxError> make(obj_type_t t)
{
    return makeBlock(t);
}

std::shared_ptr<Object> scan()
{
    static OneWireScanningFactory oneWireScanner{CboxPtr<OneWire>(4)};
    return oneWireScanner.scan();
}

} // end namespace cbox
