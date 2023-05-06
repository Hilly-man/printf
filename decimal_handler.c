#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_number - prints a number using _putchar
 * @n: the number to print
 *
 * Return: the number of digits printed
 */
int _print_number(int n)
{
	unsigned int abs_n = n;
	int digit_count = 1;

	if (n < 0)
	{
		_putchar('-');
		abs_n = -n;
	}

	while (abs_n / 10 > 0)
	{
		digit_count++;
		abs_n /= 10;
	}

	abs_n = (n < 0) ? -n : n;
	while (digit_count > 0)
	{
		_putchar('0' + (abs_n / digit_count));
		abs_n %= digit_count;
		digit_count /= 10;
	}

	return ((n < 0) ? digit_count + 1 : digit_count);
}

/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 * @...: optional arguments
 *
 * Return: the number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'd':
			case 'i':
			{
				int n = va_arg(args, int);

				len += _print_number(n);
				break;
			}
			default:
				_putchar('%');
				len++;
				if (*format != '\0')
				{
					_putchar(*format);
					len++;
				}
				break;
			}
		} else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}

	va_end(args);
	return (len);
}
