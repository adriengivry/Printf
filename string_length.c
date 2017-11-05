#include "string_length.h"

unsigned int string_length(char const* str)
{
    unsigned int length = 0;

    while (str[length] != '\0')
        length++;

    return length;
}
