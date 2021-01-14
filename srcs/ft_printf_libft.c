/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 05:54:07 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/14 18:35:33 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
	return ;
}

void		ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	return ;
}

int			ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return(0);
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
