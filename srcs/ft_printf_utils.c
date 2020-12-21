/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:02:19 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/21 01:50:42 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			ft_clearlst(t_pfdata *head)
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

void		ft_flagzero(t_flags *flag)
{
		flag->hash = 0;
		flag->left = 0;
		flag->zero = 0;
		flag->asterisk = 0;
		flag->fwidth = 0;
		flag->precision = 0;
		flag->pwidth = 0;

		return ;
}

int			ft_isflag(char c, char *flags)
{
	int		n;

	n = 0;
	while (flags[n] != '\0')
	{
		if (c == flags[n])
			return (n);
		n++;
	}
	return (-1);
}

int			ft_flagtrue(char *str, char *flags, int n)
{
	int		i;

	i = 0;
	while (*str != '\0' && i >= 0)
	{
		i = ft_isflag(*str, flags);
		if (i == n)
			return (1);
		str++;
	}
	return (0);
}
