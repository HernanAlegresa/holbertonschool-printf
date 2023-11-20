#include "main.h"

/**
 * print_string - Print a string
 * @args: Argument list containing the string to be printed
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	if (!str)
	str = "(null)";

	while (*str)
	{
		_putchar(*str);
		count++;
		str++;
	}

	return (count);
}
