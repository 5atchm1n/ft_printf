/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:11:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/26 15:30:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static uintmax_t	pf_isnegative(intmax_t num, int *neg)
{
	uintmax_t		n;

	*neg = 0;
	if (num == 0)
		return (0);
	if (num < 0)
	{
		n = num * -1;
		*neg = 1;
	}
	if (num > 0)
		n = num;
	return (n);
}

static char			*pf_addflags_p(char *str, t_flags flags, int neg)
{
	char			*ret;

	ret = str;
	if (neg == 1)
		ret = pf_putflag(str, '-');
//	if (neg == 0 && flags.pwidth <= l)
	if (neg == 0)
	{
		if ((flags.space == 1 && flags.plus == 1) || flags.plus == 1)
			ret = pf_putflag(str, '+');
		else if (flags.space == 1)
			ret = pf_putflag(str, ' ');
	}
//	if (neg == 0 && flags.pwidth > l)
//	{
//		if ((flags.space == 1 && flags.plus == 1) || flags.plus == 1)
//			str[0] = '+';
//		else if (flags.space == 1)
//			str[0] = ' ';
//	}
	return (ret);
}
/*
static char			*pf_addflags(char *str, t_flags flags, int neg, int l)
{
	int				len;
	char			*ret;

	len = pf_strlen(str);
	ret = str;
	if (neg == 1 && (flags.zero == 0 || flags.fwidth <= l))
		ret = pf_putflag(str, '-');
	if (neg == 1 && flags.zero == 1 && flags.fwidth > l)
		str[0] = '-';
	if (neg == 0 && (flags.zero == 0 || flags.fwidth == l))
	{
		if ((flags.space == 1 && flags.plus == 1) || flags.plus == 1)
			ret = pf_putflag(str, '+');
		else if (flags.space == 1)
			ret = pf_putflag(str, ' ');
	}
	if (neg == 0 && flags.zero == 1 && flags.fwidth > l)
	{
		if ((flags.space == 1 && flags.plus == 1) || flags.plus == 1)
			str[0] = '+';
		else if (flags.space == 1)
			str[0] = ' ';
	}
	return (ret);
}
*/
int					pf_printint(intmax_t num, t_flags flags, signed char format)
{
	char			*pfstring;
	uintmax_t		n;
	int				len;
	int				neg;

	n = pf_isnegative(num, &neg);
	pfstring = pf_convert(n, format);
	len = pf_strlen(pfstring);
	if (n == 0 && flags.precision == 1 && (flags.pwidth == 0 || flags.pwidth == -1))
		pfstring = NULL;
	if (flags.precision == 1)
	{
		pfstring = pf_putzero(pfstring, flags.pwidth);
		pfstring = pf_addflags_p(pfstring, flags, neg);
	}
	if (flags.precision == 0)
	{
		if (flags.zero == 1 && flags.fwidth > len && flags.left == 0)
			pfstring = pf_putzero(pfstring, flags.fwidth);
		pfstring = pf_addflags_p(pfstring, flags, neg);
	}
	len = pf_strlen(pfstring);
	if (flags.fwidth > 0 && flags.fwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.fwidth, flags.left);
	len = pf_putstr(pfstring);
	free(pfstring);
	return (len);
}
