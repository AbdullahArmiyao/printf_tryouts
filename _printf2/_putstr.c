#include "lib/main.h"

/**
 * _putstr - print string but without new line
 * @s: string
 * Return: length of string
*/

int _putstr(char *s){
    int len = 0;

    while (*s)
    {
        len += _putchar(*s);
        s++;
    }

    return (len);

}
