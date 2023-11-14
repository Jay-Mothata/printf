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
	char *s;
	int result;

	switch (specifier)
	{
		case CHAR_TYPE:
			{
				char c = (char)va_arg(args, int);

				return (write(1, &c, sizeof(char)));
			}
		case STRING_TYPE:
			s = va_arg(args, char *);
			if (s == NULL)
				s = "(nil)";
			return (write(1, s, strlen(s)));
		case PERCENT_TYPE:
			return (write(1, "%", sizeof(char)));
		default:
			return (-1);
	}

	return (result);
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
	int result;

	va_list ls_args;

	if (format == NULL)
		return (-1);

	va_start(ls_args, format);

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
			/* Call specifier handler based on the specifier */
			specifier = (*format == 'c') ? CHAR_TYPE :
				((*format == 's') ? STRING_TYPE : PERCENT_TYPE);
			result = specifier_handler(specifier, ls_args);

			if (result == -1)
			{
				va_end(ls_args);
				return (-1);
			}
			printed_chars += result;
		}
		format++;
	}

	va_end(ls_args); /*Cleans up variable arguements*/
	return (printed_chars);/*Returns the total chars printed*/
}
