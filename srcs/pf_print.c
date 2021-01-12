/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:10:58 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/12 14:08:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pf_print(t_pfdata *pfdata)
{
	while (pfdata != NULL)
	{
		pf_setreturn(*pfdata);
		pf_putstr(pfdata->str);
		pfdata = pfdata->next;
	}
}
