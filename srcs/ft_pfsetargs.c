/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsetargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:12:57 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/31 14:39:41 by sshakya          ###   ########.fr       */
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

void		ft_setwidth(t_pfdata *arglist, va_list args)
{
	int		fwidth;

	if (arglist->flags->asterisk != 0)
	{
		if (arglist->flags->fwidth == 0)


		

void		ft_pfsetargs(t_pfdata *arglist, va_list args)
{
	char	*format;

	format = FORMAT;
	type = ft_settype(format, arglist->format);
	while (arglist != NULL)
	{
		arglist->arg = ft_setarg(&arglist->arg, args);	
		arglist = arglist->next;
	}

}
