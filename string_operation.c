#include "string_operation.h"

bool string_contain_from_start(const char* str, char* toFind)
{
	size_t strLength = string_length(toFind);

	while (str != '\0' && strLength--)
	{
		if (*str++ != *toFind++)
			return false;
	}

	return true;
}