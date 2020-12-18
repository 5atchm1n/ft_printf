/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:06:23 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/18 04:18:02 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c);

static int	ft_isflag(char c, char *flags)
{
	int		n;

	n = 0;
	if (c == '%')
		return (-2);
	while (flags[n] != '\0')
	{
		if (c == flags[n])
			return (n);
		n++;
	}
	return (-1);
}

static int	ft_fleft(char *str, char *flags)
{
	int		i;

	i = 0;
	while (*str != '\0' && i >= 0)
	{
		i = ft_isflag(*str, flags);
		if (i == 0)
			return (1);
		str++;
	}
	return (0);
}

static int	ft_fzero(char *str, char *flags)
{
	int		i;

	i = 0;
	while (*str != '\0' && i >= 0)
	{
		i = ft_isflag(*str, flags);
		if (i == 1)
			return (1);
		str++;
	}
	return (0);
}

static int	ft_fwidth(char *str, char *flags)
{
	int		i;

	i = 0;
	while (*str && i >= 0)
	{
		i = ft_isflag(*str, flags);
		if (i < 0)
			break ;
		str++;
	}
	if (ft_isdigit(*str))
	{
		i = 0;
		while (*str)
		{
			if (ft_isdigit(*str))
				i = i * 10 + ((*str) - '0');
			str++;
			if (!(ft_isdigit(*str)))
				return (i);
		}
	}
	return (0);
}

static int	ft_precision(char *str, char *flags)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		i = ft_isflag(*str, flags);
		if (i == 2)
			return (1);
		if (ft_isflag(*str, flags) < 0 && ft_isdigit(*str) == 1)
			i = 0;
		str++;
	}
	return (0);
}

static int	ft_pwidth(char *str, char *flags)
{
	int		i;

	i = 0;
	while (*str && i != 2)
	{
		i = ft_isflag(*str, flags);
		str++;
	}
	if (ft_isdigit(*str))
	{
		i = 0;
		while (*str)
		{
			if (ft_isdigit(*str))
				i = i * 10 + ((*str) - '0');
			str++;
			if (!(ft_isdigit(*str)))
				return (i);
		}
	}
	return (6);
}

t_flags		*ft_setflags(char *str, t_flags *flag)
{
	char	*flags;

	flags = "-0.*";
	str++;
	flag = malloc(sizeof(t_flags));
	if (!flag)
		return (NULL);
	if (ft_isflag(*str, flags) == -2)
	{
		flag->left = 0;
		flag->zero = 0;
		flag->fwidth = 0;
		flag->precision = 0;
		flag->pwidth = 0;
	}
	flag->left = ft_fleft(str, flags);
	flag->zero = ft_fzero(str, flags);
	flag->fwidth = ft_fwidth(str, flags);
	flag->precision = ft_precision(str, flags);
	flag->pwidth = ft_pwidth(str, flags);
	return (flag);
}
