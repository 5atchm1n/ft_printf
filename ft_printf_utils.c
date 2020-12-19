/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:02:19 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/19 03:33:41 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isflag(char c, char *flags)
{
	int		n;

	n = 0;
	if (c == '%')
		return (-2);
	while (flags[n] != '\0')
	{
		if (c == flags[n])
			return (n);
		n++;
	}
	return (-1);
}

int			ft_flagtrue(char *str, char *flags, int n)
{
	int		i;

	i = 0;
	while (*str != '\0' && i >= 0)
	{
		i = ft_isflag(*str, flags);
		if (i == n)
			return (1);
		str++;
	}
	return (0);
}

int			ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *src)
{
	size_t	i;
	char	*dup;

	i = 0;
	if (!(dup = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
