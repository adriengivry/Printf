#ifndef _MY_PUT_SCIENTIFIC_NOTATION_
#define _MY_PUT_SCIENTIFIC_NOTATION_

#include <stdbool.h>

#include "my_put_number.h"

size_t my_put_scientific_notation(double number, char exposant_char);
size_t my_put_scientific_notation_no_caps(double number);
size_t my_put_scientific_notation_caps(double number);

#endif // _MY_PUT_SCIENTIFIC_NOTATION_