/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:13:33 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/06 11:53:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*pf_convert(int number, signed char format, t_flags flags)
{
	char	*hex;
	char	*HEX;
	char	*decimal;
	char	*ret;

	if (format == 'i')
	{
		pf_convertbase(number, flags);
		return (ret);
	}
	if (format == 'd')
	{
		pf_convertbase(number, flags);
		return (ret);
	}
	if (format == 'u')
	{
		pf_convertbase(number, flags);
		return (ret);
	}

