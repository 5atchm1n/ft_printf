/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:34:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/08 02:44:54 by sshakya          ###   ########.fr       */
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
	int		err;

	n = 0;
	if (flags.precision == 1)
	{
		n = pf_str_putspace(str, flags.fwidth, flags.pwidth);
		if (n == -1)
			return (-1);
		err = n;
		n += pf_write_preci(str, flags.pwidth);
		if (n < err)
			return (-1);
	}
	if (flags.precision == 0 && flags.fwidth >= 0)
	{
		n = pf_write_fwidth_r(str, flags.fwidth);
		if (n == -1)
			return (-1);
	}
	return (n);
}

static int	pf_putstr_l(char *str, t_flags flags)
{
	int		n;
	int		err;

	n = 0;
	if (flags.precision == 1)
	{
		n = pf_write_preci(str, flags.pwidth);
		if (n == -1)
			return (-1);
		err = n;
		n += pf_str_putspace(str, flags.fwidth, flags.pwidth);
		if (n < err)
			return (-1);
	}
	if (flags.precision == 0 && flags.fwidth >= 0)
	{
		n = pf_write_fwidth_l(str, flags.fwidth);
		if (n == -1)
			return (-1);
	}
	return (n);
}

int			pf_printstr(char *str, t_flags flags)
{
	int		n;
	char	*ret;

	n = 0;
	ret = str;
	if (str == NULL)
		ret = "(null)";
	if (flags.left == 0)
		n = pf_putstr_r(ret, flags);
	if (flags.left == 1)
		n = pf_putstr_l(ret, flags);
	return (n);
}
