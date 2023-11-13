#include "main.h"
#include <stdio.h> 

void print_integer(int number, char specifier)
{
    if (specifier == 'd' || specifier == 'i')
    {
        char buffer[50];
        int length;

        length = sprintf(buffer, "%d\n", number);
        write(1, buffer, length);
    }
}
