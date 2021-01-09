/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setreturn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 02:27:43 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/09 01:04:22 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** 1 = char
** 2 = string
** 3 = pointer
** 4 = integer
** 5 = hex
** 6 = HEX
*/

static int	pf_ret_type(signed char format)
{
	int		n;

	n = pf_isformat(format);
	if (n == 1)
		return(1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (3);
	if (n > 3)
		return (4);
}

void	*pf_setreturn(t_pfdata pfdata)
{
	int	type;
	char	*pfstring;

	pfstring = NULL;
	type = pf_ret_type(pfdata->format);
	if (type == 1)
		write(1 , pfdata->arg->ch, 1);
	if (type == 2)
		pf_printstr(pfdata->arg->str, pfdata->flags);
	if (type == 3)
	{
		pfstring = pf_convert(pfdata->arg->ptr, pfdata->format, pfdata->flags);
		pf_printptr(pfstring);
	}
	if (type == 4)
	{
		pfstring = pf_convert(pfdata->arg->nbr, pfdata->format, pfdata->flags);
		pf_printstr(pfstring, pfdata->flags);
	}
}
