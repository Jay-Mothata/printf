#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/* Prototype function for _printf */
int _printf(const char *format, ...);
void write_char(char c, int *output_count);
void print_char(va_list ls_args, int *output_count);
void print_string(va_list ls_args, int *output_count);

/* Task 1 */
void print_integer(int number, char specifier);

#endif

