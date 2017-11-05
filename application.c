#include "application.h"

unsigned char application_run_test()
{
	double myDouble = 5551.428571428;
	double myOtherDouble = 36542364.87963;

	COMPARE("%d %d %u %u %hd %hd %hu %hu", INT_MIN, INT_MAX, 0, UINT_MAX, SHRT_MIN, SHRT_MAX, 0, USHRT_MAX);
	COMPARE("%f", myDouble);
	COMPARE("%e %E", myOtherDouble, myOtherDouble);
	COMPARE("%p", &myDouble);
	COMPARE("%c %c %s", CHAR_MIN, CHAR_MAX, "Seems working very well!");

	return EXIT_SUCCESS;
}