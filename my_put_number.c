#include "my_put_number.h"

size_t my_put_unsigned_short_int(unsigned short int number)
{
	DISPLAY_UNSIGNED(unsigned short int);
}

size_t my_put_signed_short_int(short int number)
{
	DISPLAY_SIGNED(short int);
}

size_t my_put_unsigned_int(unsigned int number)
{
	DISPLAY_UNSIGNED(unsigned int);
}

size_t my_put_signed_int(int number)
{
	DISPLAY_SIGNED(int);
}

size_t my_put_unsigned_long(unsigned long number)
{
	DISPLAY_UNSIGNED(unsigned long);
}

size_t my_put_signed_long(long number)
{
	DISPLAY_SIGNED(long);
}

size_t my_put_unsigned_long_long(unsigned long long number)
{
	DISPLAY_UNSIGNED(unsigned long long);
}

size_t my_put_signed_long_long(long long number)
{
	DISPLAY_SIGNED(long long);
}

size_t my_put_float(double num)
{
	return my_put_signed_long_long(num) 
		 + my_put_char('.') 
		 + my_put_signed_long_long(get_decimal_part(num, ROUNDING_PRECISION));
}