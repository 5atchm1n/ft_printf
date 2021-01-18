/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/18 22:45:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*pf_convertexp(double number, int pwidth)
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
	deci = deci * pf_pow(10, pwidth);
	flt = pf_convertbase((uintmax_t)deci, "0123456789");
	flt = pf_joinfloat(dig, flt);
	flt = pf_addexp(flt, exp);
	return (flt);
}

char			*pf_convertfloat(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	double		deci;
	intmax_t	digit;
	int			exp;

	exp = pf_expi(number);
	digit = (uintmax_t)number;
	deci = number - (double)digit;
	dig = pf_convertbase(digit, "0123456789");
	deci = pf_exp(deci);
	deci = deci * pf_pow(10, pwidth + exp);
	flt = pf_convertbase((uintmax_t)deci, "0123456789");
	flt = pf_addpow(flt, exp, pwidth);
	flt = pf_joinfloat(dig, flt);
	return (flt);
}
char			*pf_convertfloatg(double number, int pwidth)
{
	char		*ret;
	int			exp;
	int			width;

	width = pwidth;
	exp = pf_expi(number);
	if (number == 1)
	{
		ret = pf_convertbase(1, "0123456789");
		return(ret);
	}
	else if (exp < -4 || exp >= pwidth)
		ret = pf_convertexp(number,pwidth);
	else 
		ret = pf_convertfloat(number, width);
	return (ret);
}
