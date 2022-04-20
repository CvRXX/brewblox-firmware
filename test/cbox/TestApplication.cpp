#include "TestApplication.hpp"
#include "LongIntScanningFactory.hpp"
#include "TestObjects.hpp"
#include "cbox/Application.hpp"
#include "cbox/EepromAccess.hpp"
#include "cbox/EepromObjectStorage.hpp"
#include "cbox/ObjectFactory.hpp"

namespace test {

cbox::ArrayEepromAccess<2048>& getEeprom()
{
    static cbox::ArrayEepromAccess<2048> eeprom;
    return eeprom;
}

cbox::EepromObjectStorage& getStorage()
{
    static cbox::EepromObjectStorage objectStore(getEeprom());
    return objectStore;
}

} // end namespace test

namespace cbox {

ObjectStorage& getStorage()
{
    return test::getStorage();
}

cbox::ObjectStorage& getCacheStorage()
{
    static cbox::ArrayEepromAccess<2048> eeprom;
    static cbox::EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

CboxExpected<std::shared_ptr<Object>> make(obj_type_t t)
{
    static const ObjectFactory factory = {
        makeFactoryEntry<LongIntObject>(),
        makeFactoryEntry<LongIntVectorObject>(),
        makeFactoryEntry<UpdateCounter>(),
        makeFactoryEntry<PtrLongIntObject>(),
        makeFactoryEntry<NameableLongIntObject>(),
        makeFactoryEntry<MockStreamObject>(),
    };

    return factory.make(t);
}

std::shared_ptr<Object> scan()
{
    static LongIntScanningFactory longIntScanner;
    return longIntScanner.scan();
}

std::string handshakeMessage()
{
    return "handshake";
}

} // end namespace cbox
