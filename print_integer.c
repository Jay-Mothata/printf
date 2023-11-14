#include "main.h"

/**
 * print_integer - Prints an integer
 * @args: The integer to be printed
 */

void print_integer(va_list args)
{
	int n = va_arg(args, int); /* Retrieve the integer argument */
	unsigned int u;

	u = (n < 0) ? -n : n; /* Calculate the absolute value of the integer */

	if (n < 0)
	{
		_putchar('-'); /* Print a minus sign for negative integers */
	}

	if (u / 10 != 0)
	{
		print_integer(u / 10); /* Recursively call the function to print the remaining digits */
	}

	_putchar((u % 10) + '0');  /* Print the last digit */
}
