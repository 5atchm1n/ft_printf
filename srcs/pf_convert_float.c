/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/19 01:09:28 by sshakya          ###   ########.fr       */
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
	deci = deci * pf_pow(10, pwidth);
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
		return (ret);
	}
	else if (exp < -4 || exp >= pwidth)
		ret = pf_convertexpg(number, (pwidth - exp + 1));
	else
		ret = pf_convertfloat(number, width - (exp + 1));
	return (ret);
}
