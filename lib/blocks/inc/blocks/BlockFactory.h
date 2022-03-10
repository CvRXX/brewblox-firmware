#pragma once

#include "cbox/ObjectContainer.h"
#include "cbox/ObjectFactory.h"

std::tuple<cbox::CboxError, std::shared_ptr<cbox::Object>> makeBlock(const cbox::obj_type_t& t);
