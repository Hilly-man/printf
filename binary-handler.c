#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * binary-handler - function to convert unsigned to binary
 * @num: number to be converted
 *
 * Return: returns number of bits printed
 */

int binary_helper(unsigned int num)
{
	char c[33];
	int bits_printed = 0, res;

	if (num > 1)
	{
		bits_printed += binary_helper(num / 2);
	}
	sprintf(c, "%u", num % 2);
	res = write(STDOUT_FILENO, c, 1);
	if (res < 0)
		return (0);
	bits_printed++;
	return (bits_printed);
}


/**
 * handle_binary - converts int to binary
 * @count:  characters to be printed to the output stream
 * @args: the argu to be formatted
 *
 * Return: returns the char_printed_count
 */

int handle_binary(int count, va_list args)
{
	unsigned long int num;
	int res;

	num = va_arg(args, unsigned long int);
	res = binary_helper(num);
	count += res;
	return (count);
}
