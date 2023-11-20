#include "main.h"

/**
 * print_char - Print a character
 * @args: Argument list containing the character to be printed
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
