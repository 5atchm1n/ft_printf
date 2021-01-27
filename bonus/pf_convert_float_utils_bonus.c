/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/27 21:57:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*pf_convertdecimal(double number, int pwidth, int *n)
{
	char		*ret;
	double		deci[2];
	intmax_t	digit;
	int			exp;
	int			i;

	i = 0;
	digit = (uintmax_t)number;
	deci[0] = number - (double)digit;
	exp = pf_expi(deci[0]);
	deci[0] = pf_exp(deci[0]);
	deci[0] = deci[0] * pf_pow_f(10, pwidth, exp);
	deci[1] = pf_roundfloat(deci[0], &i);
	ret = pf_convertbase((uintmax_t)deci[1], "0123456789");
	if (exp != -1)
		ret = pf_addpow(ret, exp + i, pwidth);
	if ((uintmax_t)deci[1] % (uintmax_t)deci[0] == 1 && exp == -1)
	{
		ret = pf_doublezero(pwidth);
		*n = 1;
	}
	return (ret);
}

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
	double		deci[2];
	intmax_t	digit;
	int			exp[2];
	int			i;

	i = 0;
	exp[0] = pf_expi(number);
	number = pf_exp(number);
	digit = (uintmax_t)number;
	deci[0] = number - (double)digit;
	exp[1] = pf_expi(deci[0]);
	deci[0] = deci[0] * pf_pow_e(10, pwidth, exp[0]);
	deci[1] = pf_roundfloat(deci[0], &i);
	ret = pf_convertbase((uintmax_t)deci[1], "0123456789");
	if (exp[1] != -1)
		ret = pf_addpow(ret, exp[1] + i, pwidth);
	if ((uintmax_t)deci[1] == 0 && (uintmax_t)deci[0] == 0)
		return (pf_doublezero(pwidth));
	else if ((uintmax_t)deci[1] % (uintmax_t)deci[0] == 1 &&
			exp[0] == 0 && exp[1] == -1)
	{
		ret = pf_doublezero(pwidth);
		*n = 1;
	}
	return (ret);
}
