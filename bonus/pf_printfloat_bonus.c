/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/18 21:07:33 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_convertf(double number, signed char format, int pwidth)
{
	char		*ret;

	ret = NULL;
	if (format == 'f')
		ret = pf_convertfloat(number, pwidth);
	if (format == 'e')
		ret = pf_convertexp(number, pwidth);
	if (format == 'g')
		ret = pf_convertfloatg(number, pwidth);
	return (ret);
}

static char		*pf_addflags(char *str, t_flags flags, int neg, int l)
{
	int			len;
	char		*ret;

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

int				pf_printfloat(double number, t_flags flags, signed char format)
{
	int			len;
	int			neg;
	char		*pfstring;
	double		num;

	num = pf_isnegdouble(number, &neg);
	pfstring = pf_convertf(num, format, flags.pwidth);
	len = pf_strlen(pfstring);
	if (flags.zero == 1 && flags.fwidth > len && flags.left == 0)
		pfstring = pf_putzero(pfstring, flags.fwidth);
	pfstring = pf_addflags(pfstring, flags, neg, len);
	len = pf_strlen(pfstring);
	if (flags.fwidth > 0 && flags.fwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.fwidth, flags.left);
	len = pf_putstr(pfstring);
	free(pfstring);
	return (len);
}
