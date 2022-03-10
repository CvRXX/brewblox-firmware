#pragma once

#include "cbox/ObjectContainer.h"
#include <memory>

namespace cbox {

const obj_id_t userStartId(100);

// must be implemented in application code
ObjectContainer& getObjects();

// must be implemented in application code
ObjectStorage& getStorage();

// must be implemented in application code
std::tuple<CboxError, std::shared_ptr<Object>> make(const obj_type_t& t);

// must be implemented in application code
std::shared_ptr<Object> scan();

} // end namespace cbox
