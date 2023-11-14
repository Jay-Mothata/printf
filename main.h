#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_TYPE 1
#define STRING_TYPE 2
#define PERCENT_TYPE 3
#define INT_TYPE 4

int _printf(const char *format, ...);
int specifier_handler(int specidfier, va_list args);
void print_char(char charater);
int _putchar (char c);
int print_int(int num);

#endif /*MAIN_H */
