/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:06:23 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/15 09:12:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

t_flags		ft_setflags(char *str);
{
	t_flags			flags;

	flags = malloc(sizeof(flags));

	flags.left = ft_fleft(str);
	flags.zero = ft_fzero(str);
	flags.fwidth = ft_fwidth(str);
	flags.precision = ft_precision(str);

	return (flags);
}
