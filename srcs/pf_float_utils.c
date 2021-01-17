/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/17 23:45:10 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*pf_addexp(char *str, int exp)
{
	char		*ret;
	char		*base;
	int			neg;
	int			i;

	i = 0;
	base = "0123456789";
	ret = malloc(sizeof(char) * 5);
	if (ret == NULL)
		return (NULL);
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
	ret[i++] = 'e';
	ret[i++] = '\0';
	ret = pf_revstr(ret);
	ret = pf_joinstr(str, ret);
	return (ret);
}

static char		pf_perr(char c)
{
	if (c == '9')
		return ('0');
	return (c + 1);
}

static char		*pf_setperr(char *str)
{
	int			len;
	int			err;

	len = pf_strlen(str);
	err = 1;
	while (len && err == 1)
	{
		str[len - 1] = pf_perr(str[len - 1]);
		err = 0;
		if (str[len - 1] == '0')
			err = 1;
		len--;
	}
	return (str);
}

static int		pf_setfzero(char **str, int *exp, int *pwidth)
{
	int			i;

	i = 0;
	if (*pwidth == -1)
		*pwidth = 6;
	while (*exp < -1)
	{
		(*str)[i] = '0';
		(*exp)++;
		(*pwidth)--;
		i++;
	}
	(*str)[i] = '\0';
	return (i);
}

char			*pf_addpow(char *str, int exp, int pwidth)
{
	char		*ret;
	int			i;
	int			j;
	int			len;

	j = 0;
	len = pf_strlen(str);
	ret = malloc(sizeof(char) * (len + (exp * -1)));
	if (ret == NULL)
		return (NULL);
	i = pf_setfzero(&ret, &exp, &pwidth);
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
