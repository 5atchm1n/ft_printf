/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsetargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:12:57 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/22 04:06:01 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_settype(char *format, signed char c)
{
	int		n;

	if (c = -1)
		return (-1);
	n = ft_flagtrue(c, format);
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

int			ft_setcall(int type, signed char format)
{
	return (0);
}

t_argtype	ft_setarg(t_argtype *arg, va_list args)
{
	t

void		ft_pfsetargs(t_pfdata *arglist, va_list args)
{
	format = FORMAT;

	while (arglist != NULL)
	{
		arglist->arg->type = ft_settype(format, arglist->format);
		arglist->arg->call = ft_setcall(type, arglist->flags);
		arglist->arg->argtype = ft_setarg(&arglist->arg->argtype, args);	
		arglist = arglist->next;
	}

}
