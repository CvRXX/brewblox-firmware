#pragma once

#include "cbox/ObjectContainer.hpp"
#include "cbox/ObjectFactory.hpp"
#include "tl/expected.hpp"

cbox::CboxExpected<std::shared_ptr<cbox::Object>> makeBlock(cbox::obj_type_t t);
