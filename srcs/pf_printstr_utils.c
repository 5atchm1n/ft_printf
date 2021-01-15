/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printstr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:52:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/15 01:16:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_putstr_wl(char *str, int pwidth, int fwidth, int left)
{
	int		len;

	len = pf_strlen(str);
	if (len > pwidth && fwidth > pwidth && left == 1)
	{
		write(1, str, pwidth);
		while (pwidth < fwidth)
		{
			write(1, " ", 1);
			pwidth++;
		}
		return (fwidth);
	}
	return (0);
}

int			pf_putstr_w(char *str, int pwidth, int fwidth, int left)
{
	int		len;
	int		n;
	int		i;

	len = pf_strlen(str);
	n = 0;
	i = fwidth - pwidth;
	if (len > pwidth && fwidth > pwidth && left == 0)
	{
		while (n < i)
		{
			write(1, " ", 1);
			n++;
		}
		write(1, str, pwidth);
		return (fwidth + pwidth);
	}
	return (0);
}
