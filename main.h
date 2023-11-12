#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
void write_char(char c, int *output_count);
void print_char(va_list ls_args, int *output_count);

#endif /* MAIN_H */
