/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printuint_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:11:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/08 01:30:06 by sshakya          ###   ########.fr       */
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

static char			*pf_set_p(t_flags flags, char *pfstring, uintmax_t num,
		signed char format)
{
	int				len;

	len = pf_strlen(pfstring);
	if (num == 0 && flags.precision == 1 && (flags.pwidth == 0 ||
				flags.pwidth == -1))
	{
		free(pfstring);
		pfstring = malloc(sizeof(char));
		pfstring[0] = '\0';
	}
	if (flags.precision == 1 && flags.pwidth > 0)
		pfstring = pf_putzero(pfstring, flags.pwidth);
	if (flags.precision == 0)
	{
		if (flags.zero == 1 && flags.fwidth > len && flags.left == 0)
			pfstring = pf_putzero_u(pfstring, flags, format);
	}
	return (pfstring);
}

int					pf_printuint(uintmax_t num, t_flags flags,
		signed char format)
{
	char			*pfstring;
	int				len;

	pfstring = pf_convert(num, format);
	pfstring = pf_set_p(flags, pfstring, num, format);
	pfstring = pf_addflags(pfstring, flags, format);
	len = pf_strlen(pfstring);
	if (flags.fwidth > 0 && flags.fwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.fwidth, flags.left);
	len = pf_putstr(pfstring);
	free(pfstring);
	return (len);
}
