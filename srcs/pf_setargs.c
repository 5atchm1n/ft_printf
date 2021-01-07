/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:12:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/07 22:08:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int			pf_settype(signed char c)
{
	int				n;

	if (c == -1)
		return (-1);
	n = pf_isformat(c);
	if (n == 0)
		return (n);
	if (n > 3)
		return (1);
	if (n == 1)
		return (2);
	if (n == 2)
		return (3);
	if (n == 3)
		return (4);
	return (-1);
}

static t_arg		pf_setarg(t_arg arg, int type, va_list args)
{
	int				num;
	char			*string;
	unsigned char	chr;
	uintptr_t		ptr;

	if (type == 1)
	{
		num = va_arg(args, int);
		arg.nbr = num;
	}
	if (type == 2)
	{
		chr = (char)va_arg(args, int);
		arg.ch = chr;
	}
	if (type == 3)
	{
		string = va_arg(args, char *);
		arg.str = string;
	}
	if (type == 4)
	{
		ptr = va_arg(args, uintptr_t);
		arg.ptr = ptr;
	}
	return (arg);
}

t_arg				pf_setargs(t_arg arg, va_list args, signed char f)
{
	int				type;

	type = pf_settype(f);
	arg = pf_setarg(arg, type, args);

	return (arg);
}
