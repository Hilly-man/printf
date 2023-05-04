#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: format string
 *   - %c: prints a single character
 *   - %s: prints a null-terminated string
 *   - %%: prints a single '%' character
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{ format++;
			switch (*format)
			{
			case 'c':{
					char c = va_arg(args, int);

						len += write(1, &c, 1);
							break;
				}
			case 's':{
					char *str = va_arg(args, char *);

					if (str == NULL)
						str = "(null)";
					len += write(1, str, strlen(str));
					break;
				}
			case '%':{
					len += write(1, "%", 1);
					break;
				}
			default:{
					break;
				}
			}
		} else
		{
			len += write(1, for, 1);
		} format++;
	} va_end(args);
	return (len);
}
