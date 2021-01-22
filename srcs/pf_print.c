/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:10:58 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/23 00:04:32 by sshakya          ###   ########.fr       */
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
	size_t		n;

	n = 0;
	while (tab[n] != NULL)
	{
		free(tab[n]);
		n++;
	}
	free(tab);
}

int				pf_print(t_pfdata *arglist, char **strlist, char *str)
{
	t_pfdata	*head;
	int			n;

	head = arglist;
	n = 0;
	while (str[n] != '%') 
	{
		write(1, &str[n], 1);
		n++;
	}
	while (arglist != NULL)
	{
		n += pf_setreturn(arglist);
		if (arglist->format != '%')
			n += pf_putstr(arglist->str);
		arglist = arglist->next;
	}
	pf_cleartab(strlist);
	pf_clearlst(head);
	return (n);
}
