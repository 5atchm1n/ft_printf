/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfsetargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:12:57 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/21 02:37:59 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_settype(char *format, signed char c, t_flags flags)
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

void		ft_pfsetargs(t_pfdata *arglist, va_list args)
{
	int		call;
	int		type;
	char	format;
	format = FORMAT;

	call = 0;
	while (arglist->next != NULL)
	{
		type = ft_settype(format, arglist->format, arglist->flags);
		call = ft_setcall(type, arglist->flags);
		

}
