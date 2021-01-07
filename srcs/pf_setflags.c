/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:06:23 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/07 22:14:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		pf_setflagdata(char *str, t_flags *flags)
{
	flags->hash = pf_flagtrue(str, 0);
	flags->space = pf_flagtrue(str,1);
	flags->plus = pf_flagtrue(str, 2);
	flags->left = pf_flagtrue(str, 3);
	flags->zero = pf_flagtrue(str, 4);
	flags->fwidth = pf_fwidth(str);
	flags->asterisk = pf_asterisk(str);
	flags->precision = pf_precision(str);
	if (flags->precision == 1)
		flags->pwidth = pf_pwidth(str);
	else
		flags->pwidth = 0;
}

t_flags		*pf_setflags(char *str, t_flags *flags, va_list args)
{
	str++;
	if (!flags)
		return (NULL);
	if (pf_isflag(*str) == 0)
	{
		pf_flagzero(flags);
		return (flags);
	}
	pf_setflagdata(str, flags);
	if (flags->asterisk != 0)
		pf_flagargs(flags, args, str);
	return (flags);
}
