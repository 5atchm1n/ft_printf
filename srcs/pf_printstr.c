/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:34:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/21 16:09:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	pf_str_putspace(char *str, int fwidth, int pwidth)
{
	int		len;
	int		n;
	int		width;

	len = pf_strlen(str);
	n = 0;
	width = pwidth;
	if (str == NULL)
		len = pf_strlen("(null)");
	if (pwidth <= 0)
	{
		n = pf_write_space(fwidth);
		width = 0;
		return (n);
	}
	if (len >= pwidth)
	{
		n = pf_write_space(fwidth - width);
		return (n);
	}
	if (len < pwidth)
	{
		n = pf_write_space(fwidth - len);
		return (n);
	}
	return (n);
}

static int	pf_putstr_r(char *str, t_flags flags)
{
	int		n;

	n = 0;
	if (str == NULL && flags.precision == 0)
	{
		n = pf_write_fwidth_r(str, flags.fwidth);
		return (n);
	}
	if (flags.precision == 1)
	{
		n += pf_str_putspace(str, flags.fwidth, flags.pwidth);
		n = pf_write_preci(str, flags.pwidth);
	}
	if (flags.precision == 0 && flags.fwidth >= 0)
		n = pf_write_fwidth_r(str, flags.fwidth);
	return (n);
}

static int	pf_putstr_l(char *str, t_flags flags)
{
	int		n;

	n = 0;
	if (str == NULL && flags.precision == 0)
	{
		n = pf_write_fwidth_l(str, flags.fwidth);
		return (n);
	}
	if (flags.precision == 1)
	{
		n = pf_write_preci(str, flags.pwidth);
		n += pf_str_putspace(str, flags.fwidth, flags.pwidth);
	}
	if (flags.precision == 0 && flags.fwidth >= 0)
		n = pf_write_fwidth_l(str, flags.fwidth);
	return (n);
}

int			pf_printstr(char *str, t_flags flags)
{
	int		n;

	n = 0;
	if (flags.left == 0)
		n = pf_putstr_r(str, flags);
	if (flags.left == 1)
		n = pf_putstr_l(str, flags);
	return (n);
}
