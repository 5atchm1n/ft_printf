/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printstr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:52:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/23 02:02:49 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_write_space(int size)
{
	int		n;
	char	c;

	n = 0;
	c = ' ';
	while (n < size)
	{
		write(1, &c, 1);
		n++;
	}
	return (n);
}

int			pf_write_preci(char *str, int pwidth)
{
	int		n;
	int		len;
	char	*ret;

	n = 0;
	ret = str;
	len = pf_strlen(str);
	if (pwidth <= 0)
		return (0);
	if (len > pwidth && str != NULL)
	{
		write(1, ret, pwidth);
		return (pwidth);
	}
	write(1, ret, len);
	return (len);
}

int			pf_write_fwidth_l(char *str, int fwidth)
{
	int		len;
	int		n;
	char	*ret;

	n = 0;
	len = pf_strlen(str);
	ret = str;
	write(1, ret, len);
	if (fwidth >= 0)
		n += pf_write_space(fwidth - len);
	return (len + n);
}

int			pf_write_fwidth_r(char *str, int fwidth)
{
	int		len;
	int		n;
	char	*ret;

	n = 0;
	len = pf_strlen(str);
	ret = str;
	if (fwidth >= 0)
		n += pf_write_space(fwidth - len);
	write(1, ret, len);
	return (n + len);
}
