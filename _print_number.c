#include "main.h"

/**
 * print_int_helper - helper function to orinrsrints an integer
 * @num: The integer to be printed
 *
 * Return: number of characters to be printed
 */

int print_int_helper(int num)
{
	int i = 0;

	if (num / 10)
		i += print_int_helper(num / 10);

	_putchar(num % 10 + '0');
	return (i + 1);
}

/**
 * print_int - prints an integer
 * @args: The integer to be printed
 *
 * Return: number of characters to be printed
 */

int print_int(va_list args)
{
	int num;
	int i = 0;
	
	num = va_arg(args, int);
	/* Handle negative numbers */
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		i++;
	}

	if (num / 10)
		i += print_int_helper(num / 10);

	_putchar(num % 10 + '0');
	return (i + 1);
}

/**
 * _print_deci - Prints decimals
 * @format: arguement to print
 *
 * Return: number of chars printed
 */

int _print_deci(const char *format, ...)
{
	int num;

	int i = 0;

	va_list args;

	va_start(args, format);

	num = va_arg(args, int);
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		i++;
	}

	if (num / 10)
		i += print_int_helper(num / 10);

	_putchar(num % 10 + '0');
	va_end(args);
	return (i + 1);
}
