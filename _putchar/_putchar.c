#include <unistd.h>
#include "../_printf2/lib/main.h"

/**
 * _putchar - main function
 *
 * @c: user input
 *
 * Return: void
 */

int _putchar(char c)
{
	write(1, &c, 1);
}
