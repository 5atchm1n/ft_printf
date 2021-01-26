/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_split_utlis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:23:04 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/26 19:24:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*pf_string(char const *str, size_t len)
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

size_t			pf_splitsize(const char *str)
{
	size_t		n;

	n = 0;
	while (*str != '\0' && (pf_isflag(*str) >= 0 ||
				pf_isdigit(*str) == 1))
	{
		n++;
		str++;
	}
	if (pf_isformat(*str) == 0)
	{
		str++;
		n++;
	}
	while (*str != '\0' && *str != '%')
	{
		n++;
		str++;
	}
	return (n);
}

size_t			pf_splitlen(const char *str)
{
	size_t		n;
	int			flag;

	n = 0;
	flag = 0;
	while (*str != '\0' && n == 0)
	{
		if (*str == '%')
		{
			str++;
			n++;
			n += pf_splitsize(str);
		}
		if (*str)
			str++;
	}
	return (n);
}

