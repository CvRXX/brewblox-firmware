// This file corrects intellisense mishaps
// It is a no-op for executable code

#pragma once

#ifdef __INTELLISENSE__

// Intellisense drops the quotes surrounding defined string values
// Values defined here are only ever placeholder, and will never be used in compiled code
#define GIT_VERSION ""
#define GIT_DATE ""
#define PLATFORM_NAME "gcc"

// In intellisense mode, __linux__ is defined by default
// This leads to various system headers trying to include
// unavailable headers like 'linux/version.h'.
#undef __linux__

#endif
