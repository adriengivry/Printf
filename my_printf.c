#include "my_printf.h"

size_t my_printf(const char * str, ...)
{
	va_list arg_list;
	size_t charPrinted = 0;

	OptionList* optionList = option_list_create();
	option_list_add(optionList, "d", &print_int);
	option_list_add(optionList, "c", &print_char);
	option_list_add(optionList, "s", &print_string);
	option_list_add(optionList, "f", &print_float);
	option_list_add(optionList, "u", &print_unsigned_int);
	option_list_add(optionList, "p", &print_pointer);
	option_list_add(optionList, "e", &print_scientific);
	option_list_add(optionList, "E", &print_scientific_caps);
	option_list_add(optionList, "ld", &print_long);
	option_list_add(optionList, "ll", &print_long_long);
	option_list_add(optionList, "lu", &print_unsigned_long);
	option_list_add(optionList, "llu", &print_unsigned_long_long);
	option_list_add(optionList, "hd", &print_short);
	option_list_add(optionList, "hu", &print_unsigned_short);

	va_start(arg_list, str);

	while (*str != '\0')
	{
		if (*str == '%')
		{
			int increment = 1;
			Option* optionFound = option_list_find(optionList, ++str, &increment);
			if (optionFound)
			{
				charPrinted += optionFound->ptrDisplayFunction(&arg_list);
				option_destroy(optionFound);
			}
			str += increment;
		}
		else
			charPrinted += my_put_char(*str);
		++str;
	}

	option_list_destroy(optionList);

	va_end(arg_list);

	return charPrinted;
}


