#include "main.h"
#include <string.h>

void _printf(char c[])
{
    int i = 0;

    while(c[i] != '\0')
    {
        _putchar(c[i]);
        i++;
    }
    _putchar('\n');
}
