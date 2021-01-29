/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/29 01:19:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_convertexpg(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	double		deci;
	intmax_t	digit;
	int			exp;

	exp = pf_expi(number);
	number = pf_exp(number);
	digit = (uintmax_t)number;
	deci = number - (double)digit;
	dig = pf_convertbase(digit, "0123456789");
	deci = deci * pf_pow_g(10, pwidth, exp);
	flt = pf_convertbase((uintmax_t)deci, "0123456789");
	flt = pf_joinfloat(dig, flt);
	flt = pf_addexp(flt, exp);
	return (flt);
}

static void		pf_set_zero_e(char **flt, char **dig, int *exp, int pwidth)
{
	*flt = pf_doublezero(pwidth);
	*dig = pf_convertbase(0, "0123456789");
	*exp = 0;
}

char			*pf_convertexp(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	uintmax_t	digit;
	int			exp;
	int			n;

	n = 0;
	if (number > 0 && number < DBL_EPSILON)
		pf_set_zero_e(&flt, &dig, &exp, pwidth);
	else
	{
		exp = pf_expi(number);
		flt = pf_convertdecimal_e(number, pwidth, &n);
		number = pf_exp(number);
		digit = (uintmax_t)number;
		if (n == 1)
			digit = digit + 1;
		dig = pf_convertbase(digit, "0123456789");
	}
	flt = pf_joinfloat(dig, flt);
	flt = pf_addexp(flt, exp);
	return (flt);
}

static char		*pf_whole_f(uintmax_t digit, int pwidth)
{
	char		*dig;
	char		*flt;

	dig = pf_convertbase(digit, "012345679");
	if (pwidth == 0)
		return (dig);
	flt = pf_doublezero(pwidth);
	flt = pf_joinfloat(dig, flt);
	return (flt);
}

char			*pf_convertfloat(double number, int pwidth, int precision)
{
	char		*dig;
	char		*flt;
	uintmax_t	digit;
	double		deci;
	int			n;

	n = 0;
	digit = (uintmax_t)number;
	deci = number - (double)digit;
	if ((number > 0 && number < DBL_EPSILON) || deci < DBL_EPSILON)
		return (pf_whole_f(digit, pwidth));
	if (precision == 1 && pwidth == -1)
		return (pf_whole_f(digit, 0));
	flt = pf_convertdecimal(number, pwidth, &n);
	if (n == 1)
		digit = digit + 1;
	dig = pf_convertbase(digit, "0123456789");
	flt = pf_joinfloat(dig, flt);
	return (flt);
}

char			*pf_convertfloatg(double number, int pwidth, int precision)
{
	char		*ret;
	int			exp;
	int			width;

	width = pwidth;
	exp = pf_expi(number);
	if (number > 0 && number < DBL_EPSILON)
	{
		ret = pf_convertbase(0, "0123456798");
		return (ret);
	}
	if (number == 1)
	{
		ret = pf_convertbase(1, "0123456789");
		return (ret);
	}
	else if (exp < -4 || (exp >= pwidth && pwidth != -1))
		ret = pf_convertexpg(number, pwidth);
	else if (exp < 0 && !(exp < -4) && pwidth != -1)
		ret = pf_convertfloat(number, width - (exp + 1), precision);
	else
	{
		if (pwidth == -1)
			ret = pf_convertfloat(number, 5 - exp, precision);
		else
			ret = pf_convertfloat(number, pwidth - 1, precision);
	}
	return (ret);
}
