/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 04:03:47 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/14 20:45:11 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_string(char const *str, size_t len)
{
	size_t		i;
	char		*ret;

	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}

static size_t	pf_strlen(const char *str)
{
	size_t		n;

	n = 0;
	while (*str != '\0' && n == 0)
	{
		if (*str == '%')
		{
			str++;
			n++;
			if (*str != '\0')
				n++;
			str++;
			while (*str != '\0' && *str != '%')
			{
				n++;
				str++;
			}
		}
		if (*str)
			str++;
	}
	return (n);
}

static size_t	pf_tabsize(const char *str)
{
	size_t		n;

	n = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			n++;
		}
		if (*str == '%')
			str++;
		if (*str != '\0' && *str != '%')
			str++;
	}
	return (n);
}

static char		**pf_settab(const char *str)
{
	size_t		size;
	char		**tab;

	size = pf_tabsize(str);
	if (!(tab = malloc(sizeof(char *) * (size + 1))))
		return (tab = NULL);
	tab[size] = NULL;
	return (tab);
}

char			**pf_split(char const *str)
{
	char		**tab;
	size_t		size;
	size_t		n;
	size_t		len;

	tab = pf_settab(str);
	size = pf_tabsize(str);
	n = 0;
	while (n < size && str)
	{
		while (*str != '\0')
		{
			if (*str == '%')
			{
				len = pf_strlen(str);
				tab[n] = pf_string(str, len);
				n++;
				str++;
			}
			str++;
		}
	}
	return (tab);
}
