/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:11:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/27 01:00:58 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char			*pf_addflags(char *str, t_flags flags, signed char format)
{
	int				len;
	char			*ret;

	len = pf_strlen(str);
	ret = str;
	if (str == NULL && format != 'p')
		return (NULL);
	if (flags.hash == 1 && format != 'p')
	{
		if (format == 'x')
			ret = pf_putflag(str, (char)format);
		if (format == 'X')
			ret = pf_putflag(str, (char)format);
		if (format == 'x' || format == 'X')
			ret = pf_putflag(ret, '0');
	}
	if (format == 'p')
	{
		ret = pf_putflag(str, 'x');
		ret = pf_putflag(ret, '0');
	}
	return (ret);
}

int					pf_printuint(uintmax_t num, t_flags flags,
		signed char format)
{
	char			*pfstring;
	int				len;

	pfstring = pf_convert(num, format);
	len = pf_strlen(pfstring);
	if (num == 0 && flags.precision == 1 && (flags.pwidth == 0 ||
				flags.pwidth == -1))
	{
		free(pfstring);
		pfstring = NULL;
	}
	if (flags.precision == 1 && flags.pwidth > 0)
		pfstring = pf_putzero(pfstring, flags.pwidth);
	if (flags.precision == 0)
	{
		if (flags.zero == 1 && flags.fwidth > len && flags.left == 0)
			pfstring = pf_putzero(pfstring, flags.fwidth);
	}
	pfstring = pf_addflags(pfstring, flags, format);
	len = pf_strlen(pfstring);
	if (flags.fwidth > 0 && flags.fwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.fwidth, flags.left);
	len = pf_putstr(pfstring);
	free(pfstring);
	return (len);
}