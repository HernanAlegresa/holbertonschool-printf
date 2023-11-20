#include "main.h"
#include "putchar.c"  /* Incluye otros archivos según sea necesario */

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
