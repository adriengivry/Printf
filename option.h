#ifndef _OPTION_
#define _OPTION_

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#include "my_put_string.h"
#include "string_copy.h"
#include "string_compare.h"
#include "string_operation.h"

typedef struct s_option Option;
struct s_option
{
	char* code;
	size_t (*ptrDisplayFunction)(va_list* args);
	Option* next;
};


typedef struct s_option_list OptionList;
struct s_option_list
{
	Option* head;
	Option* tail;
};

OptionList* option_list_create();
void option_list_destroy(OptionList* optionList);
void option_list_add(OptionList* optionList, char* code, size_t(*ptrDisplayFunction)(va_list*));
void option_list_add_existant(OptionList* optionList, Option* option);
Option* option_list_find(OptionList* optionList, const char* str, int* increment);
Option* option_create(char* code, size_t(*ptrDisplayFunction)(va_list*));
void option_destroy(Option* option);
size_t option_get_priority(Option* option);


#endif // _OPTION_