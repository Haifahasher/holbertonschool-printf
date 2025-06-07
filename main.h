#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Prints to stdout using a simple format.
 * @format: String of normal chars and % tokens.
 *
 * Supports: %c, %s, %%, %d, %i.
 * Unknown tokens print literally (e.g. "%x").
 *
 * Return: Number of chars printed (excluding null byte),
 *         or -1 on error.
 */
int _printf(const char *format, ...);

int print_char(char c);
int print_string(char *s);
int print_percent(void);
int print_integer(int n);

#endif /* MAIN_H */
