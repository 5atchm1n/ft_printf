/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convertfloat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/16 02:35:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static double	pf_pow(double pow, int exp)
{
	int temp;
	double ret;

	temp = 0;
	if (exp == -1)
		return(1000000);
	while(temp < exp)
	{
		ret = pow;
		temp++;
	}


static char		pf_convert(double number, int pwidth)
{
	char		*digit;
	char		*flt;
	double		deci;
	intmax_t	digit;
	int			i;

	digit = (uintmax_t)number;
	deci = number - (double)digit;

	digit = pf_convertbase(digit, "0123456789");
	i = pf_strlen(ret);
	deci = deci * pf_pow(10, pwidth);
	flt = pf_convertbase((uintmax_t)deci, "0123456789");
	pf_join(digit, flt);
	return (ret);
}

char		pf_convertf(double number, signed char format, t_flags flags)
{
	char	*ret;

	if (format == 'f')
		ret = pf_convertfloat(number, flags.pwidth);
	if (format == 'e')
		ret = pf_convertexp(number, flags.pwidth);
	if (format == 'g')
		ret = pfconvertg(number, flags.pwidth);
	return (ret);
}
