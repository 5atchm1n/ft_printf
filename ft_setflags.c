/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:06:23 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/16 05:04:01 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_fleft(char *str)
{
	if (str == NULL)
		return (-1);
	while (*str != '\0' && str == '%')
		str++;
	if (*str == '-')
		return (1);
	return (0);
}

static int		ft_fzero(char *str)
{
	if (str == NULL)
		return (-1);
	while (*str != '\0' && *str == '%')
		str++;
	if (*str == '0')
		return (1);
	return (0);
}

static int		ft_fwidth(char *str)
{
	int				width;

	width = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			width = width + (*str - '0');
		str++;
		if (ft_isformat(*str))
			return (width);
	}
	return (0);
}



static int		ft_precision(char *str)
{
//	not ready yet

	return (0);
}

t_flags			ft_setflags(char *str);
{
	t_flags		flags;

	flags = malloc(sizeof(flags));

	flags.left = ft_fleft(str);
	flags.zero = ft_fzero(str);
	flags.fwidth = ft_fwidth(str);
	flags.precision = ft_precision(str);

	return (flags);
}
