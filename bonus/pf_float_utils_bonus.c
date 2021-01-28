/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/28 23:40:36 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

char			*pf_doublezero(int pwidth)
{
	int			width;
	char		*ret;
	int			i;

	i = 0;
	width = pwidth;
	if (pwidth == -1)
		width = 6;
	ret = malloc(sizeof(char) * (pwidth + 1));
	if (ret == NULL)
		return (NULL);
	while (i < width)
	{
		ret[i] = '0';
		i++;
	}
	ret[i++] = '\0';
	return (ret);
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
	if (pwidth == -1)
		pwidth = 6;
	while (len && pwidth > 0)
	{
		ret[i] = str[j];
		i++;
		j++;
		len--;
		pwidth--;
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}

static int		pf_copystr(char *src, char *dest)
{
	size_t		n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	free(src);
	return (n);
}

char			*pf_joinfloat(char *s1, char *s2)
{
	char		*str;
	size_t		len;
	size_t		i;
	size_t		j;

	len = pf_strlen(s1) + pf_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = pf_copystr(s1, str);
	j = 0;
	str[i] = '.';
	i++;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s2);
	return (str);
}

char			*pf_joinstr(char *s1, char *s2)
{
	char		*str;
	size_t		len;
	size_t		i;
	size_t		j;

	len = pf_strlen(s1) + pf_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = pf_copystr(s1, str);
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s2);
	return (str);
}
