/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 06:02:19 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/07 21:52:35 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			pf_clearlst(t_pfdata *head)
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

void			pf_flagzero(t_flags *flag)
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

int				pf_isflag(char c)
{
	int			n;
	char		*flags;

	flags = FLAGS;

	n = 0;
	while (flags[n] != '\0')
	{
		if (c == flags[n])
			return (n);
		n++;
	}
	return (-1);
}

int				pf_isformat(char c)
{
	int			n;
	char		*format;

	format = FORMAT;

	n = 0;
	while (format[n] != '\0')
	{
		if (c == format[n])
			return (n);
		n++;
	}
	return (-1);
}

int				pf_flagtrue(char *str, int n)
{
	int			i;

	i = 0;
	while (*str != '\0' && i >= 0)
	{
		i = pf_isflag(*str);
		if (i == n)
			return (1);
		str++;
	}
	return (0);
}
