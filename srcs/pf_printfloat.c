/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/17 02:04:40 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static double	pf_isneg(double num, int *neg)
{
	double		n;

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

static double	pf_pow(double pow, int pwidth)
{
	double		ret;
	int			def;

	ret = 1;
	def = pwidth;
	if (pwidth == -1)
		def = 6;
	while(def)
	{
		ret = ret * pow;
		def--;
	}
	return (ret);
}

static char		*pf_join(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = pf_strlen(s1) + pf_strlen(s2) + 1;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	str[i] = '.';
	i++;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

static char		*pf_convertfloat(double number, int pwidth)
{
	char		*dig;
	char		*flt;
	char		*ret;
	double		deci;
	intmax_t	digit;
	int			i;

	digit = (uintmax_t)number;
	deci = number - (double)digit;

	dig = pf_convertbase(digit, "0123456789");
	i = pf_strlen(dig);
	deci = deci * pf_pow(10, pwidth);
	flt = pf_convertbase((uintmax_t)deci, "0123456789");
	ret = pf_join(dig, flt);
	return (ret);
}

static char		*pf_convertf(double number, signed char format, int pwidth)
{
	char		*ret;

	ret = NULL;
	if (format == 'f')
		ret = pf_convertfloat(number, pwidth);
	if (format == 'e')
		ret = pf_convertfloat(number, pwidth);
//		ret = pf_convertexp(number,pwidth);
	if (format == 'g')
		ret = pf_convertfloat(number, pwidth);
//		ret = pfconvertg(number, pwidth);
	return (ret);
}

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

int				pf_printfloat(double number, t_flags flags, signed char format)
{
	int			len;
	int			neg;
	char		*pfstring;
	double		num;

	num = pf_isneg(number, &neg);
	pfstring = pf_convertf(num, format, flags.pwidth);
	len = pf_strlen(pfstring);
	if (flags.zero == 1 && flags.fwidth > len && flags.left == 0)
		pfstring = pf_putzero(pfstring, flags.fwidth);
	pfstring = pf_addflags(pfstring, flags, neg, len);
	len  = pf_strlen(pfstring);
	if (flags.fwidth > 0 && flags.fwidth > len)
		pfstring = pf_putfwidth(pfstring, flags.fwidth, flags.left);
	len = pf_putstr(pfstring);
	free(pfstring);
	return (len);
}
