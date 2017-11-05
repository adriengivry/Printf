#include "print_functions.h"

size_t print_int(va_list * args)
{
	return my_put_signed_int(CURRENT_ARG(int));
}

size_t print_char(va_list * args)
{
	return my_put_char(CURRENT_ARG(int));
}

size_t print_string(va_list * args)
{
	return my_put_string(CURRENT_ARG(char*));
}

size_t print_float(va_list * args)
{
	return my_put_float(CURRENT_ARG(double));
}

size_t print_unsigned_int(va_list * args)
{
	return my_put_unsigned_int(CURRENT_ARG(unsigned int));
}

size_t print_pointer(va_list * args)
{
	return my_put_pointer(CURRENT_ARG(void*));
}

size_t print_scientific(va_list * args)
{
	return my_put_scientific_notation_no_caps(CURRENT_ARG(double));
}

size_t print_scientific_caps(va_list * args)
{
	return my_put_scientific_notation_caps(CURRENT_ARG(double));
}

size_t print_long(va_list * args)
{
	return my_put_signed_long(CURRENT_ARG(long));
}

size_t print_long_long(va_list * args)
{
	return my_put_signed_long_long(CURRENT_ARG(long long));
}

size_t print_unsigned_long(va_list * args)
{
	return my_put_unsigned_long(CURRENT_ARG(unsigned long));
}

size_t print_unsigned_long_long(va_list * args)
{
	return my_put_unsigned_long_long(CURRENT_ARG(unsigned long long));
}

size_t print_short(va_list * args)
{
	return my_put_signed_short_int(CURRENT_ARG(int));
}

size_t print_unsigned_short(va_list * args)
{
	return my_put_unsigned_short_int(CURRENT_ARG(int));
}
