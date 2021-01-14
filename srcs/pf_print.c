/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:10:58 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/14 00:06:11 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		pf_clearlst(t_pfdata *head)
{
	t_pfdata	*lst;
	t_pfdata	*tmp;

	lst = head;
	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

static void		pf_cleartab(char **tab)
{
	int			n;

	n = 0;
	while(tab[n] != NULL)
	{
		free(tab[n]);
		n++;
	}
	free(tab[n]);
	free(tab);
}

int				pf_print(t_pfdata *arglist, char **strlist)
{
	t_pfdata	*head;
	int			n;

	head = arglist;
	n = 0;
	while (arglist != NULL)
	{
		n += pf_setreturn(*arglist);
		n += pf_putstr(arglist->str);
		arglist = arglist->next;
	}
	pf_cleartab(strlist);
	pf_clearlst(head);
	return (n);
}
