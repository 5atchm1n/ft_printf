/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:11:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/31 14:26:30 by sshakya          ###   ########.fr       */
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

static char			*pf_addflags_p(char *str, int neg)
{
	char			*ret;

	ret = str;
	if (neg == 1)
		ret = pf_putflag(str, '-');
	return (ret);
}

static char			*pf_addflags(char *str, t_flags flags, int neg, int l)
{
	int				len;
	char			*ret;

	len = pf_strlen(str);
	ret = str;
	if (neg == 1 && (flags.zero == 0 || flags.fwidth <= l))
	{
		ret = pf_putflag(str, '-');
		return (ret);
	}
	if (neg == 1 && flags.zero == 1 && flags.fwidth > len)
		ret = pf_putflag(str, '-');
	if (neg == 1 && flags.zero == 1 && flags.fwidth <= len)
		str[0] = '-';
	return (ret);
}

static char			*pf_set_p(t_flags flags, char *pfstring, int neg,
		uintmax_t num)
{
	int				len;

	len = pf_strlen(pfstring);
	if (num == 0 && flags.precision == 1 && (flags.pwidth == 0 ||
				flags.pwidth == -1))
	{
		free(pfstring);
		pfstring = NULL;
	}
	if (flags.precision == 1)
	{
		pfstring = pf_putzero(pfstring, flags.pwidth);
		pfstring = pf_addflags_p(pfstring, neg);
	}
	if (flags.precision == 0)
	{
		if (flags.zero == 1 && flags.fwidth > len && flags.left == 0)
			pfstring = pf_putzero(pfstring, flags.fwidth);
		pfstring = pf_addflags(pfstring, flags, neg, len);
	}
	return (pfstring);
}

int					pf_printint(intmax_t num, t_flags flags, signed char format)
{
	char			*pfstring;
	uintmax_t		n;
	int				len;
	int				neg;

	n = pf_isnegative(num, &neg);
	pfstring = pf_convert(n, format);
	pfstring = pf_set_p(flags, pfstring, neg, num);
	len = pf_strlen(pfstring);
	if (flags.fwidth > 0 && flags.fwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.fwidth, flags.left);
	len = pf_putstr(pfstring);
	free(pfstring);
	return (len);
}
