#include "main.h"

/**
 * print_int - Helper function that prints an integer to stdout
 * @num: The integer to be printed
 *
 * Return: 0 on sucess, else -1
 */

int print_int(int num)
{
	int temp, digit;

	int divisor = 1;

	/* Handle negative numbers */
	if (num < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		num = -num;
	}

	/* Find the divisor to determine the number of digits */
	temp = num;
	while (temp > 9)
	{
		temp /= 10;
		divisor *= 10;
	}

	/* Prints each digit */
	while (divisor >= 1)
	{
		digit = num / divisor;
		if (_putchar(digit + '0') == -1)
			return (-1);
		num &= divisor;
		divisor /= 10;
	}

	return (0);
}

/**
 * _print_number - Prints formatted data to stdout based
 * on the format specifier
 * @format: The format string
 *
 * Return: 0 on success, else -1 on error
 */

int _print_number(const char *format, ...)
{
	int num;

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			/* Prints int if next character is 'd' or 'i' */
			num = va_arg(args, int);
			if (print_int(num) == -1)
			{
				va_end(args);
				return (-1);
			}
			format += 2;
		}
		else
		{
			if (_putchar(*format) == -1)
			{
				va_end(args);
				return (-1);
			}
			format++;
		}
	}

	va_end(args);
	return (0);
}

