#include "TestObjects.h"

namespace cbox {
template <>
const obj_type_t
interfaceIdImpl<Nameable>()
{
    return 1004;
}
} // end namespace cbox
