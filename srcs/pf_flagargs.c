/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flagargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 04:52:17 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/25 01:37:32 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	pf_checkarg(char *str)
{
	int		flag;

	flag = 0;
	while (*str != '\0' && pf_isformat(*str) == -1)
	{
		if (*str == '.')
			flag = 1;
		if (*str == '*' && flag == 0)
			return (1);
		str++;
	}
	return (0);
}

static int	pf_setargp(char *str, va_list args)
{
	int		res;
	int		precision;

	precision = 0;
	res = -1;
	while (*str != '\0')
	{
		if (pf_isflag(*str) == 5)
			precision = 1;
		if (pf_isflag(*str) == 6 && precision)
		{
			res = va_arg(args, int);
			return (res);
		}
		str++;
	}
	return (res);
}

static int	pf_setargw(char *str, va_list args)
{
	int		res;

	res = -1;
	while (*str != '\0')
	{
		if (pf_isflag(*str) == 6)
		{
			res = va_arg(args, int);
			if (res < 0)
				res = -res;
			return (res);
		}
		str++;
	}
	return (res);
}

void		pf_flagargs(t_flags *flags, va_list args, char *str)
{
	if (flags->asterisk == 2)
	{
		flags->fwidth = pf_setargw(str, args);
		flags->pwidth = pf_setargp(str, args);
		return ;
	}
	if (flags->asterisk == 1)
	{
		if (pf_checkarg(str))
			flags->fwidth = pf_setargw(str, args);
		else
			flags->pwidth = pf_setargp(str, args);
	}
	return ;
}
