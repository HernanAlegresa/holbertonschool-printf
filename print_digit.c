#include "main.h"

/**
 * printdigit - Print integers
 * @args: Argument list containing the integer to be printed
 * Return: Number of characters printed
 */
int print_digit(int num)
{
    int count = 0;

    if (num < 0)
    {
        _putchar('-');
        num = -num;
        ++count;
    }

    if (num / 10)
    {
        count += print_digit(num / 10);
    }

    _putchar(num % 10 + '0');
    return (count + 1);
}
