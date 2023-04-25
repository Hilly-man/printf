#include <stdarg.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - function that prints out accoring to a format
 * @buffer: Array of characters
 * @buff_ind: index at which to add next char (length)
 * Return: number of characters printed excluding null byte
 */
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
int handle_print(const char *format, int *index,
		va_list args, char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	int num_chars_printed = 0;
	int buffer_index = 0;
	char buffer[BUFFER_SIZE];
	va_list args;

	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
			{
				print_buffer(buffer, &buffer_index);
			}
			num_chars_printed++;
		}
		else
		{
			int chars_printed = handle_print(format, &i, args, buffer, &buffer_index);

			if (chars_printed == -1)
			{
				va_end(args);
				return (-1);
			}
			num_chars_printed += chars_printed;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(args);
	return (num_chars_printed);
}

int handle_print(const char *format, int *index,
		va_list args, char buffer[], int *buff_ind)
{
	int chars_printed = 0;
	char *str;

	switch (format[*index])
	{
		case 'c':
			{
				char c = va_arg(args, int);

				buffer[(*buff_ind)++] = c;
				break;
			}
		case 's':
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				chars_printed = _strncpy(buffer, str, BUFF_SIZE, buff_ind);
				break;
			}
		case '%':
			{
				buffer[(*buff_ind)++] = '%';
				break;
			}
			return (chars_printed);
	}
}
/**
 * print_buffer - prints contents of buffer if it exists
 * @buffer: Array of characters
 * @buff_ind: index at which to add next char (length)
 */
void print_buffer(char buffer[], int *buff_ind)
{
	write(STDOUT_FILENO, buffer, *buff_ind);
	*buff_ind = 0;
}
