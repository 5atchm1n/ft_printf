/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setreturn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 02:27:43 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/09 05:01:40 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** 1 = char
** 2 = string
** 3 = pointer
** 4 = integer
** 5 = hex
** 6 = HEX
*/

static int	pf_ret_type(signed char format)
{
	int		n;

	n = pf_isformat(format);
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (3);
	if (n > 3)
		return (4);
	return (0);
}

void		pf_putstr(char *str)
{
}

void		pf_putstrl(char *str, int width)
{
}

void		pf_putstrs(char *str, int width, int left)
{
}

void		pf_addprecision(char *str)
{
}

void		pf_printstr(char *str, t_flags flags, int n)
{
	if (n == 0)
		pf_putstr(str);
	if (n == 1)
	{
		if (flags.precision == 1)
			pf_putstrl(str, flags.pwidth);
		if (flags.fwidth == 0 && flags.precision == 0)
			pf_putstr(str);
		if (flags.fwidth > 0 && flags.precision == 0)
			pf_putstrs(str, flags.fwidth, flags.left);
	}
	if (n == 2)
	{
		if (flags.precision == 1)
			pf_addprecision(str);
		pf_putstrs(str, flags.fwidth, flags.left);
	}
}

void		pf_setreturn(t_pfdata pfdata)
{
	int		type;
	char	*pfstring;

	pfstring = NULL;
	type = pf_ret_type(pfdata.format);
	if (type == 1)
		write(1, &pfdata.arg.ch, 1);
	if (type == 2)
		pf_printstr(pfdata.arg.str, pfdata.flags, 1);
	if (type == 3)
	{
		pfstring = pf_convert(pfdata.arg.ptr, pfdata.format, pfdata.flags);
		pf_printstr(pfstring, pfdata.flags, 0);
	}
	if (type == 4)
	{
		pfstring = pf_convert(pfdata.arg.nbr, pfdata.format, pfdata.flags);
		pf_printstr(pfstring, pfdata.flags, 2);
	}
}
