/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/19 03:18:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		pf_setfzero(char **str, int *exp, int *pwidth)
{
	int			i;

	i = 0;
	if (*pwidth == -1)
		*pwidth = 6;
	while (*exp < -1)
	{
		(*str)[i] = '0';
		(*exp)++;
		(*pwidth)--;
		i++;
	}
	(*str)[i] = '\0';
	return (i);
}

char			*pf_addpow(char *str, int exp, int pwidth)
{
	char		*ret;
	int			i;
	int			j;
	int			len;

	j = 0;
	len = pf_strlen(str);
	ret = malloc(sizeof(char) * (len + (exp * -1)));
	if (ret == NULL)
		return (NULL);
	i = pf_setfzero(&ret, &exp, &pwidth);
	if (pwidth == -1)
		pwidth = 6;
	while (len && pwidth > 0)
	{
		ret[i] = str[j];
		i++;
		j++;
		len--;
		pwidth--;
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}
