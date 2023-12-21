#include "main.h"

/**
 * error_not_found - print default error message
 *
 * Return: void
 */

int error_not_found(char **ptr, const char *format, ...)
{
	va_list args;

	if (ptr)
		free(ptr);
	if (format != NULL)
	{
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
	}
	return (EXIT_FAILURE);
}


/**
 * print_debug - Print debug messages
 * with automatic new line
 * @format: Format string
 * Return: (0) on success, (-1) on fail
 */

int print_debug(const char *format, ...)
{
	va_list args;
	int format_len = 0;

	if (DEBUG)
	{
		printf("DEBUG_PRINT: ");
		va_start(args, format);
		format_len = vprintf(format, args);
		va_end(args);
		putchar('\n');
	};
	return (format_len);
}
