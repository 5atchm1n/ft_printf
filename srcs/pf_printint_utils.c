/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printint_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 23:35:43 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/14 00:51:05 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../ft_printf.h"

char		*pf_putflag(char *str, char flag)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = ft_strlen(str);
	ret = malloc(sizeof(char) * (len + 2));
	str[0] = flag;
	while (str[i] != '\0')
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[j++] = '\0';
	return (ret);
}

char		*pf_putwidth(char *str, int width, char flag, char *ret)
{
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (len < width)
	{
		ret[i] = flag;
		i++;
		len++;
	}
	while (i < width)
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	return(ret);
}

char		*pf_putleft(char *str, int width, char flag, char *ret)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	while (i < width)
	{
		ret[i] = flag;
		i++;
	}
	return(ret);
}
