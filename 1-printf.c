#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "main.h"

/**
 * write_and_count - writes to the stdout and increments the count
 * @fd: file descriptor -> 1 for the std output
 * @buf: buffer to be written to the output stream
 * @n: size of the buffer
 * @count: number of characters written to the output stream
 *
 * Return: returns the count;
 */
int write_and_count(int fd, const void *buf, size_t n, int count)
{
	ssize_t write_res = write(fd, buf, n);
	if (write_res < 0)
		return count;
	count += write_res;
	return count;
}

/**
 * _printf - prints formatted text to the stdout
 * @format: how the text will be formatted
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return 0;

	va_list args;
	va_start(args, format);
	int char_printed_count = 0;
	const char *p = format;

	while (*p != '\0')
	{
		if (*p != '%')
		{
			char_printed_count = write_and_count(1, p, 1, char_printed_count);
			p++;
			continue;
		}

		p++;
		if (*p == '\0')
			break;

		int (*result)(int, va_list) = get_handler(*p);
		if (result == NULL)
			return char_printed_count;

		char_printed_count = result(char_printed_count, args);
		p++;
	}

	va_end(args);
	return char_printed_count;
}
