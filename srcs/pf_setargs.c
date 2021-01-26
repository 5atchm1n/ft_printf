/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:12:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/26 00:44:18 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** 1 = char
** 2 = string
** 3 = pointer
** 4 = integer
** 5 = decimal
** 6 = unsigned
** 7 = hex
** 8 = HEX
*/

static int		pf_settype(signed char c)
{
	int			n;

	if (c == -1)
		return (-1);
	n = pf_isformat(c);
	if (n == 0)
		return (n);
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (3);
	if (n == 4 || n == 5)
		return (4);
	if (n == 6)
		return (5);
	if (n == 7 || n == 8)
		return (6);
	if (n == 9 || n == 10 || n == 11)
		return (7);
	return (-1);
}

static t_arg	pf_setarg(t_arg arg, int type, va_list args)
{
	if (type == 0)
		arg.ch = '%';
	if (type == 1)
		arg.ch = (char)va_arg(args, int);
	if (type == 2)
		arg.str = va_arg(args, char *);
	if (type == 3)
		arg.ptr = va_arg(args, intptr_t);
	if (type == 4)
		arg.nbr = (intmax_t)va_arg(args, int);
	if (type == 5)
		arg.unbr = (uintmax_t)va_arg(args, unsigned int);
	if (type == 6)
		arg.unbr = (uintmax_t)va_arg(args, unsigned int);
	if (type == 7)
		arg.dbl = va_arg(args, double);
	return (arg);
}

t_arg			pf_setargs(t_arg arg, va_list args, signed char f)
{
	int			type;

	type = pf_settype(f);
	arg = pf_setarg(arg, type, args);
	return (arg);
}
