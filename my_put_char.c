#include "my_put_char.h"

size_t my_put_char(char c)
{
	return fwrite(&c, sizeof(char), 1, stdout);
}