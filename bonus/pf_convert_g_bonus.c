/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_g_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:54:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/02 05:15:23 by sshakya          ###   ########.fr       */
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

static void		pf_setend_g(char *str)
{
	int			len;
	int			n;
	int			flag;

	flag = 0;
	n = 0;
	len = pf_strlen(str);
	while (str[n] != '\0')
	{
		if (str[n] == '.')
			flag = 1;
		n++;
	}
	if (len > 2 && flag)
	{
		len--;
		while(str[len] == '0')
		{
			str[len] = '\0';
			len--;
		}
		if (str[len] == '.')
			str[len] = '\0';
	}
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

static char		*pf_convertexpg(double number, int pwidth, int precision)
{
	char		*ret;
	int			exp;

	if (precision == 1 && pwidth == -1)
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

char			*pf_convertfloatg(double number, int pwidth, int precision)
{
	char		*ret;
	int			exp;
	int			width;

	width = pwidth;
	exp = pf_expi(number);
	if ((number > 0 && number < DBL_EPSILON) || number == 0)
	{
		ret = pf_convertbase(0, "0123456798");
		return (ret);
	}
	if (number == 1)
	{
		ret = pf_convertbase(1, "0123456789");
		return (ret);
	}
	else if (exp < -4 || (exp >= pwidth && pwidth != -1) || (exp >= 5 && pwidth == -1))
		ret = pf_convertexpg(number, pwidth, precision);
	else if (exp < 0 && !(exp < -4) && pwidth != -1)
		ret = pf_convertfloat(number, width - (exp + 1), precision);
	else
	{
		if (pwidth == -1 && exp < 0)
			ret = pf_convertfloat(number, 5 - exp, precision);
		else if (pwidth == -1 && exp >= 0)
		{
			ret = pf_convertfloat(number, (6 - (exp + 1)), precision);
		}
		else
			ret = pf_convertfloat(number, pwidth - 1, precision);
	}
	pf_setend_g(ret);
	return (ret);
}
