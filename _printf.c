#include "main.h"
/**
 * _printf - La función que imprime la salida
 * @format: Cadena de caracteres
 * Return: Número de caracteres impresos (excluyendo el byte nulo)
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int count = 0;
	int i = 0;

	va_list args;

	va_start(args, format);

	print_format_t formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{0, NULL}
	};

	while (format[i] != '\0')
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

		i++;
	}

	va_end(args);

	return (count);
}
