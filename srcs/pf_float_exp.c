/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:34:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/23 02:29:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		pf_convert_exp(char *ret, int exp)
{
	int			i;
	int			neg;
	char		*base;

	i = 0;
	base = "0123456789";
	neg = pf_isneg(&exp);
	while (exp > 0)
	{
		ret[i] = base[exp % 10];
		exp = exp / 10;
		i++;
	}
	if (i == 1 || i == 0)
		ret[i++] = '0';
	if (i == 1)
		ret[i++] = '0';
	if (neg == 1)
		ret[i++] = '-';
	if (neg == 0)
		ret[i++] = '+';
	return (i);
}

char			*pf_addexp(char *str, int exp)
{
	char		*ret;
	int			i;

	i = 0;
	ret = malloc(sizeof(char) * 6);
	if (ret == NULL)
		return (NULL);
	i = pf_convert_exp(ret, exp);
	ret[i++] = 'e';
	ret[i++] = '\0';
	ret = pf_revstr(ret);
	ret = pf_joinstr(str, ret);
	return (ret);
}

double			pf_exp(double num)
{
	if (num == 1)
		return (num);
	if (num < 1)
	{
		while (num < 10)
		{
			num = num * 10;
		}
	}
	if (num > 1)
	{
		while (num > 10)
		{
			num = num / 10;
		}
	}
	return (num);
}

int				pf_expi(double num)
{
	int		n;

	n = 0;
	if (num < 1)
	{
		while (num < 10 && num != 0)
		{
			num = num * 10;
			n--;
		}
	}
	if (num > 1)
	{
		while (num > 10 && num != 0)
		{
			num = num / 10;
			n++;
		}
	}
	return (n);
}
