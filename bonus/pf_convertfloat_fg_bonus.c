/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convertfloat_fg_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:45:49 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/09 02:56:38 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_whole_f(double number, int pwidth)
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
	if (pwidth == 0 || pwidth == -1)
		return (dig);
	flt = pf_doublezero(pwidth, flt);
	flt = pf_joinfloat(dig, flt);
	return (flt);
}

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

char			*pf_convertfloat_fg(double number, int pwidth, int precision)
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
		return (pf_whole_f(number, pwidth));
	if (precision == 1 && (pwidth == -1 || pwidth == 0))
		return (pf_whole_f(number, 0));
	flt = pf_convertdecimal(number, pwidth, &n);
	if (n == 1)
		digit = digit + 1;
	dig = pf_convertbase(digit, "0123456789");
	flt = pf_joinfloat(dig, flt);
	return (flt);
}
