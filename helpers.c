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

/**
 * print_integer - Prints a signed integer in base 10.
 * @n: Integer to print.
 *
 * Return: Number of chars printed (incl. '-'), or -1 on failure.
 */
int print_integer(int n)
{
	unsigned int abs;
	int cnt = 0, rv;

	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		cnt++;
		abs = (unsigned int)(-1 * (long)n);
	}
	else
	{
		abs = (unsigned int)n;
	}

	rv = print_digits(abs);
	if (rv < 0)
		return (-1);
	cnt += rv;

	return (cnt);
}
