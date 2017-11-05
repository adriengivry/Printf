#ifndef _DECIMAL_TO_HEXA_
#define _DECIMAL_TO_HEXA_

#include <stdlib.h>

#include "reverse_string.h"

#ifdef _WIN32
	#define HEXA_CHARS "0123456789ABCDEF"
	#define POINTER_PREFIX '0'
#elif defined __linux__
	#define HEXA_CHARS "0123456789abcdef"
	#define POINTER_PREFIX 'x'
#endif

char* decimal_to_hexa(long number);

#endif // _DECIMAL_TO_HEXA_