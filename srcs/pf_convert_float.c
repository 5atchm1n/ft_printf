/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/17 06:44:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*pf_convertexp(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	char		*ret;
	double		deci;
	intmax_t	digit;
	int			i;
	int			exp;

	exp = 0;
	number = pf_exp(number, &exp);
	digit = (uintmax_t)number;
	deci = number - (double)digit;
	dig = pf_convertbase(digit, "0123456789");
	i = pf_strlen(dig);
	deci = deci * pf_pow(10, pwidth);
	flt = pf_convertbase((uintmax_t)deci, "0123456789");
	ret = pf_join(dig, flt);
	ret = pf_addexp(ret, exp);
	return (ret);
}

char			*pf_convertfloat(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	char		*ret;
	double		deci;
	intmax_t	digit;

	digit = (uintmax_t)number;
	deci = number - (double)digit;
	dig = pf_convertbase(digit, "0123456789");
	deci = deci * pf_pow(10, pwidth);
	flt = pf_convertbase((uintmax_t)deci, "0123456789");
	ret = pf_join(dig, flt);
	return (ret);
}
