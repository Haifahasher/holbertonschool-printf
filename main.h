#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Produces output according to a format string.
 * @format: The format string (if NULL, return -1).
 *
 * Supported conversions: %c, %s, %%
 *   - %c: print a single character
 *   - %s: print a string (if NULL, prints "(null)")
 *   - %%: print a literal '%'
 *
 * Any other sequence "%X" prints '%' followed by 'X' literally.
 * Return: Number of characters printed (excluding null byte),
 *         or -1 on error.
 */
int _printf(const char *format, ...);

/* Helper functions for each supported conversion */
int print_char(char c);
int print_string(char *s);
int print_percent(void);

#endif /* MAIN_H */
