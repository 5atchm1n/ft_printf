/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:32:11 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/19 06:02:22 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		ft_setformat(char *str, t_format *n)
{
	char		*format;
	int			i;

	format = "%cspidux";
//	if (!(n = malloc(sizeof(t_format))))
//		return (-1);
	str++;
	while (*str != '\0')
	{
		i = 0;
		while (format[i] != '\0')
		{
			if (*str == format[i])
			{
				*n = i;
				return (*n);
			}
			i++;
		}
		str++;
	}
	*n = -1;
	return (*n);
}
