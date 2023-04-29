#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * %p_function - selects the correct conversion to perform
 * @format: format of the conversion
 *
 * Return: returns function pointer to the handler of the conversion
 */

int (*get_handler(char format))(int, va_list)
{
	typedef struct {
		char format;
		int (*handler)(int, va_list);
	} conversion;

	conversion conversions[] = {
		{'d', handle_integers},
		{'i', handle_integers},
		{'c', handle_character},
		{'s', handle_strings},
		{'b', handle_binary},
		{'u', handle_unsigned_decimal},
		{'x', handle_hex_lower},
		{'X', handle_hex_upper},
		{'o', handle_octal},
		{'S', handle_String},
		{'p', handle_address},
		{'\0', NULL}
	};

	for (int i = 0; conversions[i].format != '\0'; i++)
	{
		if (format == conversions[i].format)
		{
			return conversions[i].handler;
		}
	}

	return NULL;
}
