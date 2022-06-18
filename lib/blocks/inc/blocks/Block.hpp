#pragma once

#include "cbox/ObjectBase.hpp"
#include "proto/brewblox.pb.h"
#include <type_traits>

template <uint16_t id>
using Block = cbox::ObjectBase<id>;
