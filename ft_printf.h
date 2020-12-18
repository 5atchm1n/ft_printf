/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:04 by sshakya           #+#    #+#             */
/*   Updated: 2020/12/18 07:28:04 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_flags
{
	int					left;
	int					zero;
	int					fwidth;
	int					precision;
	int					pwidth;
}						t_flags;

typedef enum			e_format
{
	c = 1,
	s = 2,
	p = 3,
	i = 4,
	d = 5,
	u = 6,
	x = 7,
	end = 0,
}						t_format;

typedef struct			s_pfdata
{
	enum e_format		format;
	t_flags				flags;
	char				*str;
	struct s_pfdata		*head;
	struct s_pfdata		*next;
}						t_pfdata;

char					**ft_pfsplit(char const *str);
t_pfdata				*pfsetlist(char **strlist, va_list args);
t_flags					*ft_setflags(char *str, t_flags *flags);
t_format				ft_setformat(char *str, t_format *format);
int						ft_flagtrue(char *str, char *flags, int n);
int						ft_isdigit(int c);
int						ft_isflag(char c, char *flags);
char					**ft_pfsplit(char const *str);

#endif
