/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 09:06:23 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/05 07:01:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	pf_fwidth(char *str, char *flags)
{
	int		i;

	i = 0;
	while (*str && i >= 0)
	{
		i = pf_isflag(*str, flags);
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

static int	pf_pwidth(char *str, char *flags)
{
	int		i;

	i = 0;
	while (*str && i != 2)
	{
		i = pf_isflag(*str, flags);
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

static int	pf_asterisk(char *str, char *flags)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (*str != '\0' && i >= 0)
	{
		i = pf_isflag(*str, flags);
		if (i == 6)
			n = n + 1;
		if (i < 0 && ft_isdigit(*str) == 1)
			i = 1;
		str++;
	}
	return (n);
}

static int	pf_precision(char *str, char *flags)
{
	int		i;

	i = 1;
	while (*str != '\0' && i >= 0)
	{
		i = pf_isflag(*str, flags);
		if (i == 5)
			return (1);
		if (i < 0 && ft_isdigit(*str) == 1)
			i = 1;
		str++;
	}
	return (0);
}

t_flags		*pf_setflags(char *str, t_flags *flag, va_list args)
{
	char	*flags;

	flags = FLAGS;
	str++;
	if (!flag)
		return (NULL);
	if (pf_isflag(*str, flags) == 0)
	{	
		pf_flagzero(flag);
		return (flag);
	}
	flag->hash = pf_flagtrue(str, flags, 0);
	flag->space = pf_flagtrue(str, flags, 1);
	flag->plus = pf_flagtrue(str, flags, 2);
	flag->left = pf_flagtrue(str, flags, 3);
	flag->zero = pf_flagtrue(str, flags, 4);
	flag->fwidth = pf_fwidth(str, flags);
	flag->asterisk = pf_asterisk(str, flags);
	flag->precision = pf_precision(str, flags);
	if (flag->precision == 1)
		flag->pwidth = pf_pwidth(str, flags);
	else
		flag->pwidth = 0;
	if (flag->asterisk != 0)
		pf_flagargs(flag, args, str);
	return (flag);
}
