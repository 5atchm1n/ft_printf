/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:10:58 by sshakya           #+#    #+#             */
/*   Updated: 2021/02/08 03:20:22 by sshakya          ###   ########.fr       */
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

static int		pf_error(char **strlist, t_pfdata *arglist)
{
	pf_cleartab(strlist);
	pf_clearlst(arglist->head);
	return (-1);
}

static int		pf_print_str(char *str)
{
	int			n;
	int			err;

	n = 0;
	while (str[n] != '%')
	{
		err = write(1, &str[n], 1);
		if (err == -1)
			return (-1);
		n++;
	}
	return (n);
}

int				pf_print(t_pfdata *arglist, char **strlist, char *str)
{
	t_pfdata	*head;
	int			n;
	int			err;

	head = arglist;
	n = pf_print_str(str);
	if (n == -1)
		return (-1);
	while (arglist != NULL)
	{
		err = n;
		n += pf_setreturn(arglist);
		if (n < err)
			return (pf_error(strlist, arglist));
		err = n;
		n += pf_putstr_2(arglist->str);
		if (n < err)
			return (pf_error(strlist, arglist));
		arglist = arglist->next;
	}
	pf_cleartab(strlist);
	pf_clearlst(head);
	return (n);
}
