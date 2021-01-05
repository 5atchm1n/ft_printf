/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:50:53 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/05 04:52:09 by sshakya          ###   ########.fr       */
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
	tmp = FLAGS;
	while (*str && (ft_isdigit(*str) || pf_isflag(*str, tmp) >= 0))
		str++;
	tmp = "cspidux";
	while (*str && pf_isflag(*str, tmp) >= 0)
		str++;
	tmp = str;
	*string = tmp;
	return (*string);
}
