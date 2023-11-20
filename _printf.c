#include "main.h"

/**
* _printf - create printf
*@format: Format
*Return: count chars
*/
int _printf(const char *format, ...)
{
    unsigned int i, str_count;
    int count = 0;
    va_list args;

    if (!format)
        return (-1);
    
    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            ++count;
        }
        else if (format[i + 1] == 'c')
        {
            _putchar(va_arg(args, int));
            i++;
            ++count;
        }
        else if (format[i + 1] == 's')
        {
            str_count = print_string(args);
            i++;
            count += str_count;
        }
        else if (format[i + 1] == 'd' || format[i + 1] == 'i')
        {
            int num = va_arg(args, int);
            count += print_digit(num);
            i++;
        }
        else if (format[i + 1] == '%')
        {
            _putchar('%');
            ++count;
            i++;
        }
        else
        {
            va_end(args);
            return (-1);
        }
    }

    va_end(args);
    return (count);
}
