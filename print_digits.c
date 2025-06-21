#include "main.h"

/**
 * print_digits - Writes an unsigned int as decimal digits.
 * @n: The number to print.
 *
 * Return: Number of digits printed, or -1 on write failure.
 */
int print_digits(unsigned int n)
{
char buf[12];
int i = 0, cnt = 0;

if (n == 0)
{
if (write(1, "0", 1) == -1)
return (-1);
return (1);
}

while (n)
{
buf[i++] = '0' + (n % 10);
n /= 10;
}
while (i-- > 0)
{
if (write(1, &buf[i], 1) == -1)
return (-1);
cnt++;
}
return (cnt);
}
