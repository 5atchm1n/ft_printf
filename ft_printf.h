/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:04 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/02 14:48:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "# +-0.*"
# define FORMAT "%cspidux"

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_flags
{
	int					hash;
	int					space;
	int					plus;
	int					left;
	int					zero;
	int					asterisk;
	int					fwidth;
	int					precision;
	int					pwidth;
}						t_flags;

typedef union			u_arg
{
	unsigned char		ch;
	char				*str;
	double				nbr;
	void				*ptr;
}						t_arg;

typedef struct			s_pfdata
{
	signed char			format;
	t_flags				flags;
	char				*str;
	union u_arg			arg;
	struct s_pfdata		*head;
	struct s_pfdata		*next;
}						t_pfdata;

t_pfdata				*ft_pfsetlist(char **strlist);
char					**ft_pfsplit(char const *str);
void					ft_pfsetargs(t_pfdata *arglist, va_list args);

char					*ft_setstring(char *str, char **string);
t_flags					*ft_setflags(char *str, t_flags *flags);
signed char				ft_setformat(char *str, signed char *format);

int						ft_flagtrue(char *str, char *flags, int n);
int						ft_isflag(char c, char *flags);
void					ft_clearlst(t_pfdata *head);
void					ft_flagzero(t_flags *flags);
//libft functions
int						ft_isdigit(int c);
size_t					ft_strlen(const char *s);

#endif
