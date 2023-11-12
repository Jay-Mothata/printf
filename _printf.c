#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: character string (format string)
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ls_args;

	va_start(ls_args, format);

	int output_of_chars = 0;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			output_of_chars++;
		}
		else
		{
			switch (*(++format))
			{
				case 'c':
					{
						int character = va_arg(ls_args, int);

						write(1, &character, 1);
						output_of_chars++;
						break;
					}
				case 's':
					{
						char *str = va_arg(ls_args, char *);
						int length = strlen(str);

						write(1, str, length);
						output_of_chars += length;
						break;
					}
				case '%':
					write(1, "%", 1);
					output_of_chars++;
					break;

				default:
					break;
			}
		}
		format++;
	}

	va_end(ls_args);

	return (output_of_chars);
}
