/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/27 21:55:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		pf_setendg(char *str)
{
	int			i;
	int			j;
	int			k;
	int			len;

	i = 0;
	len = pf_strlen(str);
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			j = i;
			k = i;
			while (str[j] != '\0')
			{
				if (str[j] == '0')
					j++;
				if (str[j] != '0')
				{
					i = j;
					break ;
				}
			}
		}
		i++;
	}
	if (j == len)
		str[k] = '\0';
}

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
	pf_setendg(flt);
	flt = pf_joinfloat(dig, flt);
	flt = pf_addexp(flt, exp);
	return (flt);
}

char			*pf_convertexp(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	intmax_t	digit;
	int			exp;
	int			n;

	n = 0;
	if (number > 0 && number < DBL_EPSILON)
	{
		flt = pf_doublezero(pwidth);
		dig = pf_convertbase(0, "0123456789");
		exp = 0;
	}
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

char			*pf_convertfloat(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	intmax_t	digit;
	double		deci;
	int			n;

	n = 0;
	digit = (uintmax_t)number;
	deci = number - (double)digit;
	if ((number > 0 && number < DBL_EPSILON) || deci < DBL_EPSILON)
	{
		dig = pf_convertbase(digit, "0123456789");
		if (pwidth == 0)
			return (dig);
		flt = pf_doublezero(pwidth);
		flt = pf_joinfloat(dig, flt);
		return (flt);
	}
	flt = pf_convertdecimal(number, pwidth, &n);
	if (n == 1)
		digit = digit + 1;
	dig = pf_convertbase(digit, "0123456789");
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
		ret = pf_convertfloat(number, width - (exp + 1));
	else
	{
		if (pwidth == -1)
			ret = pf_convertfloat(number, 5 - exp);
		else
			ret = pf_convertfloat(number, pwidth - 1);
	}
	return (ret);
}
