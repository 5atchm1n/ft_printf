/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printfloat_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/06 16:04:53 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_convertf(double number, signed char format, t_flags f)
{
	char		*ret;

	ret = NULL;
	if (format == 'f')
		ret = pf_convertfloat(number, f);
	if (format == 'e')
		ret = pf_convertexp(number, f.pwidth, f.precision);
	if (format == 'g')
		ret = pf_convertfloatg(number, f.pwidth, f.precision);
	return (ret);
}

static char		*pf_addflags(char *str, t_flags f, int neg, int l)
{
	int			len;

	len = pf_strlen(str);
	if (neg == 1 && (f.zero == 0 || f.fwidth <= l))
		str = pf_putflag(str, '-');
	if (neg == 1 && f.zero == 1 && f.fwidth > l)
		str[0] = '-';
	if (neg == 0 && (f.fwidth < l ||
				(f.fwidth > l && f.pwidth == -1 && f.precision == 0)))
	{
		if ((f.space == 1 && f.plus == 1) || f.plus == 1)
			str = pf_putflag(str, '+');
		else if (f.space == 1)
			str = pf_putflag(str, ' ');
	}
	if (neg == 0 && f.zero == 1 && f.fwidth > l &&
			(f.pwidth != -1 || f.fwidth == len))
	{
		if ((f.space == 1 && f.plus == 1) || f.plus == 1)
			str[0] = '+';
		else if (f.space == 1)
			str[0] = ' ';
	}
	return (str);
}

int				pf_printfloat(double number, t_flags f, signed char format)
{
	int			len;
	int			neg;
	char		*pfstring;
	double		num;

	num = pf_isnegdouble(number, &neg);
	pfstring = pf_convertf(num, format, f);
	len = pf_strlen(pfstring);
	if (f.zero == 1 && f.fwidth > len && f.left == 0)
		pfstring = pf_putzero(pfstring, f.fwidth);
	pfstring = pf_addflags(pfstring, f, neg, len);
	len = pf_strlen(pfstring);
	if (f.fwidth > 0 && f.fwidth > len)
		pfstring = pf_putfwidth(pfstring, f.fwidth, f.left);
	len = pf_putstr(pfstring);
	free(pfstring);
	return (len);
}
