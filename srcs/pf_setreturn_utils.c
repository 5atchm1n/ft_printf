/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setreturn_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:34:29 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/13 00:29:14 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		pf_putstr(char *str)
{
	int		l;

	l = ft_strlen(str);
	write (1, str, l);

}

void		pf_putstrl(char *str, int pwidth)
{
	int		l;
	l = ft_strlen(str);
	if (l > pwidth)
		write (1, str, pwidth);
	else 
		write (1 , str, l);
}

void		pf_putstrs(char *str, int width, int left)
{
	int		l;

	l = ft_strlen(str);
	if (l > width)
		write(1 ,str, l);
	else
	{
		if (left)
		{
			write (1, str, l);
			while (l < width)
			{
				write(1, " ", 1);
				l++;
			}
		}
		else
		{
			while (l < width)
			{
				write(1, " ", 1);
				width--;
			}
			write(1, str, l);
		}
	}
}

char		*pf_addpwidth(char *str, int pwidth, int start)
{
	int		l;
	int		i;
	char	*ret;

	l = ft_strlen(str);
	i = 0;
	ret = malloc(sizeof(char) * (pwidth + 3));
	while (i < start)
	{
		ret[i] = str[i];
		i++;
	}
	while (l - start < pwidth)
	{
		ret[i] = '0';
		i++;
	}
	while (l - 2 > 0)
	{
		ret[i] = str[i + 2];
		i++;
		l--;
	}
	ret[i] = '\0';
	free(str);
	return (ret);
}
