/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:50:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/21 23:20:40 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char			*pf_setstring(char *str, char **string)
{
	char		*tmp;

	tmp = str;
	if (*tmp == '%')
		tmp++;
	while (*tmp  && (pf_isdigit(*tmp) || pf_isflag(*tmp) > -1))
		tmp++;
	if (*tmp && *tmp == '%')
		return (*string = tmp);
	str++;
	while (*str && (pf_isdigit(*str) || pf_isflag(*str) >= 0))
		str++;
	while (*str && pf_isformat(*str) >= 0)
		str++;
	tmp = str;
	*string = tmp;
	return (*string);
}
