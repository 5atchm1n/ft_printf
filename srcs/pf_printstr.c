/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:34:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/14 00:03:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	pf_putstr_l(char *str, int width, int left)
{
	int		l;

	l = ft_strlen(str);
	if (left)
	{
		write (1, str, l);
		while (l < width)
		{
			write(1, " ", 1);
			l++;
		}
	}
	else
	{
		while (l < width)
		{
			write(1, " ", 1);
			width--;
		}
		write(1, str, l);
	}
	return(width);
}

static int	pf_putstrs(char *str, int width, int left)
{
	int		l;

	l = ft_strlen(str);
	if (l > width)
	{
		write(1 ,str, l);
	}
	else
	{
		l = pf_putstr_l(str, width, left);
	}
	return (l);
}

static int	pf_putstr_pw(char *str, int pwidth, int fwidth, int left)
{
	int		l;
	l = ft_strlen(str);
	if (l > pwidth && pwidth >= fwidth)
	{
		write (1, str, pwidth);
		return (pwidth);
	}
	if (l > pwidth && fwidth > pwidth && left == 1)
	{
		write (1 , str, fwidth);
		while (pwidth < fwidth)
		{
			write(1, " ", 1);
			pwidth++;
		}
		return (fwidth);
	}
	if (l > pwidth && fwidth > pwidth && left == 0)
	{
		while (pwidth < fwidth)
		{
			write(1, " ", 1);
			pwidth++;
		}
		write (1, str, pwidth);
		return (fwidth);
	}
	return(0);
}

int			pf_printstr(char *str, t_flags flags)
{
	int		i;

	i = 0;
	if (flags.fwidth == 0 && flags.precision == 0)
		i = pf_putstr(str);
	if (flags.precision == 1)
		i = pf_putstr_pw(str, flags.pwidth, flags.fwidth, flags.left);
	if (flags.fwidth > 0 && flags.precision == 0)
		i = pf_putstrs(str, flags.fwidth, flags.left);
	return (i);
}
