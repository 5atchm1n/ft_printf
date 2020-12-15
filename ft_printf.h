/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:04 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/15 07:01:51 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

#include <stdarg.h>
#include "libft.h"

typedef struct		s_flags
{
	int				left;
	int				zero;
	int				fwidth;
	int				precision;
}					t_flags;

typedef struct		s_pfdata
{
	int				arg;
	t_flags			flags;
	char			*str;
	s_pfdata		*head;
	s_pfdata		*next;
}					t_pfdata;

int					ft_pfsplit(char const *str);
*t_pfdata			*pfsetlist(char **strlist, va_list args);

#endif
