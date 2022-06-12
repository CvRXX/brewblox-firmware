// This file corrects intellisense mishaps
// It is a no-op for executable code

#pragma once

#ifdef __INTELLISENSE__

// Intellisense drops the quotes surrounding defined string values
// Values defined here are only ever placeholder, and will never be used in compiled code
#define GIT_VERSION "abcdef01"
#define GIT_DATE "2000-01-01"
#define PLATFORM_NAME "sim"

#endif
