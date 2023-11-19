#include "main.h"
/**
 *
 *
 *
 *
 */
int get_function(char t_st, va_list args)
{
	int i = 0;
	int count = 0;

	print_format_t st[] = {
		{'c', print_char.c},
		{'s', print_string.c},
		{'%', print_percent.c},
		{'d', print_decimal.c},
		{'i', print_decimal.c},
		{0, NULL}
	};
