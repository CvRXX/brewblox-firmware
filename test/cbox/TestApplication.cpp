#include "TestApplication.h"
#include "LongIntScanningFactory.hpp"
#include "TestObjects.h"
#include "cbox/Application.h"
#include "cbox/ArrayEepromAccess.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/ObjectFactory.h"

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

ObjectContainer& getObjects()
{
    static ObjectContainer objects;
    return objects;
}

ObjectStorage& getStorage()
{
    return test::getStorage();
}

std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t)
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

} // end namespace cbox
