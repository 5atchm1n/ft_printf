/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:34:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/19 03:19:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	pf_putstr_l(char *str, int width, int left)
{
	int		l;

	l = pf_strlen(str);
	if (left)
	{
		write(1, str, l);
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
	return (width);
}

static int	pf_putstrs(char *str, int width, int left)
{
	int		l;

	l = pf_strlen(str);
	if (l > width)
	{
		write(1, str, l);
	}
	else
	{
		l = pf_putstr_l(str, width, left);
	}
	return (l);
}

static int	pf_putstr_pw(char *str, int pwidth, int fwidth, int left)
{
	int		len;
	int		n;

	len = pf_strlen(str);
	if (pwidth > len)
	{
		write(1, str, len);
		return (len);
	}
	if (len > pwidth && pwidth >= fwidth)
	{
		write(1, str, pwidth);
		return (pwidth);
	}
	if (len > pwidth && fwidth > pwidth && left == 1)
	{
		n = pf_putstr_wl(str, pwidth, fwidth, left);
		return (n);
	}
	if (len > pwidth && fwidth > pwidth && left == 0)
	{
		n = pf_putstr_w(str, pwidth, fwidth, left);
		return (n);
	}
	return (0);
}

int			pf_printstr(char *str, t_flags flags)
{
	int		i;
	int		len;

	i = 0;
	len = pf_strlen(str);
	if (len == 0)
	{
		free(str);
		str = "(null)";
	}
	if (flags.fwidth == 0 && flags.precision == 0)
		i = pf_putstr(str);
	if (flags.precision == 1)
		i = pf_putstr_pw(str, flags.pwidth, flags.fwidth, flags.left);
	if (flags.fwidth > 0 && flags.precision == 0)
		i = pf_putstrs(str, flags.fwidth, flags.left);
	return (i);
}
