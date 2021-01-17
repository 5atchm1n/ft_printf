/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:08:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/17 04:59:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			pf_putstr(char *str)
{
	int		l;

	l = pf_strlen(str);
	write(1, str, l);
	return (l);
}

int			pf_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int			pf_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*pf_join(char *s1, char *s2)
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
	str[i] = '.';
	i++;
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
