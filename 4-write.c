#include "main.h"

/**
 * write_char - This function is for printing characters
 *
 * @c: Is a type of a character
 * @buffer: Is an array of buffer for handling printing
 * @flags: The number of active flags
 * @width: Is the resulting width of format specification;
 * @precision: Is the resulting precision of format specification;
 * @size: Is size of format specifier;
 *
 * Return: The value equal to the number of printed characters.
 */
int write_char(char c, char buffer[], int flags, int width, int precision,
		int size)
{
	int x = 0;
	char chan;

	UNUSED(precision);
	UNUSED(size);
	if (flags & ZERO)
		chan = '0';
	buffer[x++] = c;
	buffer[x] = '\0';
	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		x = 0;
		while (x < width)
		{
			buffer[BUFFER_SIZE - x - 2] = chan;
			x++;
		}
		if (flags & MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_nsign - a function to write a signs for a number in a string;
 *
 * @is_negative: is for checking a negative number;
 * @x: is index of a buffer where to start to write arguments to be printed;
 * @buffer: is an array of buffer to handle what to be printed;
 * @flags: number of active flags;
 * @width: is the resulting width of format specification;
 * @precision: is the resulting precision of format specification;
 * @size: is size of format specifier;
 *
 * Return: all values required by write_num function.
 */
int write_nsign(int is_negative, int x, char buffer[], int flags, int width,
		int precision, int size)
{
	char pc = ' ', ext_c = 0;
	int len = BUFFER_SIZE - x - 1;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & MINUS))
		pc = '0';

	if (is_negative)
		ext_c = '-';
	else if (flags & PLUS)
		ext_c = '+';
	else if (flags & SPACE)
		ext_c = ' ';

	return (write_num(x, buffer, flags, width, precision, len, pc, ext_c));
}

/**
 * write_num - a function to write or record a number in a buffer;
 * @x: is index of a buffer where to start write a number;
 * @buffer: is an array of buffer to handle what to be printed;
 * @flags: number of active flags;
 * @width: is the resulting width of format specification;
 * @precision: is the resulting precision of format specification;
 * @len: length for a number;
 * @pc: specifies the character which is to be used for padding block;
 * @ext_c: is extra character;
 *
 * Return: resulting written number in a buffer.
 */
int write_num(int x, char buffer[], int flags, int width, int precision,
		int len, char pc, char ext_c)
{
	int z, p_start = 1;

	if (width == 0 && precision == 0 && x == BUFFER_SIZE - 2 && buffer[x] == '0')
		return (0); /* it is like printf(".0d", 0), not to print char */
	if (precision == 0 && x == BUFFER_SIZE - 2 && buffer[x] == '0')
		buffer[x] = pc = ' '; /* Padding ' ' displayed as width */
	if (precision < len && precision > 0)
		pc = ' ';
	while (precision > len)
		buffer[--x] = '0', len++;
	if (ext_c != 0)
		len++;
	if (width > len)
	{
		for (z = 1; z < width - len + 1; z++)
			buffer[z] = pc;
		buffer[z] = '\0';
		if (flags & MINUS && pc == ' ') /* assigning extra char to left */
		{
			if (ext_c)
				buffer[--x] = ext_c;
			return (write(1, &buffer[x], len) + write(1, &buffer[1], z - 1));
		}
		else if (pc == ' ' && !(flags & MINUS)) /* extra character to left */
		{
			if (ext_c)
				buffer[--x] = ext_c;
			return (write(1, &buffer[1], z - 1) + write(1, &buffer[x], len));
		}
		else if (pc == '0' && !(flags & MINUS)) /* extra character to left */
		{
			if (ext_c)
				buffer[--p_start] = ext_c;
			return (write(1, &buffer[1], p_start - 1) + write(1, &buffer[x],
						len - (1 - p_start)));
		}
	}
	if (ext_c)
		buffer[--x] = ext_c;
	return (write(1, &buffer[x], len));
}

/**
 * write_uns - This function writes unsigned number;
 *
 * @is_negative: is for checking a negative number;
 * @x: is index of a buffer where to start to write arguments to be printed;
 * @buffer: is an array of buffer to handle what to be printed;
 * @flags: number of active flags;
 * @width: is the resulting width of format specification;
 * @precision: is the resulting precision of format specification;
 * @size: is size of format specifier;
 *
 * Return: The length of a printed string.
 */
int write_uns(int is_negative, int x, char buffer[], int flags, int width,
		int precision, int size)
{
	char pc = ' ';
	int z, len = BUFFER_SIZE - x - 1;

	UNUSED(is_negative);
	UNUSED(size);

	if (x == BUFFER_SIZE - 2 && precision == 0 && buffer[x] == '0')
		return (0);/* it is like printf(".0d", 0), not to print char */

	if (precision < len && precision > 0)
		pc = ' ';

	while (precision > len)
	{
		buffer[--x] = '0';
		len++;
	}
	if (!(flags & MINUS) && (flags & ZERO))
		pc = '0';

	if (width > len)
	{
		for (z = 0; z < width - len; z++)
			buffer[z] = pc;
		buffer[z] = '\0';

		if (flags & MINUS) /* extra character to the left of buffer  pc < buffer */
			return (write(1, &buffer[x], len) + write(1, &buffer[0], z));

		else /* extra character to the left of padding, pc > buffer */
			return (write(1, &buffer[0], z) + write(1, &buffer[x], len));
	}
	return (write(1, &buffer[x], len));
}

/**
 * write_pointer - This function is for writing address stored in a pointer
 *
 * @buffer: Is an array of buffer to handle what to be printed
 * @x: Is index of a buffer where to start to write arguments to be printed
 * @len: Is the length of a number
 * @width: Is the resulting width of format specification
 * @flags: Is a number of active flags
 * @pc: Is padding character
 * @ext_c: Is extra character
 * @p_start: Is index where to start for  padding
 *
 * Return: The length of printed string
 */
int write_pointer(char buffer[], int x, int len, int flags, int width, char pc,
		char ext_c, int p_start)
{
	int z;

	if (width > len)
	{
		for (z = 3; z < width - len + 3; z++)
			buffer[z] = pc;
		buffer[z] = '\0';
		if (pc == ' ' && (flags & MINUS)) /* extra character to left buffer */
		{
			buffer[--x] = 'x';
			buffer[--x] = '0';
			if (ext_c)
				buffer[--x] = ext_c;
			return (write(1, &buffer[x], len) + write(1, &buffer[3], z - 3));
		}
		else if (pc == ' ' && !(flags & MINUS)) /* extra character to left buffer */
		{
			buffer[--x] = 'x';
			buffer[--x] = '0';
			if (ext_c)
				buffer[--x] = ext_c;
			return (write(1, &buffer[3], z - 3) + write(1, &buffer[x], len));
		}
		else if (pc == '0' && !(flags & MINUS))
			/* extra character to left padding (pc) */
		{
			if (ext_c)
				buffer[--p_start] = ext_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[p_start], z - p_start) +
					write(1, &buffer[x], len - (1 - p_start) - 2));
		}
	}
	buffer[--x] = 'x';
	buffer[--x] = '0';
	if (ext_c)
		buffer[--x] = ext_c;

	return (write(1, &buffer[x], BUFFER_SIZE - x - 1));
}
