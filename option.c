#include "option.h"

OptionList * option_list_create()
{
	OptionList* optionList = (OptionList*)malloc(sizeof(OptionList));
	if (!optionList)
		return NULL;

	optionList->head = NULL;
	optionList->tail = NULL;

	return optionList;
}

void option_list_destroy(OptionList * optionList)
{
	if (!optionList)
		return;

	Option* current = optionList->head;
	Option* next = NULL;

	while (current)
	{
		next = current->next;
		option_destroy(current);
		current = next;
	}

	free(optionList);
}

void option_list_add(OptionList* optionList, char * code, size_t(*ptrDisplayFunction)(va_list*))
{
	if (!optionList)
		return;

	Option* newOption = option_create(code, ptrDisplayFunction);
	if (!newOption)
		return;

	option_list_add_existant(optionList, newOption);
}

void option_list_add_existant(OptionList* optionList, Option* option)
{
	if (!optionList || !option)
		return;

	if (!optionList->head)
	{
		optionList->head = option;
		optionList->tail = option;
	}
	else
	{
		optionList->tail->next = option;
		optionList->tail = option;
	}
}

Option* option_list_find(OptionList * optionList, const char * str, int* increment)
{
	if (!optionList)
		return NULL;

	Option* current = optionList->head;
	Option* toReturn = NULL;
	OptionList* foundOptions = option_list_create();
	bool found = false;

	while (current)
	{
		if (string_contain_from_start(str, current->code))
			option_list_add(foundOptions, current->code, current->ptrDisplayFunction);
		current = current->next;
	}

	current = foundOptions->head;
	if (!current)
		return NULL;

	size_t higherPriority = option_get_priority(current);
	size_t currentPriority;

	while (current)
	{
		currentPriority = option_get_priority(current);
		if (higherPriority < currentPriority)
			higherPriority = currentPriority;
		current = current->next;
	}

	current = foundOptions->head;
	while (current && !found)
	{
		if (option_get_priority(current) == higherPriority)
		{
			toReturn = option_create(current->code, current->ptrDisplayFunction);
			found = true;
		}
		current = current->next;
	}

	*increment = higherPriority - 1;

	option_list_destroy(foundOptions);

	return toReturn;
}

Option * option_create(char * code, size_t(*ptrDisplayFunction)(va_list*))
{
	Option* option = (Option*)malloc(sizeof(Option));
	if (!option)
		return NULL;

	string_copy(code, &option->code);

	option->ptrDisplayFunction = ptrDisplayFunction;
	option->next = NULL;

	return option;
}

void option_destroy(Option * option)
{
	if (!option)
		return;

	free(option->code);
	option->ptrDisplayFunction = NULL;
	option->next = NULL;
	free(option);
}

size_t option_get_priority(Option * option)
{
	return string_length(option->code);
}
