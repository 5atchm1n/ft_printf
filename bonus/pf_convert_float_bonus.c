/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/27 18:40:07 by sshakya          ###   ########.fr       */
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
	double		deci;
	intmax_t	digit;
	int			exp;
	int			exp2;

	if (number > 0 && number < DBL_EPSILON)
	{
		flt = pf_doublezero(pwidth);
		dig = pf_convertbase(0, "0123456789");
		exp = 0;
	}
	else
	{
		exp = pf_expi(number);
		number = pf_exp(number);
//		printf("exp = %i\n", exp);
		digit = (uintmax_t)number;
		deci = number - (double)digit;
		exp2 = pf_expi(deci);
//		printf("exp2 = %i\n", exp2);
		dig = pf_convertbase(digit, "0123456789");
		deci = deci * pf_pow_e(10, pwidth, exp) + 0.5;
//		printf("fl = %.2f\n", deci);
		flt = pf_convertbase((uintmax_t)deci, "0123456789");
		flt = pf_addpow(flt, exp2, pwidth);
	}
	flt = pf_joinfloat(dig, flt);
	flt = pf_addexp(flt, exp);
	return (flt);
}

static double	pf_roundfloat(double decimal, int *i)
{
	int			exp;
	int			round;
	double		temp;

	exp = pf_expi(decimal);
//	printf("\n exp-r1 = %d\n", exp);
	temp = decimal + 0.5;
	round = pf_expi(temp);
//	printf("\n exp-r2 = %d\n", round);
	*i = round - exp;
	return (temp);
}

static char		*pf_convertdecimal(double number, int pwidth, int *n)
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
//	printf("\n exp-main = %d\n", exp);
	deci[0] = pf_exp(deci[0]);
	deci[0] = deci[0] * pf_pow_f(10, pwidth, exp);
	deci[1] = pf_roundfloat(deci[0], &i);
	ret = pf_convertbase((uintmax_t)deci[1], "0123456789");
//	printf("\n i = %d\n", i);
	if (exp != -1)
		ret = pf_addpow(ret, exp + i, pwidth);
	if ((uintmax_t)deci[1] % (uintmax_t)deci[0] == 1 && exp == -1)
	{
		ret = pf_doublezero(pwidth);
		*n = 1;
	}
//	printf("ret = %s\n", ret);
	return (ret);
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
