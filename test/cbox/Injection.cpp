#include "cbox/Injection.h"
#include "LongIntScanningFactory.hpp"
#include "TestInjection.h"
#include "TestObjects.h"
#include "cbox/ArrayEepromAccess.h"
#include "cbox/EepromObjectStorage.h"
#include "cbox/ObjectFactory.h"

namespace test {

cbox::ArrayEepromAccess<2048> eeprom;

cbox::EepromObjectStorage& getStorage()
{
    static cbox::EepromObjectStorage objectStore(eeprom);
    return objectStore;
}

} // end namespace test

namespace cbox {
cbox::ObjectContainer objects;

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

ObjectStorage& getStorage()
{
    return test::getStorage();
}

} // end namespace cbox
