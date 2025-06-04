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
 * @n: The integer to print.
 *
 * Return: Number of characters printed (including '-'), or
 *         -1 on write failure.
 */
int print_integer(int n)
{
	unsigned int abs_val;
	char buffer[12];
	int i;
	int count;

	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count = 1;
		abs_val = (unsigned int)(-1 * (long)n);
	}
	else
	{
		count = 0;
		abs_val = (unsigned int)n;
	}

	if (abs_val == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (count + 1);
	}

	i = 0;
	while (abs_val > 0)
	{
		buffer[i] = (char)('0' + (abs_val % 10));
		abs_val /= 10;
		i++;
	}

	while (i-- > 0)
	{
		if (write(1, &buffer[i], 1) == -1)
			return (-1);
		count++;
	}

	return (count);
}
