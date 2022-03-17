#pragma once

#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"
#include "tl/expected.hpp"

cbox::CboxExpected<std::shared_ptr<cbox::Object>> makeBlock(const cbox::obj_type_t& t);
