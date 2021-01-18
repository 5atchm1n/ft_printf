/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:34:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/18 02:33:10 by sshakya          ###   ########.fr       */
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
	ret = malloc(sizeof(char) * 5);
	if (ret == NULL)
		return (NULL);
	i = pf_convert_exp(ret, exp);
	ret[i++] = 'e';
	ret[i++] = '\0';
	ret = pf_revstr(ret);
	ret = pf_joinstr(str, ret);
	return (ret);
}
