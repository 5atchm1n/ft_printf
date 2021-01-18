/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:34:39 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/18 01:43:54 by sshakya          ###   ########.fr       */
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

double		pf_pow(double pow, int pwidth)
{
	double	ret;
	int		def;

	ret = 1;
	def = pwidth;
	if (pwidth <= -1)
		def = 6;
	while (def)
	{
		ret = ret * pow;
		def--;
	}
	return (ret);
}

double		pf_exp(double pow, int *exp)
{
	int		n;

	n = 0;
	if (pow < 1)
	{
		while (pow < 10 && pow != 0)
		{
			pow = pow * 10;
			n--;
		}
	}
	if (pow > 1)
	{
		while (pow > 10)
		{
			pow = pow / 10;
			n++;
		}
	}
	*exp = n;
	return (pow);
}

double		pf_isnegdouble(double num, int *neg)
{
	double	n;

	*neg = 0;
	if (num < 0)
	{
		n = num * -1;
		*neg = 1;
	}
	if (num > 0)
		n = num;
	return (n);
}

char		*pf_joinstr(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = pf_strlen(s1) + pf_strlen(s2) + 1;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
