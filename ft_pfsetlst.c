/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsetlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 22:13:30 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/15 01:00:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_flags		ft_setflags(char *str);
{
	t_flags			flags;

	flags = malloc(sizeof(flags));

	flags.left = ft_fleft(string);
	flags.zero = ft_fzero(string);
	flags.fwidth = ft_fwidth(string);
	flags.precision = ft_precision(string);

	return (flags);
}

static *t_pfdata	ft_pfsethead(t_pfdata pfdata, char *string)
{
	pfdata = malloc(sizeof(t_pfdata));
	pfdata->arg = 0;
	pfdata->flags = ft_setflags(string);
	pfdata->str = string;
	pfdata->head = pfdata;
	pfdata->next = NULL;
	return (pfdata);
}

static *t_pfdata	ft_pfsetelem(t_pfdata pfdata, char *string)
{
	pfdata->next = malloc(sizeof(t_pfdata));
	pfdata->next->arg = 0;
	pfdata->next->flags = ft_setflags(string)
	pfdata->next->str = string;
	pfdata->next->head = pfdata->head;
	pfdata->next->next = NULL;
	return (pfdata);
}


static t_pfdata		*ft_pfsetlist(char **strlist, va_list args)
{
	t_pfdata		*arglist;
	size_t			n;

	n = 0;
	arglist = ft_pfsethead(arglist, strlist[n]);
	while (strlist[n] != NULL)
	{
		ft_pfsetelem(arglist, strlist[n]);
		n++;
	}
	return (arglist->head);	
}
