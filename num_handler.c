#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"


int handle_integer(int char_printed_count, va_list args);
int handle_unsigned_decimal(int char_printed_count, va_list args);
int handle_hex(int char_printed_count, va_list args, char format);


typedef struct 
{
    char format;
    int (*handler)(int, va_list);
} conversion;


static conversion conversions[] = {
    {'d', handle_integer},
    {'i', handle_integer},
    {'c', handle_character},
    {'s', handle_string},
    {'b', handle_binary},
    {'u', handle_unsigned_decimal},
    {'x', handle_hex},
    {'X', handle_hex},
    {'o', handle_octal},
    {'S', handle_string},
    {'p', handle_address},
    {'\0', NULL}
};


int (*get_handler(char format))(int, va_list)
{
    for (int i = 0; conversions[i].format != '\0'; i++) {
        if (format == conversions[i].format) {
            return conversions[i].handler;
        }
    }
    return NULL;
}


int handle_integer(int char_printed_count, va_list args)
{
    char buf[32];
    int num, len, write_res;

    num = va_arg(args, int);
    len = snprintf(buf, sizeof(buf), "%d", num);
    if (len < 0) {
        return char_printed_count;
    }
    write_res = write(1, buf, len);
    if (write_res < 0) {
        return char_printed_count;
    }
    char_printed_count += write_res;
    return char_printed_count;

int handle_unsigned_decimal(int char_printed_count, va_list args)
{
    unsigned int num;
    int result;
    char buffer[20];

    num = va_arg(args, unsigned int);
    result = snprintf(buffer, sizeof(buffer), "%u", num);
    if (result < 0) {
        return char_printed_count;
    }
    write(1, buffer, result);
    char_printed_count += result;
    return char_printed_count;
}


int handle_hex(int char_printed_count, va_list args, char format)
{
    int count, num;
    char fmt_str[3];

    fmt_str[0] = '%';
    fmt_str[1] = format;
    fmt_str[2] = '\0';

    num = va_arg(args, unsigned int);
    count = to_hex_helper(num, fmt_str);
    if (count == 0) {
        return char_printed_count;
    }
    char_printed_count += count;
    return char_printed_count;
}
