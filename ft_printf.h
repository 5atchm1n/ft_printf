/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:04 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/18 03:27:08 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct			s_flags
{
	int					left;
	int					zero;
	int					fwidth;
	int					precision;
	int					pwidth;
}						t_flags;

typedef union			u_format
{
	char				c;
	char				*s;
	void				*p;
	int					i;
	int					d;
	unsigned int		u;
	char				*x;
}						t_format;

typedef struct			s_pfdata
{
	union u_format		format;
	t_flags				flags;
	char				*str;
	struct s_pfdata		*head;
	struct s_pfdata		*next;
}						t_pfdata;

char					**ft_pfsplit(char const *str);
t_pfdata				*pfsetlist(char **strlist, va_list args);
t_flags					*ft_setflags(char *str, t_flags *flags);

#endif
