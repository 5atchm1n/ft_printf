/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 04:03:47 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/16 06:06:33 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_pfstring(char const *str, size_t len)
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

static size_t	ft_pfstrlen(const char *str)
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

static size_t	ft_tabsize(const char *str)
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

static char		**ft_pfsettab(const char *str)
{
	size_t		size;
	char		**tab;

	size = ft_tabsize(str);
	if (!(tab = malloc(sizeof(char *) * (size + 1))))
		return (tab = NULL);
	tab[size] = NULL;
	return (tab);
}

char			**ft_pfsplit(char const *str)
{
	char		**tab;
	size_t		size;
	size_t		n;
	size_t		len;

	tab = ft_pfsettab(str);
	size = ft_tabsize(str);
	n = 0;
	while (n < size && str)
	{
		while (*str != '\0')
		{
			if (*str == '%')
			{
				len = ft_pfstrlen(str);
				tab[n] = ft_pfstring(str, len);
				n++;
				str++;
			}
			str++;
		}
	}
	return (tab);
}
