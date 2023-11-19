#include "main.h"

int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	va_list args;
	int count = 0;
	int i;

	va_start(args, format);

	struct op
	{
		char specifier;
		int (*printer)(va_list args);
	};

	op_t step[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += get_function(format[i], args);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
	}

	va_end(args);

	return (count);
}

int get_function(char t_step, va_list args)
{
	int i = 0;
	int count = 0;

	op_t step[] = {
	{'c', print_char},
	{'s', print_string},
	{'%', print_percent},
	{0, NULL}
	};

	while (step[i].specifier != 0)
	{
		if (t_step == step[i].specifier)
		{
			count += step[i].printer(args);
			break;
		}
		i++;
	}

	if (step[i].specifier == 0)
		count += write(1, "%", 1) + write(1, &t_step, 1);

	return count;
}
