#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_strings - formats argument to string
 * @char_printed_count: number of characters printed to the output stream
 * @args: arguments to be formatted
 *
 * Return: returns char_printed-count
 */

int handle_strings(int char_printed_count, va_list args)
{
    char *s = va_arg(args, char *);
    if (s == NULL)
        s = "(null)";
    char *ptr = s;
    while (*ptr)
    {
        int res = write(1, ptr, 1);
        if (res < 0)
            return char_printed_count;
        char_printed_count++;
        ptr++;
    }
    return char_printed_count;
}

/**
 * handle_character - formats a character
 * @char_printed_count: number of characters printed to the stdout
 * @args: list of arguments to be formatted
 *
 * Return: returns char_printed_count
 */

int handle_character(int char_printed_count, va_list args)
{
    char c = va_arg(args, int);
    int res = write(1, &c, 1);
    if (res < 0)
        return char_printed_count;
    return char_printed_count + 1;
}
