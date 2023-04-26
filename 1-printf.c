#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - my customized printf file
 * @format: filled out properly later
 */
int _printf(const char *format, ...) {
    va_list args;
    int printed_chars = 0;
    va_start(args, format);
    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd':
                    printed_chars += printf("%d", va_arg(args, int));
                    break;
                case 's':
                    printed_chars += printf("%s", va_arg(args, char *));
                    break;
                case 'c':
                    printed_chars += printf("%c", va_arg(args, int));
                    break;
                case 'f':
                    printed_chars += printf("%f", va_arg(args, double));
                    break;
                default:
                    printed_chars += printf("%c", *format);
                    break;
            }
        } else {
            printed_chars += printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    return printed_chars;
}
