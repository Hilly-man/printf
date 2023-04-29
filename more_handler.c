#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * to_octal_helper - helps in formatting to base 8
 * @num: the number to be formatted
 *
 * Return: returns the number of characters printed
 */

int to_octal_helper(unsigned int num)
{
	char buffer[12];
	int print_count;

	print_count = snprintf(buffer, 12, "%o", num);
	if (print_count < 0)
		return 0;
	write(1, buffer, print_count);
	return print_count;
}

/**
 * handle_octal - formats a number to octal (base 8)
 * @char_printed_count: number of characters printed to the stdout
 * @args: list of arguments to be formatted
 *
 * Return: returns char_printed_count
 */

int handle_octal(int char_printed_count, va_list args)
{
	unsigned int num;
	int count;

	num = va_arg(args, unsigned int);
	count = to_octal_helper(num);
	if (count == 0)
		return char_printed_count;
	return char_printed_count + count;
}

/**
 * handle_String - formats a custom conversion in printf
 * @char_printed_count: number of the characters printed to the stdout
 * @args: list of arguments to be formatted
 *
 * Return: returns char_printed_count
 */

int handle_String(int char_printed_count, va_list args)
{
	char *str;
	int ascii_val, result;
	char buffer[2];

	str = va_arg(args, char *);
	while (*str != '\0')
	{
		ascii_val = get_ascii(*str);
		if ((ascii_val > 0 && ascii_val < 32) || ascii_val >= 127)
		{
			write(1, "\\x", 2);
			char_printed_count += 2;
			result = snprintf(buffer, 2, "%02X", ascii_val);
			if (result < 0)
				return char_printed_count;
			write(1, buffer, result);
			char_printed_count += result;
		}
		else
		{
			write(1, str, 1);
			char_printed_count++;
		}
		str++;
	}
	return char_printed_count;
}

/**
 * handle_address - formats address of a pointer
 * @char_printed_count: number of character printed to the output
 * @args: list of argumnets to be fomatted
 *
 * Return: return char_printed_count
 */

int handle_address(int char_printed_count, va_list args)
{
	char buffer[32];
	int result, buf_len;
	void *ptr;

	ptr = va_arg(args, void *);
	result = snprintf(buffer, 32, "%p", ptr);
	if (result < 0)
		return char_printed_count;
	buf_len = strlen(buffer);
	write(1, buffer, buf_len);
	return char_printed_count + buf_len;
}
