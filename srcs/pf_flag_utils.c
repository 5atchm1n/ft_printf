/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 21:13:15 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/09 04:07:56 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_fwidth(char *str)
{
	int		i;

	i = 0;
	while (*str && i >= 0 && i != 6)
	{
		i = pf_isflag(*str);
		if (i < 0)
			break ;
		str++;
	}
	if (ft_isdigit(*str))
	{
		i = 0;
		while (*str)
		{
			if (ft_isdigit(*str))
				i = i * 10 + ((*str) - '0');
			str++;
			if (!(ft_isdigit(*str)))
				return (i);
		}
	}
	return (0);
}

int			pf_pwidth(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0' && i != 5)
	{
		i = pf_isflag(*str);
		str++;
	}
	if (ft_isdigit(*str))
	{
		i = 0;
		while (*str)
		{
			if (ft_isdigit(*str))
				i = i * 10 + ((*str) - '0');
			str++;
			if (!(ft_isdigit(*str)))
				return (i);
		}
	}
	return (-1);
}

int			pf_asterisk(char *str)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (*str != '\0' && i >= 0)
	{
		i = pf_isflag(*str);
		if (i == 6)
			n = n + 1;
		if (i < 0 && ft_isdigit(*str) == 1)
			i = 1;
		str++;
	}
	return (n);
}

int			pf_precision(char *str)
{
	int		i;

	i = 1;
	while (*str != '\0' && i >= 0)
	{
		i = pf_isflag(*str);
		if (i == 5)
			return (1);
		if (i < 0 && ft_isdigit(*str) == 1)
			i = 1;
		str++;
	}
	return (0);
}
