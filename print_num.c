#include "main.h"

/**
 * itp - clears struct fields and reset buf
 * @pr: argument pointer
 * @par: parameters struct
 *
 * Return: void
 */
void itp(params_t *par, va_list pr)
{
par->w = 0;
par->p = UINT_MAX;
par->hashtag_f = 0;
par->zero_f = 0;
par->unsign = 0;
par->plus_f = 0;
par->minus_f = 0;
par->space_f = 0;
par->h_m = 0;
par->l_m = 0;
(void)pr;
}

