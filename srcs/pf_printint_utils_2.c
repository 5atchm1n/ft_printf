/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printint_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 22:54:05 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/28 23:13:35 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_prepend(char *dest, int width, int len, char c)
{
	int		n;

	n = 0;
	while (len < width)
	{
		dest[n] = c;
		n++;
		len++;
	}
	return (n);
}
