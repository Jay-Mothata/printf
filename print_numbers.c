#include "main.h"

/**
 * print_number - Prints an integer
 * @args: The integer to be printed
 */

void print_integer(va_list args)
{
	int n = va_arg(args, int);
	unsigned int u;

	u = n;

	if (n < 0)
	{
		_putchar('-');
		u = -n;
	}
	if (u / 10 != 0)
	{
		print_number(u / 10);
	}
	_putchar((u % 10) + '0');
}

/**
 * print_number - Prints an integer
 * @args: The integer to be printed
 */

void print_decimal(va_list args)
{
        int n = va_arg(args, int);
        unsigned int u;

        u = n;

        if (n < 0)
        {
                _putchar('-');
                u = -n;
        }
        if (u / 10 != 0)
        {
                print_number(u / 10);
        }
        _putchar((u % 10) + '0');
}
