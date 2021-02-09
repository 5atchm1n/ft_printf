/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convertfloat_eg_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:45:49 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/09 02:57:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_set_digit_g(double number)
{
	int			exp;
	char		*ret;

	ret = pf_convertbase((uintmax_t)number, "0123456789");
	exp = pf_expi(number);
	ret = pf_addexp(ret, exp);
	return (ret);
}

static char		*pf_convertexp_g(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	uintmax_t	digit;
	int			exp;
	int			n;

	n = 0;
	exp = pf_expi(number);
	flt = pf_convertdecimal_e(number, pwidth, &n);
	number = pf_exp(number);
	digit = (uintmax_t)number;
	if (n == 1)
		digit = digit + 1;
	dig = pf_convertbase(digit, "0123456789");
	flt = pf_joinfloat(dig, flt);
	pf_setend_g(flt);
	flt = pf_addexp(flt, exp);
	return (flt);
}

char			*pf_convertexpg(double number, int pwidth, int precision)
{
	char		*ret;
	int			exp;

	if (precision == 1 && (pwidth == -1 || pwidth == 0))
	{
		ret = pf_set_digit_g(number);
		return (ret);
	}
	if (pwidth == -1)
		pwidth = 5;
	exp = pf_expi(number);
	ret = pf_convertexp_g(number, pwidth);
	return (ret);
}
