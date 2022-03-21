#pragma once

#include "cbox/ObjectContainer.hpp"
#include "tl/expected.hpp"
#include <memory>
#include <string>

namespace cbox {

// Must be implemented in application code
ObjectStorage& getStorage();

// Must be implemented in application code
CboxExpected<std::shared_ptr<Object>> make(obj_type_t t);

// Must be implemented in application code
std::shared_ptr<Object> scan();

// Must be implemented in application code
std::string handshakeMessage();

} // end namespace cbox
