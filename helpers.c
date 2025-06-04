#include "main.h"

/**
 * print_char - Prints a single character to stdout.
 * @c: The character to print.
 *
 * Return: 1 on success, or -1 on write failure.
 */
int print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
