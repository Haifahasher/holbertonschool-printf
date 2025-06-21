#include "main.h"

/**
 * print_char - Prints a single character.
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
 * print_string - Prints a string.
 * @s: The string to print (NULL prints "(null)").
 *
 * Return: Number of characters printed, or -1 on failure.
 */
int print_string(char *s)
{
int len = 0;

if (s == NULL)
s = "(null)";
while (s[len])
len++;
if (write(1, s, len) == -1)
return (-1);
return (len);
}

/**
 * print_percent - Prints a literal '%' character.
 *
 * Return: 1 on success, or -1 on failure.
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
 * Return: Number of characters printed (including '-'),
 *         or -1 on failure.
 */
int print_integer(int n)
{
unsigned int abs;
int count = 0, rv;

if (n < 0)
{
if (write(1, "-", 1) == -1)
return (-1);
count++;
abs = (unsigned int)(-1 * (long)n);
}
else
{
abs = (unsigned int)n;
}

/* Delegate digit printing to print_digits() */
rv = print_digits(abs);
if (rv < 0)
return (-1);
count += rv;

return (count);
}

/**
 * print_binary - Prints an unsigned integer in binary (base 2).
 * @n: The number to print.
 *
 * Return: Number of characters printed, or -1 on error.
 */
int print_binary(unsigned int n)
{
char buf[32];
int i = 0, count = 0;

if (n == 0)
return (write(1, "0", 1) == -1 ? -1 : 1);

while (n)
{
buf[i++] = '0' + (n & 1);
n >>= 1;
}

while (i-- > 0)
{
if (write(1, &buf[i], 1) == -1)
return (-1);
count++;
}

return (count);
}
