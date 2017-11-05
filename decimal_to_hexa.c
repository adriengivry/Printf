#include "decimal_to_hexa.h"

char* decimal_to_hexa(long number)
{
	char* result = (char*)malloc(sizeof(char));
	int resultSize = 0;
	size_t buff = 0;
	char* c = HEXA_CHARS;
	long tempNum = number;

	while (tempNum > 15)
	{
		result = realloc(result, ++resultSize * sizeof(char));
		result[buff++] = (char)(c[tempNum % 16]);
		tempNum /= 16;
	}

	result = realloc(result, ++resultSize * sizeof(char));
	result[buff++] = (char)(c[tempNum]);

	result = realloc(result, ++resultSize * sizeof(char));
	result[buff++] = POINTER_PREFIX;

	result = realloc(result, ++resultSize * sizeof(char));
	result[buff++] = '0';

	result = realloc(result, ++resultSize * sizeof(char));
	result[buff++] = '\0';

	reverse_string(result);

	return result;
}
