#include "main.h"

/**
 * _printf - Print output according to a format.
 * @format: Character string containing directives.
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
		if (*format == 
