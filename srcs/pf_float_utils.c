/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/17 08:49:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

double			pf_pow(double pow, int pwidth)
{
	double		ret;
	int			def;

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

double			pf_exp(double pow, int *exp)
{
	int			n;

	n = 0;
	if (pow < 1)
	{
		while (pow < 10)
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

double			pf_isnegdouble(double num, int *neg)
{
	double		n;

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

static char		*pf_joinstr(char *s1, char *s2)
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

char			*pf_addexp(char *str, int exp)
{
	char		*ret;
	char		*base;
	int			neg;
	int			i;

	neg = 0;
	i = 0;
	base = "0123456789";
	ret = malloc(sizeof(char) * 5);
	if (exp < 0)
	{
		exp = exp * -1;
		neg = 1;
	}
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
	ret[i++] = 'e';
	ret[i++] = '\0';
	ret = pf_revstr(ret);
	ret = pf_joinstr(str, ret);
	return (ret);
}

static char		pf_perr(char c)
{
	if (c == '9')
		return('0');
	return (c + 1);
}

static char		*pf_setperr(char *str)
{
	int			len;
	int			err;
	
	len = pf_strlen(str);
	err = 1;
	while(len && err == 1)
	{
		str[len - 1] = pf_perr(str[len - 1]);
		err = 0;
		if (str[len - 1] == '0')
			err = 1;
		len--;
	}
	return (str);
}


char			*pf_addpow(char *str, int exp, int pwidth)
{
	char		*ret;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	len = pf_strlen(str);
	ret = malloc(sizeof(char) * (len + (exp * -1)));
	if (pwidth == -1)
		pwidth = 6;
	while (exp < -1)
	{
		ret[i] = '0';
		i++;
		exp++;
		pwidth--;
	}
	while (len && pwidth > 0)
	{
		ret[i] = str[j];
		i++;
		j++;
		len--;
		pwidth--;
	}
	ret[i] = '\0';
	if (len > 0)
		ret = pf_setperr(ret);
	return (ret);
}
