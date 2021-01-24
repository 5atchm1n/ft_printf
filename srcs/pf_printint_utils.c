/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printint_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 23:35:43 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/25 00:53:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*pf_putfwidth(char *str, int width, int left)
{
	char	*ret;

	ret = NULL;
	if (left == 0)
		ret = pf_putspace(str, width);
	if (left == 1)
		ret = pf_putleft(str, width);
	return (ret);
}

char		*pf_putflag(char *str, char flag)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	i = 1;
	j = 0;
	len = pf_strlen(str);
	ret = malloc(sizeof(char) * (len + 2));
	ret[0] = flag;
	while (str[j] != '\0')
	{
		ret[i] = str[j];
		i++;
		j++;
	}
	ret[i++] = '\0';
	free(str);
	return (ret);
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
	while (len < width)
	{
		ret[i] = '0';
		i++;
		len++;
	}
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

char		*pf_putspace(char *str, int width)
{
	int		len;
	int		i;
	int		j;
	char	*ret;

	len = pf_strlen(str);
	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * (width + 1));
	while (len < width)
	{
		ret[i] = ' ';
		i++;
		len++;
	}
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

char		*pf_putleft(char *str, int width)
{
	int		len;
	int		i;
	char	*ret;

	len = pf_strlen(str);
	i = 0;
	ret = malloc(sizeof(char) * (width + 1));
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	while (i < width)
	{
		ret[i] = ' ';
		i++;
	}
	ret[width] = '\0';
	free(str);
	return (ret);
}
