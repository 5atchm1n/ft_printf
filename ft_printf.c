/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:12:55 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/14 22:26:11 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *str)
{
	char	**strlist;
	t_
	size_t	n;

	arglist = ft_pfsplit(str);
	if (arglist[0] == NULL)
		return (ft_putstr_fd(1, str));
	n = 0;
	while (strlist[n] != NULL)
	{
		ft_print(strlist[n]);
		free(strlist[n])
		n++;
	}
	return (0);
}

