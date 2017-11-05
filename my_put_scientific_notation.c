#include "my_put_scientific_notation.h"

size_t my_put_scientific_notation(double number, char exposant_char)
{
	size_t charCount = 0;

	double tempNumber = number;
	size_t exposant = 1;
	while ((number /= 10) > 9)
		++exposant;
	charCount += my_put_float(number);
	charCount += my_put_char(exposant_char) + my_put_char('+');
	if (exposant < 10)
		charCount += my_put_char('0');
	charCount += my_put_unsigned_int(exposant);
	return charCount;
}

size_t my_put_scientific_notation_no_caps(double number)
{
	size_t charCount = 0;
	char exposant_char = 'e';
	return (my_put_scientific_notation(number, exposant_char));
}

size_t my_put_scientific_notation_caps(double number)
{
	size_t charCount = 0;
	char exposant_char = 'E';
	return (my_put_scientific_notation(number, exposant_char));
}

