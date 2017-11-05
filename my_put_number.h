#ifndef _MY_PUT_NUMBER_
#define _MY_PUT_NUMBER_

#include <stdlib.h>
#include <stdbool.h>

#include "my_put_char.h"
#include "my_put_string.h"
#include "mathematic_operations.h"

#define ROUNDING_PRECISION 6

#define CREATE_COPY(type) type numberCopy = number;\

#define INIT_COUNTER()\
		size_t charCount = 0;\
		unsigned char numberLength = 1;\

#define DISPLAY_SIGN()\
		if (number < 0)\
			charCount += my_put_char('-');\

#define GET_SIGNED_LENGTH()\
		while (numberCopy > 9 || numberCopy < -9)\
		{\
			++numberLength; \
			numberCopy /= 10; \
		}\

#define GET_UNSIGNED_LENGTH()\
		while (numberCopy > 9)\
		{\
			++numberLength; \
			numberCopy /= 10; \
		}\

#define DISPLAY_NUMBER()\
		char* stringToPrint = (char*)malloc(sizeof(char) * numberLength + 1);\
		char digit;\
		unsigned char numberLengthBuff = numberLength;\
		bool addOneToLastDigit = false;\
		if (charCount == 1)\
			addOneToLastDigit = true;\
		while (numberLengthBuff)\
		{\
			digit = number % 10;\
			if (digit < 0)\
				digit *= -1;\
			number /= 10;\
			stringToPrint[--numberLengthBuff] = 48 + digit;\
		}\
		stringToPrint[numberLength] = '\0';\
		charCount += my_put_string(stringToPrint);\
		free(stringToPrint);\

#define RETURN_COUNTER() return charCount;\

#define DISPLAY_SIGNED(type)\
		CREATE_COPY(type);\
		INIT_COUNTER();\
		DISPLAY_SIGN();\
		GET_SIGNED_LENGTH()\
		DISPLAY_NUMBER();\
		RETURN_COUNTER();\

#define DISPLAY_UNSIGNED(type)\
		CREATE_COPY(type);\
		INIT_COUNTER();\
		GET_UNSIGNED_LENGTH();\
		DISPLAY_NUMBER();\
		RETURN_COUNTER();\

size_t my_put_unsigned_short_int(unsigned short int number);
size_t my_put_signed_short_int(short int number);
size_t my_put_unsigned_int(unsigned int number);
size_t my_put_signed_int(int number);
size_t my_put_unsigned_long(unsigned long number);
size_t my_put_signed_long(long number);
size_t my_put_unsigned_long_long(unsigned long long number);
size_t my_put_signed_long_long(long long number);
size_t my_put_float(double num);

#endif // _MY_PUT_NUMBER_
