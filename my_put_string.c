#include "my_put_string.h"

size_t my_put_string(const char *string)
{
	size_t charCount = 0;

	if (!string)
		return 0;

	while (*string++ != '\0')
		charCount += my_put_char(*(string - 1));

	return charCount;
}
