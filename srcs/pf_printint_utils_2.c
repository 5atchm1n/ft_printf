/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printint_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:54:05 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/02 05:10:53 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_prepend(char *dest, int width, int len, char c)
{
	int		n;

	n = 0;
	while (len < width)
	{
		dest[n] = c;
		n++;
		len++;
	}
	return (n);
}

char		*pf_putzero(char *str, int width)
{
	int		len;
	int		i;
	int		j;
	char	*ret;

	len = pf_strlen(str);
	i = 0;
	j = 0;
	if (width == -1 || width < len)
		width = len;
	ret = malloc(sizeof(char) * (width + 1));
	i = pf_prepend(ret, width, len, '0');
	while (i < width)
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[width] = '\0';
	free(str);
	return (ret);
}

char		*pf_putzero_u(char *str, t_flags flags, signed char format)
{
	int		len;
	int		i;
	int		j;
	char	*ret;
	int		width;

	len = pf_strlen(str);
	i = 0;
	j = 0;
	width = flags.fwidth;
	if (flags.fwidth == -1 || flags.fwidth < len)
		width = len;
	else if (flags.hash == 1 && (format == 'x' || format == 'X'))
		width = flags.fwidth - 2;
	ret = malloc(sizeof(char) * (width + 1));
	i = pf_prepend(ret, width, len, '0');
	while (i < width)
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[width] = '\0';
	free(str);
	return (ret);
}
