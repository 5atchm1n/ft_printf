/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:13:33 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/17 00:53:25 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*pf_revstr(char *str)
{
	int			len;
	int			i;
	int			j;
	char		*ret;

	len = pf_strlen(str);
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

char		*pf_convertbase(uintmax_t num, char *base)
{
	char		*ret;
	int			j;
	uintmax_t	len;

	j = 0;
	len = pf_strlen(base);
	ret = malloc(sizeof(char) * 34);
	while (num >= len)
	{
		ret[j] = base[num % len];
		num = num / len;
		j++;
	}
	ret[j++] = base[num % len];
	ret[j++] = '\0';
	ret = pf_revstr(ret);
	return (ret);
}

char			*pf_convert(uintmax_t number, signed char format)
{
	char		*ret;

	if (format == 'i' || format == 'd')
	{
		ret = pf_convertbase(number, "0123456789");
		return (ret);
	}
	if (format == 'u')
	{
		ret = pf_convertbase(number, "0123456789");
		return (ret);
	}
	if (format == 'x' || format == 'p')
	{
		ret = pf_convertbase(number, "0123456789abcdef");
		return (ret);
	}
	if (format == 'X')
	{
		ret = pf_convertbase(number, "0123456789ABCDEF");
		return (ret);
	}
	return (NULL);
}
