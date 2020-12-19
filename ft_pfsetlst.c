/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsetlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:13:30 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/18 23:47:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_pfdata		*ft_pfsethead(t_pfdata *pfdata, char *str)
{
	pfdata = malloc(sizeof(t_pfdata));
	pfdata->format = *ft_setformat(str, &pfdata->format);
	pfdata->flags = *ft_setflags(str, &pfdata->flags);
	pfdata->str = ft_setstring(str);
	pfdata->head = pfdata;
	pfdata->next = NULL;
	return (pfdata);
}

static t_pfdata		*ft_pfsetelem(t_pfdata *pfdata, char *str)
{
	pfdata->next = malloc(sizeof(t_pfdata));
	pfdata->next->format = *ft_setformat(str, &pfdata->next->format);
	pfdata->next->flags = *ft_setflags(str, &pfdata->next->flags);
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
	arglist = NULL;
	arglist = ft_pfsethead(arglist, strlist[n]);
	while (strlist[n] != NULL)
	{
		ft_pfsetelem(arglist, strlist[n]);
		arglist = arglist->next;
		n++;
	}
	return (arglist->head);
}
