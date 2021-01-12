/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:13:30 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/12 23:06:31 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static t_pfdata		*pf_sethead(t_pfdata *pfdata, char *str, va_list args)
{
	pfdata = malloc(sizeof(t_pfdata));
	pfdata->format = pf_setformat(str, &pfdata->format);
	pfdata->flags = *pf_setflags(str, &pfdata->flags, args);
	pfdata->str = pf_setstring(str, &pfdata->str);
	pfdata->arg = pf_setargs(pfdata->arg, args, pfdata->format);
	pfdata->head = pfdata;
	pfdata->next = NULL;
	return (pfdata);
}

static t_pfdata		*pf_setelem(t_pfdata *pfdata, char *str, va_list args)
{
	pfdata->next = malloc(sizeof(t_pfdata));
	pfdata->next->format = pf_setformat(str, &pfdata->next->format);
	pfdata->next->flags = *pf_setflags(str, &pfdata->next->flags, args);
	pfdata->next->str = pf_setstring(str, &pfdata->next->str);
	pfdata->next->arg = pf_setargs(pfdata->arg, args, pfdata->format);
	pfdata->next->head = pfdata->head;
	pfdata->next->next = NULL;
	return (pfdata);
}

t_pfdata			*pf_setlist(char **strlist, va_list args)
{
	t_pfdata		*arglist;
	size_t			n;

	n = 1;
	arglist = NULL;
	arglist = pf_sethead(arglist, strlist[0], args);
	while (strlist[n] != NULL)
	{
		pf_setelem(arglist, strlist[n], args);
		arglist = arglist->next;
		n++;
	}
	return (arglist->head);
}
