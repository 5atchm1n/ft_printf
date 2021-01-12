/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 22:41:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/12 22:46:58 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_clearlst(t_pfdata *head)
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

void	pf_cleartab(char **tab)
{
	int	n;

	n = 0;
	while(tab[n] != NULL)
	{
		free(tab[n]);
		n++;
	}
	free(tab[n]);
	free(tab);
}
