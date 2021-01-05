/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_setargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:12:57 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/05 05:53:24 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			pf_settype(char *format, signed char c)
{
	int				n;

	if (c = -1)
		return (-1);
	n = pf_flagtrue(c, format);
	if (n == 0)
		return (n);
	if (n > 3)
		return (1);
	if (n == 1)
		return (2);
	if (n == 2)
		return (3);
	if (n == 3)
		return (4);
}

static t_arg		pf_setarg(t_arg *arg, int type, va_list args)
{
	double			num;
	char			*string;
	unsigned char	chr;
	void			*ptr;
	
	if(type == 1)
	{
		num = va_arg(args, double);
		*arg.nbr = num;
	}
	if(type == 2)
	{
		chr = (char)va_arg(args, int);
		*arg.ch = chr;
	}
	if(type == 3)
	{
		string = va_arg(args, char *);
		*arg.str = string;
	}
	if(type == 4)
	{
		*ptr = va_arg(args, void *);
		*arg.ptr = *ptr;
	}
	return (*arg);
}

void				pf_setargs(t_pfdata *arglist, va_list args)
{
	char			*format;
	int				type;

	format = FORMAT;
	while (arglist != NULL)
	{
		type = pf_settype(format, arglist->format);
		arglist->arg = pf_setarg(&arglist->arg, type, args);	
		arglist = arglist->next;
	}

}
