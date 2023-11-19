#include "main.h"
/**
 * print_string - Print a decimal value
 * @args: list containing the string to be printed
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	int *dec = va_arg(args, int *);
	int len = 0;

	if (dec < 0)
	{
		print_char('-');
		dec = -dec;
		len++;
	}
	if (dec = 0)
		len += print_char('0');
	while (dec > 0)
	{
		int digit = decimal % 10;
		char digit_c = '0' + digit;
		len += print_char(digit_c);
		dec /= 10;
	}

	return write(1, dec, len);
}
