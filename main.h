#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);
void print_char(char charater);
void print_string(const char *str, int length);

#endif /* MAIN_H */
