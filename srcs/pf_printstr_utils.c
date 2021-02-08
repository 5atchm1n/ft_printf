/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printstr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:52:11 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/08 02:47:32 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_write_space(int size)
{
	int		n;
	int		err;
	char	c;

	n = 0;
	c = ' ';
	while (n < size)
	{
		err = write(1, &c, 1);
		if (err == -1)
			return (err);
		n++;
	}
	return (n);
}

int			pf_write_preci(char *str, int pwidth)
{
	int		n;
	int		err;
	int		len;
	char	*ret;

	n = 0;
	ret = str;
	len = pf_strlen(str);
	if (pwidth <= 0)
		return (0);
	if (len > pwidth && str != NULL)
	{
		err = write(1, ret, pwidth);
		if (err == -1)
			return (err);
		return (pwidth);
	}
	err = write(1, ret, len);
	if (err == -1)
		len = err;
	return (len);
}

int			pf_write_fwidth_l(char *str, int fwidth)
{
	int		len;
	int		n;
	char	*ret;
	int		err;

	n = 0;
	len = pf_strlen(str);
	ret = str;
	err = write(1, ret, len);
	if (err == -1)
		return (-1);
	if (fwidth >= 0)
	{
		err = n;
		n += pf_write_space(fwidth - len);
		if (n < err)
			return (-1);
	}
	return (len + n);
}

int			pf_write_fwidth_r(char *str, int fwidth)
{
	int		len;
	int		n;
	char	*ret;
	int		err;

	n = 0;
	len = pf_strlen(str);
	ret = str;
	if (fwidth >= 0)
	{
		n = pf_write_space(fwidth - len);
		if (n == -1)
			return (-1);
	}
	err = write(1, ret, len);
	if (err == -1)
		return (err);
	return (n + len);
}
