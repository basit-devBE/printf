#include "main.h"

/**
 * _putchar - writes char a to stdout
 * @a: character to print
 *
 * Return: On success 1
 * On error, -1 is returned, and error is set appropriately.
 */
int _putchar(int a)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (a == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (a != BUF_FLUSH)
		buf[i++] = a;
	return (1);
}

/**
 * _puts - will print string with newline
 * @z: string to print
 *
 * Return: void
 */
int _puts(char *z)
{
	char *u = z;

	while (*z)
		_putchar(*z++);
	return (z - u);
}

