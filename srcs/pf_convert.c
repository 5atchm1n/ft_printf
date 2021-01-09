/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:13:33 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/08 21:12:23 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*pf_convertbase(int num, t_flags flags, char *base, int n)
{
	char		*ret;
	int			i;
	int			j;
	int			len;

	j = 0;
	len = ft_strlen(base);
	ret = malloc(sizeof(char) * 34);
	while (num >= len)
	{
		i = num % len;
		ret[j] = base[i];
		num = num / len;
		j++;
	}
	ret[j] = base[num % len];
	if (n == 1)
	{
		if ((flags.space == 1 && flags.plus == 1) || flags.plus == 1)
			ret[j++] = '+';
		if (flags.space == 1)
			ret[j++] = ' ';
	}
	ret[j++] = '\0';
	return (ret);
}

static char		*pf_revstr(char *str)
{
	int			len;
	int			i;
	int			j;
	char		*ret;

	len = ft_strlen(str);
	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	j = len - 1;
	while (i < len)
	{
		ret[i] = str[j];
		i++;
		j--;
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}

char			*pf_convert(int number, signed char format, t_flags flags)
{
	char		*ret;

	if (format == 'i' || format == 'd')
	{
		ret = pf_convertbase(number, flags, "0123456789", 1);
		ret = pf_revstr(ret);
		return (ret);
	}
	if (format == 'u')
	{
		ret = pf_convertbase(number, flags, "0123456789", 0);
		ret = pf_revstr(ret);
		return (ret);
	}
	if (format == 'x')
	{
		ret = pf_convertbase(number, flags, "0123456789abcdef", 0);
		ret = pf_revstr(ret);
		return (ret);
	}
	if (format == 'X')
	{
		ret = pf_convertbase(number, flags, "0123456789ABCDEF", 0);
		ret = pf_revstr(ret);
		return (ret);
	}
	return (NULL);
}
