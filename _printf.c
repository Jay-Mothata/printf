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
 * specifier_handler - Handles different data types
 * based on the provided specifier
 * @specifier: Specifier to be handled
 * @args: arguement list
 *
 * Return: Number of characters to be  printed
 */

int specifier_handler(int specifier, va_list args)
{
	char c, *s;

	switch (specifier)
	{
		case CHAR_TYPE:
			c = (char)va_arg(args, int);
			return (write(1, &c, sizeof(char)));
		case STRING_TYPE:
			s = va_arg(args, char *);
			if (s == NULL)
				return (write(1, "(nil)", sizeof("(nil)")));
			return (write(1, s, strlen(s)));
		case PERCENT_TYPE:
			return (write(1, "%", sizeof(char)));
		default:
			return (write(1, "Err! Specifiers", sizeof("Err! Specifiers")));
	}
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
		int specifier;

		if (*format != '%')
		{
			print_char(*format);
			printed_chars++;
		}
		else
		{
			format++;
			/*Call specifier handler based on the specifier*/
			specifier = (*format == 'c') ? CHAR_TYPE :
				    ((*format == 's') ? STRING_TYPE : PERCENT_TYPE);
			printed_chars += specifier_handler(specifier, ls_args);
		}
		format++;
	}

	va_end(ls_args); /*Cleans up variable arguements*/
	return (printed_chars);/*Returns the total chars printed*/
}
