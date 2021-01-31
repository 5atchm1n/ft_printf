/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:25:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/31 15:31:08 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		pf_charspace(t_flags flags, signed char format)
{
	char		c;
	int			n;

	c = ' ';
	n = 1;
	if ((flags.zero == 1 || flags.precision == 1) && format == '%'
			&& flags.left == 0)
		c = '0';
	while (flags.fwidth > n)
	{
		write(1, &c, 1);
		n++;
	}
	return (n);
}

int				pf_printchar(char c, t_flags flags, signed char format)
{
	int			n;

	n = 1;
	if (flags.left == 0)
	{
		if (flags.fwidth > 1)
			n = pf_charspace(flags, format);
		write(1, &c, 1);
	}
	if (flags.left == 1)
	{
		write(1, &c, 1);
		if (flags.fwidth > 1)
			n = pf_charspace(flags, format);
	}
	return (n);
}
