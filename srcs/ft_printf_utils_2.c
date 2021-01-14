/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:08:14 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/13 15:08:34 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			pf_putstr(char *str)
{
	int		l;

	l = ft_strlen(str);
	write (1, str, l);
	return (l);
}
