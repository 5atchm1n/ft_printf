/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_f_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/09 01:19:09 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_convertdecimal(double number, int pwidth, int *n)
{
	char		*ret;
	double		deci[2];
	uintmax_t	digit;
	int			exp[3];
	int			i;

	i = 0;
	digit = (uintmax_t)number;
	deci[0] = number - (double)digit;
	exp[0] = pf_expi(deci[0]);
	deci[0] = pf_exp(deci[0]);
	deci[0] = deci[0] * pf_pow_f(10, pwidth, exp[0]);
	deci[1] = pf_roundfloat(deci[0], &i);
	exp[1] = pf_expi(deci[0]);
	exp[2] = pf_expi(deci[1]);
	ret = pf_convertbase((uintmax_t)deci[1], "0123456789");
	if (exp[0] != -1)
		ret = pf_addpow(ret, exp[0] + i, pwidth);
	if (exp[1] != exp[2] && exp[0] == -1)
	{
		ret = pf_doublezero(pwidth, ret);
		*n = 1;
	}
	return (ret);
}

static char		*pf_whole_f(double number, t_flags f)
{
	char		*dig;
	char		*flt;
	double		deci;
	uintmax_t	digit;

	flt = NULL;
	digit = (uintmax_t)number;
	deci = number - (double)digit;
	if (deci > 0.5)
		digit = digit + 1;
	dig = pf_convertbase(digit, "0123456789");
	if ((f.pwidth == 0 || (f.pwidth == -1 && f.precision == 1)) && f.hash != 1)
		return (dig);
	if (f.hash == 0)
		flt = pf_doublezero(f.pwidth, flt);
	if (f.hash == 1 && f.precision == 1 && f.pwidth != -1)
		flt = pf_doublezero(f.pwidth, flt);
	flt = pf_joinfloat(dig, flt);
	return (flt);
}

char			*pf_convertfloat(double number, t_flags f)
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
		return (pf_whole_f(number, f));
	if (f.precision == 1 && (f.pwidth == -1 || f.pwidth == 0))
		return (pf_whole_f(number, f));
	flt = pf_convertdecimal(number, f.pwidth, &n);
	if (n == 1)
		digit = digit + 1;
	dig = pf_convertbase(digit, "0123456789");
	flt = pf_joinfloat(dig, flt);
	return (flt);
}
