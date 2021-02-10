/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_e_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/10 03:08:05 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

double			pf_roundfloat(double decimal, int *i)
{
	int			exp;
	int			round;
	double		temp;

	exp = pf_expi(decimal);
	temp = decimal + 0.5;
	round = pf_expi(temp);
	*i = round - exp;
	return (temp);
}

char			*pf_convertdecimal_e(double number, int pwidth, int *n)
{
	char		*ret;
	double		d[2];
	uintmax_t	digit;
	int			e[2];
	int			i;

	i = 0;
	e[0] = pf_expi(number);
	number = pf_exp(number);
	digit = (uintmax_t)number;
	d[0] = number - (double)digit;
	d[0] = d[0] * pf_pow_e(10, pwidth, e[0]);
	e[1] = pf_expi(d[0]);
	d[1] = pf_roundfloat(d[0], &i);
	e[0] = pf_expi(d[1]);
	ret = pf_convertbase((uintmax_t)d[1], "0123456789");
	if (e[1] != -1)
		ret = pf_addpow(ret, e[1] + i, pwidth);
	if ((uintmax_t)d[1] == 0 && (uintmax_t)d[0] == 0)
		return (pf_doublezero(pwidth, ret));
	if (e[0] != e[1] && (uintmax_t)d[1] % (uintmax_t)d[0] == 1)
	{
		ret = pf_doublezero(pwidth, ret);
		*n = 1;
	}
	return (ret);
}

static void		pf_set_zero_e(char **flt, char **dig, int *exp, int pwidth)
{
	*flt = pf_doublezero(pwidth, *flt);
	*dig = pf_convertbase(0, "0123456789");
	*exp = 0;
}

static void		pf_set_digit_e(double number, char **flt, int *exp,
		t_flags flags)
{
	double		deci;
	uintmax_t	digit;

	*exp = pf_expi(number);
	number = pf_exp(number);
	digit = (uintmax_t)number;
	deci = number - (double)digit;
	if (deci > 0.5)
		digit = digit + 1;
	*flt = pf_convertbase(digit, "0123456789");
	if (flags.hash == 1)
		*flt = pf_joinfloat(*flt, NULL);
}

char			*pf_convertexp(double number, t_flags flags)
{
	char		*dig;
	char		*flt;
	uintmax_t	digit;
	int			exp;
	int			n;

	n = 0;
	if (number > 0 && number < DBL_EPSILON)
		pf_set_zero_e(&flt, &dig, &exp, flags.pwidth);
	else if (flags.precision == 1 && (flags.pwidth == -1 || flags.pwidth == 0))
		pf_set_digit_e(number, &flt, &exp, flags);
	else
	{
		exp = pf_expi(number);
		flt = pf_convertdecimal_e(number, flags.pwidth, &n);
		number = pf_exp(number);
		digit = (uintmax_t)number;
		if (n == 1)
			digit = digit + 1;
		dig = pf_convertbase(digit, "0123456789");
		flt = pf_joinfloat(dig, flt);
	}
	flt = pf_addexp(flt, exp);
	return (flt);
}
