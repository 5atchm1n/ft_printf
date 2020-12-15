/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsetlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:13:30 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/15 06:54:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static t_flags		ft_setflags(char *str);
{
	t_flags			flags;

	flags = malloc(sizeof(flags));

	flags.left = ft_fleft(str);
	flags.zero = ft_fzero(str);
	flags.fwidth = ft_fwidth(str);
	flags.precision = ft_precision(str);

	return (flags);
}

static t_pfdata	*ft_pfsethead(t_pfdata *pfdata, char *str)
{
	pfdata = malloc(sizeof(t_pfdata));
	pfdata->arg = ft_setargs(str);
	pfdata->flags = ft_setflags(str);
	pfdata->str = ft_setstring(str);
	pfdata->head = pfdata;
	pfdata->next = NULL;
	return (pfdata);
}

static t_pfdata		*ft_pfsetelem(t_pfdata *pfdata, char *str)
{
	pfdata->next = malloc(sizeof(t_pfdata));
	pfdata->next->arg = ft_setargs(str);
	pfdata->next->flags = ft_setflags(str)
	pfdata->next->str = ft_setstring(str);
	pfdata->next->head = pfdata->head;
	pfdata->next->next = NULL;
	return (pfdata);
}

t_pfdata			*ft_pfsetlist(char **strlist, va_list args)
{
	t_pfdata		*arglist;
	size_t			n;

	n = 0;
	arglist = ft_pfsethead(arglist, strlist[n]);
	while (strlist[n] != NULL)
	{
		ft_pfsetelem(arglist, strlist[n]);
		arglist = arglist->next;
		n++;
	} 
	return (arglist->head);	
}
