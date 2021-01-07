/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:12:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/07 22:24:02 by sshakya          ###   ########.fr       */
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
	if (type == 1)
		arg.nbr = va_arg(args, int);
	if (type == 2)
		arg.ch = (char)va_arg(args, int);
	if (type == 3)
		arg.str = va_arg(args, char *);
	if (type == 4)
		arg.ptr = va_arg(args, uintptr_t);
	return (arg);
}

t_arg				pf_setargs(t_arg arg, va_list args, signed char f)
{
	int				type;

	type = pf_settype(f);
	arg = pf_setarg(arg, type, args);
	return (arg);
}
