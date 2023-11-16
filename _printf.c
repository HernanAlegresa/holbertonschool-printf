#include "main.h"

/**
 * _printf - The function that prints output
 * @format: Character string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int i = 0;
	va_list args;
	int count = 0;

	va_start(args, format);

	print_format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	while (*format != '\0')
	{
		if (*format == '%' && format[1] != '\0')
		{
			format++;

			while (formats[i].specifier != 0)
			{
				if (formats[i].specifier == *format)
				{
					count += formats[i].printer(args);
					break;
				}
				i++;
			}

			if (formats[i].specifier == 0) /* Not found, print as is */
				count += write(1, "%", 1) + write(1, format, 1);
		}
		else
		{
			count += write(1, format, 1);
		}

		format++;
	}

	va_end(args);

	return (count);
}
