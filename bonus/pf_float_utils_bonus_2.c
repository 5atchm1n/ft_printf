/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float_utils_bonus_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:08 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/06 15:53:33 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		pf_copystr(char *src, char *dest)
{
	size_t		n;

	n = 0;
	while (src[n] != '\0')
	{
		dest[n] = src[n];
		n++;
	}
	free(src);
	return (n);
}

char			*pf_joinfloat(char *s1, char *s2)
{
	char		*str;
	size_t		len;
	size_t		i;
	size_t		j;

	len = pf_strlen(s1) + pf_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = pf_copystr(s1, str);
	j = 0;
	str[i] = '.';
	i++;
	while (s2 && s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s2);
	return (str);
}

char			*pf_joinstr(char *s1, char *s2)
{
	char		*str;
	size_t		len;
	size_t		i;
	size_t		j;

	len = pf_strlen(s1) + pf_strlen(s2) + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = pf_copystr(s1, str);
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s2);
	return (str);
}
