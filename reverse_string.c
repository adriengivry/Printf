#include "reverse_string.h"

void reverse_string(char *string)
{
	int length, c;
	char *begin, *end, temp;

	length = string_length(string);
	begin = string;
	end = string;

	for (c = 0; c < length - 1; c++)
		end++;

	for (c = 0; c < length / 2; c++)
	{
		temp = *end;
		*end = *begin;
		*begin = temp;

		begin++;
		end--;
	}
}