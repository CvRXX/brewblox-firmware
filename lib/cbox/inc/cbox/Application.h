#pragma once

#include "cbox/ObjectContainer.h"
#include <memory>

namespace cbox {

// Must be implemented in application code
ObjectStorage& getStorage();

// Must be implemented in application code
std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t);

// Must be implemented in application code
std::shared_ptr<Object> scan();

} // end namespace cbox
