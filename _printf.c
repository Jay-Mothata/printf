#include "main.h"

/**
 * print_char - Helper function to write a single character to stdout
 * @character: Character to be written
 */

void print_char(char character)
{
	write(1, &character, 1);
}

/**
 * print_string - Helps to print a string of a specified length
 * @str: String to be printed
 * @count: counts characted printed
 *
 * Return: character printed
 */

int print_string(const char *str, int count)
{
	count = 0;

	while (*str)
	{
		print_char(*str);
		count++;
	}
	return (count);
}

/**
 * _printf - a function that produces output according to a format
 * @format: character string (format string)
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;

	va_list ls_args;

	va_start(ls_args, format);

	while (*format)
	{
		const char *str;

		if (*format != '%')
		{
			print_char(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == 'c' || *format == '%')
			{
				print_char((*format == 'c') ? va_arg(ls_args, int) : '%');
				printed_chars++;
			}
			else if (*format == 's')
			{
				str = va_arg(ls_args, const char *);
				while (*str)
				{
					print_char(*str);
					str++;
					printed_chars++;
				}
			}
		}
		format++;
	}
	va_end(ls_args); /*CLeans up variable arguements*/
	return (printed_chars);/*Returns the total chars printed*/
}
