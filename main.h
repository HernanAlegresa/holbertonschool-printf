#ifndef MAIN_H
#define MAIN_H

#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/**
 * Struct to hold function pointers for each format specifier
 */
typedef struct print_format
{
    char specifier;
    int (*printer)(va_list args);
} print_format_t;

/* Function prototypes */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif
