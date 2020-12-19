/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:50:53 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/19 03:34:31 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_setstring(char *str, char **string)
{
	char		*tmp;

	tmp = str;
	if (*tmp == '%')
		tmp++;
	if (*tmp == '%')
		return (str);
	str++;
	tmp = "-0.*";
	while (*str && (ft_isdigit(*str) || ft_isflag(*str, tmp) >= 0))
		str++;
	tmp = "cspidux";
	while (*str && ft_isflag(*str, tmp) >= 0)
		str++;
	tmp = str;
	*string = ft_strdup(tmp);
	return (*string);
}