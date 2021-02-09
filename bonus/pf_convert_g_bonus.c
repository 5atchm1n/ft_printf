/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_g_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:54:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/09 17:40:07 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			pf_setend_g(char *str)
{
	int			len;
	int			n;
	int			flag;

	flag = 0;
	n = 0;
	len = pf_strlen(str);
	while (str[n] != '\0')
	{
		if (str[n] == '.')
			flag = 1;
		n++;
	}
	if (len > 2 && flag)
	{
		len--;
		while (str[len] == '0')
		{
			str[len] = '\0';
			len--;
		}
		if (str[len] == '.')
			str[len] = '\0';
	}
}

static char		*pf_convert_g(double number, int exp, t_flags flags)
{
	char		*ret;

	ret = NULL;
	if (flags.pwidth == -1 && exp < -1)
		ret = pf_convertfloat_fg(number, 5 - exp, flags.precision);
	else if (flags.pwidth == -1 && exp > 0)
		ret = pf_convertfloat_fg(number, (6 - (exp + 1)), flags.precision);
	else if (flags.pwidth == -1 && exp == 0 && flags.precision == 1)
		ret = pf_convertfloat_fg(number, 0, flags.precision);
	else if (flags.pwidth <= 0 && exp == -1 && flags.precision == 1)
		ret = pf_convertfloat_fg(number, 1, flags.precision);
	else
		ret = pf_convertfloat_fg(number, flags.pwidth, flags.precision);
	return (ret);
}

char			*pf_convertfloatg(double number, t_flags flags)
{
	char		*ret;
	int			exp;
	int			width;

	width = flags.pwidth;
	exp = pf_expi(number);
	if ((number > 0 && number < DBL_EPSILON) || number == 0)
		return (pf_convertbase(0, "0123456789"));
	else if (exp < -4 || (exp >= flags.pwidth && flags.pwidth > 0) ||
			(exp > 5 && flags.pwidth == -1))
		ret = pf_convertexpg(number, flags.pwidth, flags.precision);
	else if (exp < 0 && !(exp < -4) && flags.pwidth > 0)
		ret = pf_convertfloat_fg(number, width - (exp + 1), flags.precision);
	else
		ret = pf_convert_g(number, exp, flags);
	pf_setend_g(ret);
	return (ret);
}
