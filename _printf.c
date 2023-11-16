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

	int i;  // Declare 'i' at the beginning of the block

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;

			while (formats[i].specifier != 0)
			{
				if (formats[i].specifier == format[i])
				{
					count += formats[i].printer(args);
					break;
				}
				i++;
			}

			if (formats[i].specifier == 0)
				count += write(1, "%", 1) + write(1, &format[i], 1);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
	}

	va_end(args);

	return (count);
}
