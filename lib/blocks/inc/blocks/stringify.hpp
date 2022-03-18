#pragma once
// TODO(Bob) this helper file does not belong in blocks

#ifndef stringify
#define stringify(x) __stringify(x)
#define __stringify(x) #x
#endif
