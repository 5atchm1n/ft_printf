/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 04:03:47 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/14 22:21:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char			*ft_pfstring(char const *str, size_t len)
{
	size_t			i;
	char			*ret;

	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}


static size_t		ft_pfstrlen(const char *str)
{
	size_t			n;

	n = 1;
	if (*str == '%' && *str)
		str++;
	while (*(str + 1) != '\0' && *(str + 1) != '%')
	{
		n++;
		str++;
	}
	return (n);
}

static char			**ft_pfsettab(const char *str)
{
	size_t			size;
	int				end;
	char			**tab;

	size = 0;
	end = 0;
	while (*str != '\0' && !end)
	{
		if (*str == '%')
		{
			size++;
			str++;
		}
		if (*str == '%')
			str++;
		end = (*str == '\0');
		if (!end)
			str++;
	}
	if (!(tab = malloc(sizeof(char *) * (size + 1))))
		return (tab = NULL);
	tab[size] = NULL;
	return (tab);
}

static size_t		ft_tabsize(const char *str)
{
	size_t			n;

	n = 0;
	while (str && *str != '\0')
	{
		if (*str == '%')
		{
			str++;
			n++;
		}
		if (*str == '%')
			str++;
		if (*str != '\0')
			str++;
	}
	return (n);
}

char				**ft_pfsplit(char const *str)
{
	char			**tab;
	size_t			size;
	size_t			n;
	size_t			len;

	tab = ft_pfsettab(str);
	size = ft_tabsize(str);
	n = 0;
	while (n < size && str)
	{
		while (*str != '\0')
		{
			if (*str == '%')
			{
				len = ft_pfstrlen(str);
				tab[n] = ft_pfstring(str, len);
				n++;
				str++;
			}
			str++;
		}
	}
	return (tab);
}



/*
int main(void)
{
	char **test;
	int i;

	i = 0;
	
	test = ft_pfsplit("%%test1 %a test2%test3");
	if (test == NULL)
	{
		printf("test = NULL");
		return (0);
	}
	
	while (test[i] != NULL)
	{
		printf("tab[%d] = %s\n", i, test[i]);
		free(test[i]);
		i++;
	}
	printf("tab[%d] = %s\n", i, test[i]);
	free(test);
	return (0);
}
*/
