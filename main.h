#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Prints characters to standard output based on a format string.
 * @format: The string that may contain regular characters and format tokens.
 *
 * This version only understands:
 *   %c - prints a single character
 *   %s - prints a string (if the string is NULL, it prints "(null)")
 *   %% -prints a literal '%' character
 *   %d - prints a signed decimal integer
 *   %i - prints a signed decimal integer
 *
 * If you give it any other token like "%x", it will just print "%x" exactly as you typed it.
 *
 * Returns the total number of characters actually printed (not counting any
 * hidden null terminator), or -1 if something goes wrong (for example, if
 * format is NULL or a write() call fails).
 */

int _printf(const char *format, ...);

/* Helper functions for each supported conversion */
int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_integer(int n);

#endif /* MAIN_H */
