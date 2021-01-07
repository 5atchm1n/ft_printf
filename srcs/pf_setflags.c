/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:06:23 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/07 21:14:22 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flags		*pf_setflags(char *str, t_flags *flag, va_list args)
{
	char	*flags;

	flags = FLAGS;
	str++;
	if (!flag)
		return (NULL);
	if (pf_isflag(*str, flags) == 0)
	{
		pf_flagzero(flag);
		return (flag);
	}
	flag->hash = pf_flagtrue(str, flags, 0);
	flag->space = pf_flagtrue(str, flags, 1);
	flag->plus = pf_flagtrue(str, flags, 2);
	flag->left = pf_flagtrue(str, flags, 3);
	flag->zero = pf_flagtrue(str, flags, 4);
	flag->fwidth = pf_fwidth(str, flags);
	flag->asterisk = pf_asterisk(str, flags);
	flag->precision = pf_precision(str, flags);
	if (flag->precision == 1)
		flag->pwidth = pf_pwidth(str, flags);
	else
		flag->pwidth = 0;
	if (flag->asterisk != 0)
		pf_flagargs(flag, args, str);
	return (flag);
}
