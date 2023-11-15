#include "main.h"
/**
 * print_string - Print a string of characters
 * @args: list containing the string to be printed
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	int len = 0;
	while (str[len] != '\0')
		len++;

	return write(1, str, len);
}
