#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CON_LOWERCASE	1
#define CON_UNSIGNED	2

/**
 * struct parameters - parameters struct
 * @par - parameters struct
 * @unsign: flag if unsigned value
 * @plus_f: on if plus_flag specified
 * @space_f: on if hashtag_flag specified
 * @hashtag_f: on if _flag specified
 * @zero_f: on if _flag specified
 * @minus_f: on if _flag specified
 * @w: field width specified
 * @p: field precision specified
 * @h_m: on if h_m is specified
 * @l_m: on if l_m is specified
 */
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_f : 1;
	unsigned int space_f : 1;
	unsigned int hashtag_f : 1;
	unsigned int zero_f : 1;
	unsigned int minus_f : 1;

	unsigned int w;
	unsigned int p;

	unsigned int h_m : 1;
	unsigned int l_m : 1;
} params_t;
/**
 * struct specifier - Struct token
 * @speci: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *speci;
	int (*f)(va_list, params_t *);
} specifier_t;
/* function prototypes in decending order */
char *con(long int b, int bs, int fs, params_t *par);
int (*gs(char *z))(va_list pr, params_t *par);
char *gw(char *z, params_t *par, va_list pr);
char *gp(char *z, params_t *par, va_list pr);
int gpf(char *z, va_list pr, params_t *par);
int _printf(const char *format, ...);
void itp(params_t *par, va_list pr);
int pst(va_list pr, params_t *par);
int pft(char *start, char *stop, char *exit);
int p_S(va_list pr, params_t *par);

int p_u(va_list pr, params_t *par);
int p_a(va_list pr, params_t *par);
int prr(va_list pr, params_t *par);
int pro(va_list pr, params_t *par);
int p_h(va_list pr, params_t *par);
int p_H(va_list pr, params_t *par);
int pb(va_list pr, params_t *par);
int po(va_list pr, params_t *par);

int pc(va_list pr, params_t *par);
int pi(va_list pr, params_t *par);
int pp(va_list pr, params_t *par);
int pnrs(char *z, params_t *par);
int pnls(char *z, params_t *par);
int gf(char *z, params_t *par);
int gm(char *z, params_t *par);
int pn(char *z, params_t *par);
int _putchar(int c);
int _puts(char *z);

int _st(char *z);
int _id(int z);


#endif
