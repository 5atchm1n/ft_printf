/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setreturn_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 02:27:43 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/28 22:35:56 by sshakya          ###   ########.fr       */
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

static int		pf_ret_type(signed char format)
{
	int			n;

	n = pf_isformat(format);
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (3);
	if (n == 4 || n == 5)
		return (4);
	if (n == 6 || n == 7 || n == 8)
		return (5);
	if (n == 9 || n == 10 || n == 11)
		return (6);
	return (0);
}

int				pf_setreturn(t_pfdata *pfdata)
{
	int			type;
	char		*pfstring;
	int			n;

	pfstring = NULL;
	n = 0;
	type = pf_ret_type(pfdata->format);
	if (type == 0)
		n = pf_printchar(pfdata->arg.ch, pfdata->flags, pfdata->format);
	if (type == 1)
		n = pf_printchar(pfdata->arg.ch, pfdata->flags, pfdata->format);
	if (type == 2)
		n = pf_printstr(pfdata->arg.str, pfdata->flags);
	if (type == 3)
		n = pf_printuint(pfdata->arg.ptr, pfdata->flags, pfdata->format);
	if (type == 4)
		n = pf_printint(pfdata->arg.nbr, pfdata->flags, pfdata->format);
	if (type == 5)
		n = pf_printuint(pfdata->arg.unbr, pfdata->flags, pfdata->format);
	if (type == 6)
		n = pf_printfloat(pfdata->arg.dbl, pfdata->flags, pfdata->format);
	return (n);
}
