#include "main.h"

/**
 * print_binary - Converts an unsigned int to binary and prints it
 * @n: The unsigned int to be converted and printed
 * Return: The number of characters printed
 */
int print_binary(unsigned int n)
{
	int printed_chars = 0;

	if (n > 1)
	{
		printed_chars += print_binary(n / 2);
	}

	_putchar((n % 2) + '0');
	printed_chars++;

	return (printed_chars);
}
