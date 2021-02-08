/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:08:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/08 02:47:09 by sshakya          ###   ########.fr       */
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
	if (s == NULL)
		return (0);
	while (s && s[i] != '\0')
	{
		i++;
	}
	return (i);
}
