#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int _printf(const char *format, ...);
void print_char(char charater);
int print_string(const char *str);
int print_percentage(void);

#endif /* MAIN_H */
