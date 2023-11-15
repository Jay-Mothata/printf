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
#define BINARY_TYPE 5

/* Custom _putchar function for printing to stdout */
int _putchar(char c);

/* Prototypes for handling %c, %s, %d specifiers */
int _printf(const char *format, ...);
int specifier_handler(int specidfier, va_list args);
void print_char(char charater);

/* Prototypes for handling %d and %i specifiers */
int _print_deci(const char *format, ...);
int print_int(va_list args);
int print_int_helper(int num);

/*Protyotype for  handling %b specifiers */
int print_binary(unsigned int n);

#endif /*MAIN_H */
