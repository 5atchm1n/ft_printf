/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:32:11 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/20 01:28:06 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

signed char		ft_setformat(char *str, signed char *format)
{
	char		*f;
	int			i;

	f = FORMAT;
	str++;
	while (*str != '\0')
	{
		i = 0;
		while (f[i] != '\0')
		{
			if (*str == f[i])
			{
				*format = f[i];
				return (*format);
			}
			i++;
		}
		str++;
	}
	*format = -1;
	return (*format);
}
