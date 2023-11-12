#include "main.h"

/**
 * write_char - Helper function to write a single character to stdout
 * @c: Character to be written
 * @output_count: Pointer to the count of characters written
 */
static void write_char(char c, int *output_count)
{
	write(1, &c, 1);
	(*output_count)++;
}

/**
 * print_char - Handle the 'c' specifier in the format string
 * @ls_args: Argument list
 * @output_count: Pointer to the count of characters written
 */
static void print_char(va_list ls_args, int *output_count)
{
	int character = va_arg(ls_args, int);

	write_char(character, output_count);
}

/**
 * _printf - a function that produces output according to a format
 * @format: character string (format string)
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ls_args;
	int output_of_chars = 0;

	va_start(ls_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write_char(*format, &output_of_chars);
		}
		else
		{
			switch (*(++format))
			{
			case 'c':
				print_char(ls_args, &output_of_chars);
				break;
			case '%':
				write_char('%', &output_of_chars);
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
