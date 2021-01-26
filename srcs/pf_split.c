/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 04:03:47 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/26 19:35:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
			while (*str != '\0' && (pf_isflag(*str) >= 0 ||
						pf_isdigit(*str) == 1))
				str++;
			if (pf_isformat(*str) == 0)
				str++;
			while (*str != '\0' && *str != '%')
				str++;
		}
		if (*str && *str != '%')
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
	while (str && *str != '\0' && n < size)
	{
		if (*str == '%')
		{
			len = pf_splitlen(str);
			tab[n] = pf_string(str, len);
			n++;
			str = str + len - 1;
		}
		str++;
	}
	return (tab);
}
