#include "TestObjects.hpp"
#include "cbox/Claimable.hpp"

// instantiate templates that are virtual interfaces explicitly to assign an ID

namespace cbox {
template <>
obj_type_t
interfaceIdImpl<Nameable>()
{
    return 10;
}

template <>
obj_type_t
interfaceIdImpl<Claimable>()
{
    return 11;
}
} // end namespace cbox
