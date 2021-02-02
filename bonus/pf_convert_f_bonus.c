/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_f_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/02 19:19:18 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_whole_f(uintmax_t digit, int pwidth)
{
	char		*dig;
	char		*flt;

	dig = pf_convertbase(digit, "0123456789");
	if (pwidth == 0)
		return (dig);
	flt = pf_doublezero(pwidth);
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
//	printf("exp = %d\n", exp[0]);
	deci[0] = pf_exp(deci[0]);
	deci[0] = deci[0] * pf_pow_f(10, pwidth, exp[0]);
	deci[1] = pf_roundfloat(deci[0], &i);
//	printf("d0 = %.10f | d1 = %.10f \n", deci[0], deci[1]);
//	printf("%% = %lu\n", (uintmax_t)deci[1] / (uintmax_t)deci[0]);
	exp[1] = pf_expi(deci[0]);
	exp[2] = pf_expi(deci[1]);
//	printf("exp1 = %d\n", exp[1]);
//	printf("exp2 = %d\n", exp[2]);
	ret = pf_convertbase((uintmax_t)deci[1], "0123456789");
	if (exp[0] != -1)
		ret = pf_addpow(ret, exp[0] + i, pwidth);
	if ((uintmax_t)deci[1] % (uintmax_t)deci[0] == 1 && exp[0] == -1 && exp[1] != exp[2])
	{
		ret = pf_doublezero(pwidth);
		*n = 1;
	}
	return (ret);
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
