#include <unistd.h>

/**
 * _putchar - write a character to stdout
 * @c: the character to write
 *
 * Return: 1 on success. -1 on error and errno is set
 */
int _putchar(int c)
{
	write(1, &c, 1);
}
