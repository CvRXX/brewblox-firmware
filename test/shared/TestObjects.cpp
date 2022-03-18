#include "TestObjects.hpp"

namespace cbox {
template <>
obj_type_t
interfaceIdImpl<Nameable>()
{
    return 1004;
}
} // end namespace cbox
