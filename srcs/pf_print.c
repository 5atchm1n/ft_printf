/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:10:58 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/12 23:17:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_print(t_pfdata *arglist, char **strlist)
{
	t_pfdata	*head;

	head = arglist;
	while (arglist != NULL)
	{
		pf_setreturn(*arglist);
		pf_putstr(arglist->str);
		arglist = arglist->next;
	}
	pf_cleartab(strlist);
	pf_clearlst(head);
}
