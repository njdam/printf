#include "main.h"

/**
 * _printf - This function prints the formatted string output to stdout
 * @format: format string
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list other_args;
	int char_count = 0, i = 0, buff_len = 0;
	int flags, width, precision, size, prints;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(other_args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			/* If the character is not a format specifier, add it to the buffer */
			buffer[buff_len++] = format[i];
			/* If the buffer is full, print its contents and reset the index*/
			if (buff_len == BUFFER_SIZE)
				flush_buffer(buffer, &buff_len);
			char_count++;
		}
		else
		{/* If the character is a format specifier, process it */
			flush_buffer(buffer, &buff_len);

			/* Get the flags, width, precision, and size from the format specifier */
			flags = check_flags(format, &i);
			width = check_width(format, &i, other_args);
			precision = check_precision(format, &i, other_args);
			size = check_size(format, &i);
			i++;
			/* Handle the format specifier and get the number of characters printed */
			prints = print_handler(format, &i, other_args, buffer, flags,
					width, precision, size);
			if (prints == -1)
				return (-1);
			char_count += prints;
		}
	}
	flush_buffer(buffer, &buff_len);
	va_end(other_args);
	return (char_count);
}

/**
 * flush_buffer - This function writes buffer content to stdout and reset index
 * @buffer: The character buffer
 * @buff_len: The pointer to buffer index
 */
void flush_buffer(char buffer[], int *buff_len)
{
	/* If there are characters in the buffer, print them */
	if (*buff_len > 0)
		write(1, &buffer[0], *buff_len);
	*buff_len = 0;
}
