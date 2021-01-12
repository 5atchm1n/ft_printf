/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:10:58 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/11 17:17:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_print(t_pfdata *pfdata);
{
	pfdata = pfdata->head;
	while (arglist != NULL)
	{
		pf_setreturn(pfdata);
		pfdata = pfdata->next;
	}
}
