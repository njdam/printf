#include "main.h"

/**
 * _isprintable - checks if a character is printable;
 * @c: a character to be checked;
 *
 * Return: value 1 (true) if printable otherwise 0 (false).
 */
int _isprintable(char c)
{
	if (c > 31 && c < 127)
		return (1);

	return (0);
}

/**
 * _isdigit - function to check if a character is a digit;
 * @c: is a character to be checked;
 *
 * Return: value 1 (true) if is a digit otherwise 0 (false).
 */
int _isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);

	return (0);
}

/**
 * conv_size_num - function to cast a value to its specied size;
 * @num: number to be used;
 * @size: is number related to it's type to be casted;
 *
 * Return: resulting casted value of a number.
 */
long int conv_size_num(long int num, int size)
{
	if (size == LONG)
		return (num);

	else if (size == SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_size_uns - a function to cast a value to it's corresponding size;
 * @num: number to be casted;
 * @size: is number related to it's type to be casted on;
 *
 * Return: resulting casted value of a number.
 */
long int conv_size_uns(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);

	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * append_hexacode - a function to append asccii code in hexadecimal to beffer;
 * @buffer: is an array of a characters to store as RAM;
 * @x: is index where to start appending;
 * @ascii_code: is the ASCII CODE;
 *
 * Return: always return 3 for success.
 */
int append_hexacode(char ascii_code, char buffer[], int x)
{
	char ref_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	/* Hexadecimal formated as always 2 digits long */
	buffer[x++] = ref_to[ascii_code / 16];
	buffer[x++] = ref_to[ascii_code % 16];

	return (3);
}
