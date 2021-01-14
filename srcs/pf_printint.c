/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:11:26 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/14 01:16:34 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

static uintmax_t	pf_isnegative(intmax_t num, int *neg)
{
	uintmax_t		n;

	*neg = 0;
	if (num < 0)
	{
		n = num * -1;
		*neg = 1;
	}
	if (num > 0)
		n = num;
	return (n);
}

static char		*pf_putfwidth(char *str, int width, int left, char flag)
{
	char		*ret;
	ret = malloc(sizeof(char) * (width + 1));
	if (left == 0)
		pf_putwidth(str, width, flag, ret);
	if (left == 1)
		pf_putleft(str, width, flag, ret);
	ret[width] = '\0';
	return (ret);
}

static char		*pf_addflags(char *str, t_flags flags)
{
	int			len;

	len = ft_strlen(str);
	if((flags.space == 1 && flags.plus == 1) || flags.plus == 1)
		str = pf_putflag(str, '+');
	else if(flags.space == 1)
		str = pf_putflag(str, ' ');
	else if(flags.zero == 1 && flags.fwidth > len && flags.left == 0)
		str = pf_putfwidth(str, flags.fwidth, 0, '0');
	return (str);
}

int				pf_printint(intmax_t num, t_flags flags, signed char format)
{
	char		*pfstring;
	uintmax_t	n;
	int			len;
	int			neg;

	n = pf_isnegative(num, &neg);
	pfstring = pf_convert(n, format, neg);
	len = ft_strlen(pfstring);
	if (flags.precision == 1 && flags.pwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.pwidth, 0, '0');
	if (flags.precision == 0)
		pfstring = pf_addflags(pfstring, flags);
	len = ft_strlen(pfstring);
	if (flags.fwidth > 0 && flags.fwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.fwidth, flags.left, ' ');
	len = pf_putstr(pfstring);
	return(0);
}
