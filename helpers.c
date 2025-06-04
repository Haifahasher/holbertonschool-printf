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

/**
 * print_string - Prints a string to stdout.
 * @s: The string to print (if NULL, prints "(null)").
 *
 * Return: Number of characters printed, or -1 on write failure.
 */
int print_string(char *s)
{
	int len;

	if (s == NULL)
		s = "(null)";

	len = 0;
	while (s[len])
		len++;

	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}
/**
 * print_percent - Prints a single '%' character.
 *
 * Return: 1 on success, or -1 on write failure.
 */
int print_percent(void)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}
