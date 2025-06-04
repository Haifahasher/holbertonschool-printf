#include "main.h"

/**
 * _printf - Prints characters to stdout based on a format string.
 * @format: The string that may contain regular characters and format tokens.
 *
 * Supported conversions will be added later.
 *
 * Return: Number of characters printed,
 *         or -1 on error or if format is NULL.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *p;
	int total;
	int printed;

	if (format == NULL)
		return (-1);

	total = 0;
	va_start(args, format);
	p = format;

	while (*p)
	{
		if (*p != '%')
		{
			if (write(1, p, 1) == -1)
			{
				va_end(args);
				return (-1);
			}
			total++;
			p++;
			continue;
		}

	p++;
	switch (*p)
		{
		case 'c':
			printed = print_char((char)va_arg(args, int));
			break;
		case 's':
			printed = print_string(va_arg(args, char *));
			break;
		case '%':
			printed = print_percent();
			break;
		case '\0':
			va_end(args);
			return (-1);
		default:
			if (write(1, "%", 1) == -1 ||
			    write(1, p, 1) == -1)
			{
				va_end(args);
				return (-1);
			}
			total += 2;
			printed = 0;
			break;
		}

		if (printed < 0)
		{
			va_end(args);
			return (-1);
		}

		total += printed;
		p++;

	}

	va_end(args);

	return (total);
}
