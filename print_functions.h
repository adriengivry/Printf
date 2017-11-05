#ifndef _PRINT_FUNCTIONS_
#define _PRINT_FUNCTIONS_

#include <stdarg.h>

#include "my_put_scientific_notation.h"
#include "my_put_number.h"
#include "my_put_pointer.h"

#define CURRENT_ARG(type) (type)va_arg(*args, type)

size_t print_int(va_list* args);
size_t print_char(va_list* args);
size_t print_string(va_list* args);
size_t print_float(va_list* args);
size_t print_unsigned_int(va_list* args);
size_t print_pointer(va_list* args);
size_t print_scientific(va_list* args);
size_t print_scientific_caps(va_list* args);
size_t print_long(va_list* args);
size_t print_long_long(va_list* args);
size_t print_unsigned_long(va_list* args);
size_t print_unsigned_long_long(va_list* args);
size_t print_short(va_list* args);
size_t print_unsigned_short(va_list* args);



#endif // _PRINT_FUNCTIONS_