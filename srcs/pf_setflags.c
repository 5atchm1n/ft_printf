/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:06:23 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/12 14:57:13 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		pf_setflagdata(char *str, t_flags *flags)
{
	flags->hash = pf_flagtrue(str, 0);
	printf("%d ", flags->hash);
	flags->space = pf_flagtrue(str, 1);
	printf("%d ", flags->space);
	flags->plus = pf_flagtrue(str, 2);
	printf("%d ", flags->plus);
	flags->left = pf_flagtrue(str, 3);
	printf("%d ", flags->left);
	flags->zero = pf_flagtrue(str, 4);
	printf("%d\n", flags->zero);
	flags->fwidth = pf_fwidth(str);
	flags->asterisk = pf_asterisk(str);
	flags->precision = pf_precision(str);
	if (flags->precision == 1)
		flags->pwidth = pf_pwidth(str);
	else
		flags->pwidth = 0;
}

t_flags			*pf_setflags(char *str, t_flags *flags, va_list args)
{
	str++;
	if (!flags)
		return (NULL);
	if (pf_isformat(*str) == 0)
	{
		pf_flagzero(flags);
		return (flags);
	}
	pf_setflagdata(str, flags);
	if (flags->asterisk != 0)
		pf_flagargs(flags, args, str);
	return (flags);
}
