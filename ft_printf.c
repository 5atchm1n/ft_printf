/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:12:55 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/20 22:00:16 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	char		**strlist;
	t_pfdata	*arglist;
	va_list		args;

	strlist = pf_split(str);
	if (strlist[0] == NULL)
	{
		pf_putstr((char *)str);
		free(strlist);
		return (0);
	}
	va_start(args, str);
	arglist = pf_setlist(strlist, args);
	va_end(args);
	pf_print(arglist, strlist, (char *)str);
	return (0);
}
