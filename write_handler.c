#include "main.h"

/**
 * write_char - a function to print characters;
 * @c: is a type of a character;
 * @buffer: an array of buffer to handle prints;
 * @flags: number of active flags;
 * @width: is the resulting width of format specification;
 * @precision: is the resulting precision of format specification;
 * @size: is size of format specifier;
 *
 * Return: value equal to the number of printed characters.
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
 * @precision: is the resulting precision of format specification;
 * @len: length for a number;
 * @pc: specifies the character which is to be used for padding block;
 * @ext_c: is extra character;
 *
 * Return: resulting written number in a buffer.
 */
int write_num(int x, char buffer[], int flags, int precision, int len, char pc,
		char ext_c)
{
	int z, p_start = 1;
}

/**
 * write_uns - is a function to write unsigned number;
 * @is_negative: is for checking a negative number;
 * @x: is index of a buffer where to start to write arguments to be printed;
 * @buffer: is an array of buffer to handle what to be printed;
 * @flags: number of active flags;
 * @width: is the resulting width of format specification;
 * @precision: is the resulting precision of format specification;
 * @size: is size of format specifier;
 *
 * Return: number written characters.
 */
int write_uns(int is_negative, int x, char buffer[], int flags, int width,
		int precision, int size)
{
	char pc = ' ';
	int z, len = BUFFER_SIZE - x - 1;

	UNUSED(is_negative);
	UNUSED(size);
}

/**
 * write_pointer - a function to write address of where pointer point to;
 * @buffer: is an array of buffer to handle what to be printed;
 * @x: is index of a buffer where to start to write arguments to be printed;
 * @len: is the length of a number;
 * @width: is the resulting width of format specification;
 * @flags: number of active flags;
 * @pc:is padding character;
 * @ext_c:i s extra character;
 * @p_start: is index where to start for  padding;
 *
 * Return: number of characters written.
 */
int write_pointer(char buffer[], int x, int len, int width, int flags, char pc,
		char ext_c, char p_start)
{
	int x;

	if (width > len)
	{
	}
}
