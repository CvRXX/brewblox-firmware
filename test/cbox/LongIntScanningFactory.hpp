#include "TestObjects.hpp"
#include "cbox/Box.hpp"
#include "cbox/Object.hpp"
#include "cbox/ScanningFactory.hpp"
#include <memory>
#include <vector>

namespace cbox {

/**
 * Simple mock factory that emulates object discovery
 * Normally, a scanning factory will scan some type of communication bus
 * This factory just has a list of candidates. If a LongIntObject with that value doesn't exist, it creates it.
 */
class LongIntScanningFactory : public ScanningFactory {
private:
    std::vector<uint32_t> candidates = {0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555};

public:
    LongIntScanningFactory() = default;

    virtual ~LongIntScanningFactory() = default;

    virtual std::shared_ptr<Object> scan() override final
    {
        for (auto& value : candidates) {
            bool found = false;
            for (auto existing = objects.cbegin(); existing != objects.cend(); ++existing) {
                auto ptrIfCorrectType = (*existing)->asInterface<LongIntObject>();
                if (ptrIfCorrectType == nullptr) {
                    continue; // not the right type, no match
                }
                if (ptrIfCorrectType->value() == value) {
                    found = true; // object with value already exists
                    break;
                }
            }
            if (!found) {
                // create new object
                return std::make_shared<LongIntObject>(value);
            }
        }
        return nullptr;
    };
};

} // end namespace cbox
