#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) ((void)(x))

/* SIZES TO BE USED */
#define SHORT 1
#define LONG 2

/* FLAGS TO BE USED */
#define SPACE 1
#define HASH 2
#define MINUS 4
#define PLUS 8
#define ZERO 16

/**
 * struct format - structure operator;
 *
 * @format: associated format;
 * @func: a pointer to a function;
 */
typedef struct format
{
	char format;
	int (*func)(va_list, char[], int, int, int, int);
}
/* a pointer to pointed to a function */
fmt_func;

/* Functions for making Printf like */
int print_handler(const char *format, int *x, va_list, char buffer[],
		int flags, int width, int width, int precision, int size);

/** Functions for making or satisfying Write function **/
int write_char(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_num(int x, char buffer[], int flags, int width,
		int precision, int size);
int write_nsign(int is_negative, int x, char buffer[],
		int flags, int width, int precision, int size);
int write_uns(int is_negative, int x, char buffer[], int flags,
		int width, int precision, int size);
int write_pointer(char buffer[], int x, int len, int width,
		int flags, char pc, char ext_c, int p_start);

/*** Functions for Other Specifier Handler ***/
int check_flags(const char *format, int *x);
int check_width(const char *format, int *x, va_list arg);
int check_precision(const char *format, int *x, va_list arg);
int check_size(const char *format, int *x);

/**** Functions for UTILS ****/
int _isdigit(char c);
int _isprintable(char c);
long int conv_size_num(long int num, int size);
long int conv_size_uns(unsigned long int num, int size);
int append_hexacode(char ascii_code, char buffer[], int x);

/******* Functions for Project Questions *******/
int _printf(const char *format, ...);
void flush_buffer(char buffer[], int *buff_len);

#endif /* MAIN_H */
