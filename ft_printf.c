/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:12:55 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/20 16:11:32 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	char		**strlist;
	t_pfdata	*arglist;
	va_list		args;

	strlist = ft_pfsplit(str);
	if (strlist[0] == NULL)
		return (ft_putstr_fd(1, str));
	
//	va_start(args, str);
	arglist = ft_pfsetlist(strlist, args)
//	va_end(args);

	while (arglist->next != NULL)
	{
		ft_print(arglist->str);
		free(arglist->str);
	}
	ft_print(arglist->str);
	free(arglist->str);
	return (0);
}
