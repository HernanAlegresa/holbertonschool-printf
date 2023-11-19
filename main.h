#ifndef MAIN_H
#define MAIN_H

#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct op
{
	char specifier;
	int (*printer)(va_list args);
} print_format_t;

/* Function prototypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
<<<<<<< HEAD
int _putchar(char c);
int print_decimal(va_list args);
int get_function
=======
>>>>>>> 68b7c726e8478d4620dd9b7502a755f9a1fdb1f2

#endif
