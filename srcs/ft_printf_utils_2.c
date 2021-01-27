/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:08:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/27 00:59:21 by sshakya          ###   ########.fr       */
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
