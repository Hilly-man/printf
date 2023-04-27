#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - my customized printf file
 * @format: filled out properly later
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
<<<<<<< HEAD
				case 'i':
=======
>>>>>>> c489567565dffc79bde813489a5292196beff085
					printed_chars += printf("%d", va_arg(args, int));
					break;
				case 's':
					printed_chars += printf("%s", va_arg(args, char *));
<<<<<<< HEAD
				break;
=======
					break;
>>>>>>> c489567565dffc79bde813489a5292196beff085
				case 'c':
					printed_chars += printf("%c", va_arg(args, int));
					break;
				case 'f':
					printed_chars += printf("%f", va_arg(args, double));
					break;
<<<<<<< HEAD
				case 'b':
					printed_chars += print_binary(va_arg(args, unsigned int));
					break;
				case 'u':
					printed_chars += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					printed_chars += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					printed_chars += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					printed_chars += printf("%X", va_arg(args, unsigned int));
					break;
				default:
					printed_chars += printf
						("%%%c", *format);
=======
				default:
					printed_chars += printf("%c", *format);
>>>>>>> c489567565dffc79bde813489a5292196beff085
					break;
			}
		}
		else
		{
<<<<<<< HEAD
			printed_chars += printf("%c",
					*format);
=======
			printed_chars += printf("%c", *format);
>>>>>>> c489567565dffc79bde813489a5292196beff085
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
<<<<<<< HEAD
}
/**
 * print_binary - prints binary
 * @n: parameter
 * Return: printed characters
 */
int print_binary(unsigned int n)
{
	int printed_chars = 0;

	if (n >= 2)
	{
		printed_chars += print_binary(n / 2);
	}
	printed_chars += printf("%d", n % 2);
	return (printed_chars);
=======
>>>>>>> c489567565dffc79bde813489a5292196beff085
}
