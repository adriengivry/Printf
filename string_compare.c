#include "string_compare.h"

int string_compare(char const* str1, char const* str2)
{
	int lengthStr1 = string_length(str1);
	int lengthStr2 = string_length(str2);
	int result;

	int smallestLength = lengthStr1 < lengthStr2 ? lengthStr1 : lengthStr2;

	for (int i = 0; i < smallestLength; i++)
	{
		if (*(str1 + i) < *(str2 + i))
		{
			return -1;
		} else if (*(str1 + i) > *(str2 + i))
		{
			return 1;
		}
	}

	if (lengthStr1 < lengthStr2)
	{
		return -1;
	} else if (lengthStr1 > lengthStr2)
	{
		return 1;
	}

	return 0;

}

