/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:50:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/14 18:19:16 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*pf_setstring(char *str, char **string)
{
	char		*tmp;

	tmp = str;
	if (*tmp == '%')
		tmp++;
	if (*tmp == '%')
		return (str);
	str++;
	while (*str && (ft_isdigit(*str) || pf_isflag(*str) >= 0))
		str++;
	while (*str && pf_isformat(*str) >= 0)
		str++;
	tmp = str;
	*string = tmp;
	return (*string);
}
