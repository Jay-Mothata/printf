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
 *
 * Return: character printed
 */

int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		print_char(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * print_percentage - Helper function to handle
 * '%'
 * Return: 1
 */

int print_percentage(void)
{
	print_char('%');
	return (1);
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

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			print_char(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				print_char((char)va_arg(ls_args, int));
				printed_chars++;
			}
			else if (*format == 's')
				printed_chars += print_string(va_arg(ls_args, const char *));
			else if (*format == '%')
				printed_chars += print_percentage();
		}
		format++;
	}
	va_end(ls_args); /*Cleans up variable arguements*/
	return (printed_chars);/*Returns the total chars printed*/
}
