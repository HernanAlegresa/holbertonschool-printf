#include "main.h"
/**
 * print_percent - Print a percent character.
 * @args: Argument list
 * Return: Number of characters printed (always 1 for percent).
 */
int print_percent(va_list args)
{
	(void)args;
	return write(1, "%", 1);
}
