/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:34:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/10 03:02:51 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_isneg(int *exp)
{
	int		neg;

	neg = 0;
	if (*exp < 0)
	{
		*exp = *exp * -1;
		neg = 1;
	}
	return (neg);
}

double		pf_pow_f(double pow, int pwidth, int exp)
{
	double	ret;
	int		def;

	ret = 1;
	def = pwidth;
	if (exp < 0 && pwidth > 0)
		def = def + exp;
	if (pwidth <= -1)
		def = 6 + exp;
	while (def > 0)
	{
		ret = ret * pow;
		def--;
	}
	return (ret);
}

double		pf_pow_e(double pow, int pwidth, int exp)
{
	double	ret;
	int		def;

	ret = 1;
	def = pwidth;
	if (exp < 0 && pwidth > 0)
		def = pwidth + exp;
	if (def < pwidth)
		def = pwidth;
	if (pwidth == -1)
		def = 6;
	while (def)
	{
		ret = ret * pow;
		def--;
	}
	return (ret);
}

double		pf_pow_g(double pow, int pwidth, int exp)
{
	double	ret;
	int		def;

	ret = 1;
	def = pwidth;
	if (exp < 0 && pwidth > 0)
		def = def + exp;
	if (pwidth == -1)
		def = 5;
	if (pwidth == -2)
		def = 5 - (exp + 1);
	while (def > 0)
	{
		ret = ret * pow;
		def--;
	}
	return (ret);
}

double		pf_isnegdouble(double num, int *neg)
{
	double	n;

	*neg = 0;
	n = num;
	if (num < 0)
	{
		n = num * -1;
		*neg = 1;
	}
	if (num > 0)
		n = num;
	return (n);
}
