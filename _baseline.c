#include "main.h"
/**
 * gs - finds the format of function
 * @z:  string
 * Return: new pointer
 */
int (*gs(char *z))(va_list pr, params_t *par)
{
specifier_t speci[] = {

{"d", pi},
{"i", pi},
{"s", pst},
{"r", prr},
{"b", pb},
{"S", p_S},
{"o", po},
{"R", pro},
{"x", p_h},
{"X", p_H},
{"%", pp},
{"p", p_a},
{"c", pc},
{"u", p_u},
{NULL, NULL}
};
int u;

for (u = 0; speci[u].speci; u++)
{
if (*z == speci[u].speci[0])
{
return (speci[u].f);
}
}
return (NULL);
}
/**
 * gpf - finds format function
 * @z:  string
 * @pr: pointer argument
 * @par: parameters struct
 * Return: number of byte
 */
int gpf(char *z, va_list pr, params_t *par)
{
	int (*u)(va_list, params_t *) = gs(z);

	if (u)
		return (u(pr, par));
	return (0);
}
/**
 * gf - finds flag function
 * @z:  string
 * @par: parameters struct
 *
 * Return: if flag was valid
 */
int gf(char *z, params_t *par)
{
int u = 0;

switch (*z)
{
case '-':
u = par->minus_f = 1;
break;
case ' ':
u = par->space_f = 1;
break;
case '+':
u = par->plus_f = 1;
break;
case '0':
u = par->zero_f = 1;
break;
case '#':
u = par->hashtag_f = 1;
break;
}
return (u);
}
/**
 * gm - getmodifier function
 * @z:  string
 * @par: parameters struct
 * Return: if modifier was valid
 */
int gm(char *z, params_t *par)
{
int u = 0;

switch (*z)
{
case 'h':
u = par->h_m = 1;
break;
case 'l':
u = par->l_m = 1;
break;
}
return (u);
}
/**
 * gw - gets width from format string
 * @z:  string
 * @pr: argument pointer
 * @par: parameters struct
 * Return: new pointer
 */
char *gw(char *z, params_t *par, va_list pr)
{
int u = 0;

if (*z == '*')
{
u = va_arg(pr, int);
z++;
}
else
{
while (_id(*z))
u = u * 10 + (*z++ - '0');
}
par->w = u;
return (z);
}
