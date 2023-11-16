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

	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if(*format == '%' && format[1] != '\0')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += print_char(args);
				break;
			case 's':
				count += print_string(args);
				break;
			case '%':
				count += print_percent(args);
				break;
			default:
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
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
