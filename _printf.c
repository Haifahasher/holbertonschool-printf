#include "main.h"

/**
 * handle_spec - Process one format specifier.
 * @spec: The character after '%'.
 * @args: The variadic argument list.
 * @count: Pointer to store how many characters the helper printed.
 *
 * Returns:
 *   2 if it fell back to writing "%<spec>" literally,
 *   0 if a helper ran (its count is in *count),
 *  -1 on error.
 */
static int handle_spec(char spec, va_list args, int *count)
{
	int rv;

	switch (spec)
	{
	case 'c':
		rv = print_char((char)va_arg(args, int));
		*count = rv;
		return (rv < 0 ? -1 : 0);
	case 's':
		rv = print_string(va_arg(args, char *));
		*count = rv;
		return (rv < 0 ? -1 : 0);
	case '%':
		rv = print_percent();
		*count = rv;
		return (rv < 0 ? -1 : 0);
	case 'd':
	case 'i':
		rv = print_integer(va_arg(args, int));
		*count = rv;
		return (rv < 0 ? -1 : 0);
	case '\0':
		return (-1);
	default:
		if (write(1, "%", 1) == -1 ||
		    write(1, &spec, 1) == -1)
			return (-1);
		return (2);
	}
}

/**
 * _printf - Prints characters to stdout based on a format string.
 * @format: May contain literal chars and format tokens.
 *
 * Supported tokens: %c, %s, %%, %d, %i. Unknown ones print literally.
 *
 * Return: Total characters printed (not counting a hidden '\0'),
 *         or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *p;
	int total = 0, printed = 0, extra;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	p = format;

	while (*p)
	{
		if (*p != '%')
		{
			if (write(1, p, 1) == -1)
				return (va_end(args), -1);
			total++;
			p++;
			continue;
		}

		p++;
		extra = handle_spec(*p, args, &printed);
		if (extra < 0)
			return (va_end(args), -1);
		total += extra + printed;
		p++;
	}

	va_end(args);
	return (total);
}
