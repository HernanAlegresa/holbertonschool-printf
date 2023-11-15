#include "main.h"
/**
 * print_char - Print single character
 * @args: list containing the character to be printed
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	return write(1, &c, 1);
}
