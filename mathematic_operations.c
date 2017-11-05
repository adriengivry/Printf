#include "mathematic_operations.h"

unsigned long long power(int number, unsigned int exp)
{
	if (exp == 0)
		return 1;
	if (exp == 1)
		return number;

	unsigned long long result = 1;
	while(exp--)
		result *= number;
	return result;
}

unsigned long long get_decimal_part(double number, size_t round_precision)
{
	double decimalPart = number - (long long)number;
	decimalPart += 0.51 * 1 / (power(10, round_precision));
	return decimalPart * power(10, round_precision);
}

unsigned char get_number_length(long long number)
{
	unsigned char numberLength = 1;
	while (number > 9 || number < -9)
	{
		number /= 10;
		++numberLength;
	}
	return numberLength;
}
