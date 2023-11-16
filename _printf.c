#include "main.h"

/**
 * _printf - Print output according to a format.
 * @format: Character string containing directives.
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return -1;
	va_list args;
	int count = 0;

	va_start(args, format);

	int i;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;

			while (format[i].specifier != 0)
			{
				if (format[i].specifier == format[i])
				{
					count += format[i].printer(args);
					break;
				}
				i++;
			}

			if (format[i].specifier == 0)
				count += _putchar('%') + _putchar(format[i]);
		}
		else
		{
			count += _putchar(format[i]);
		}
	}

	va_end(args);

	return (count);
}
