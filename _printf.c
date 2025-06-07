#include "main.h"

/**
 * handle_spec - Handle one specifier after '%'.
 * @spec: The character after '%'.
 * @args: The variadic argument list.
 * @count: Where to store how many chars the helper printed.
 *
 * spec = 'c' → print_char
 * spec = 's' → print_string
 * spec = '%' → print_percent
 * spec = 'd'/'i' → print_integer
 * spec = '\0' → error
 * otherwise → write "%<spec>" literally
 *
 * Return: 2 if it printed "%<spec>",
 *         0 if a helper did the printing,
 *        -1 on error.
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
 * _printf - Prints to stdout according to a format string.
 * @format: String of normal chars and % tokens.
 *
 * Supports: %c, %s, %%, %d, %i.
 * Unknown tokens print literally (e.g. "%x").
 *
 * Return: Number of chars printed (excluding null byte),
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

		/* Skip '%' and process the next char */
		p++;
		printed = 0;
		extra = handle_spec(*p, args, &printed);
		if (extra < 0)
			return (va_end(args), -1);
		total += extra + printed;
		p++;
	}

	va_end(args);
	return (total);
}
