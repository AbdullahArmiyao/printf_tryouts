#include "lib/main.h"
#include "_printf.c"

void main()
{
    char name[] = "Brian";
    char c = 'c';
    int age = 25;
    _printf("hello world\n");
    _printf("I am %s\n", name);
    _printf("I am %c\n", c);
    _printf("I am %d\n", age);
}
