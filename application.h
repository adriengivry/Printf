#ifndef _APPLICATION_
#define _APPLICATION_

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "my_printf.h"

#define COMPARE(codes, ...) \
		my_printf("\n   PRINTF (%s): ", codes);\
		printf(codes, __VA_ARGS__);\
		my_printf("\nMY_PRINTF (%s): ", codes);\
		my_printf(codes, __VA_ARGS__);\
		my_printf("\n");

unsigned char application_run_test();

#endif // _APPLICATION_