/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:25:27 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/08 02:57:00 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		pf_charspace(t_flags flags, signed char format)
{
	char		c;
	int			n;
	int			err;

	c = ' ';
	n = 1;
	if ((flags.zero == 1 || flags.precision == 1) && format == '%'
			&& flags.left == 0)
		c = '0';
	while (flags.fwidth > n)
	{
		err = write(1, &c, 1);
		if (err == -1)
			return (-1);
		n++;
	}
	return (n);
}

static int		pf_char_right(char c, t_flags flags, signed char format)
{
	int			n;
	int			err;

	n = 0;
	if (flags.fwidth > 1)
	{
		n = pf_charspace(flags, format);
		if (n == -1)
			return (-1);
	}
	err = write(1, &c, 1);
	if (err == -1)
		return (-1);
	return (n);
}

static int		pf_char_left(char c, t_flags flags, signed char format)
{
	int			n;
	int			err;

	n = 0;
	err = write(1, &c, 1);
	if (err == -1)
		return (-1);
	if (flags.fwidth > 1)
	{
		n = pf_charspace(flags, format);
		if (n == -1)
			return (-1);
	}
	return (n);
}

int				pf_printchar(char c, t_flags flags, signed char format)
{
	int			n;

	n = 1;
	if (flags.left == 0)
	{
		n = pf_char_right(c, flags, format);
		if (n == -1)
			return (-1);
	}
	if (flags.left == 1)
	{
		n = pf_char_left(c, flags, format);
		if (n == -1)
			return (-1);
	}
	return (n);
}
