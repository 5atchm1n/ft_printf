/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:32:11 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/19 00:51:14 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format		*ft_setformat(char *str, t_format *n)
{
	char		*format;
	int			i;

	format = "cspidux";
	n = malloc(sizeof(t_format));
	if (n == NULL)
		return (-1);
	while (*str != '\0')
	{
		while (format[i] != '/0')
		{
			i = 0;
			if (*str = format[i])
			{
				*n = i + 1;
				return (n);
			}
			i++;
		}
		str++;
	}
	return (-1);
}
