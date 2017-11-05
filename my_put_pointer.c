#include "my_put_pointer.h"

size_t my_put_pointer(void* pointer)
{
	size_t charCount = 0;
	char* toPrint = decimal_to_hexa((long)pointer);
	charCount += my_put_string(toPrint);
	free(toPrint);
	return charCount;
}