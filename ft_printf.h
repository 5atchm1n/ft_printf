/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:04 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/07 21:19:18 by sshakya          ###   ########.fr       */
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
	int					nbr;
}						t_arg;

typedef struct			s_pfdata
{
	signed char			format;
	t_flags				flags;
	char				*str;
	union u_arg			arg;
	char				*ret;
	struct s_pfdata		*head;
	struct s_pfdata		*next;
}						t_pfdata;

//t_pfdata				*pf_setlist(char **strlist, va_list args);
t_pfdata				*pf_setlist(char **strlist, ...);
char					**pf_split(char const *str);
t_arg					pf_setargs(t_arg arg, va_list args, signed char f);
char					*pf_setstring(char *str, char **string);
t_flags					*pf_setflags(char *str, t_flags *flags, va_list args);
signed char				pf_setformat(char *str, signed char *format);
void					pf_flagargs(t_flags *flags, va_list args, char *str);

int						pf_precision(char *str, char *flags);
int						pf_asterisk(char *str, char *flags);
int						pf_pwidth(char *str, char *flags);
int						pf_fwidth(char *str, char *flags);
int						pf_flagtrue(char *str, char *flags, int n);
int						pf_isflag(char c, char *flags);
void					pf_clearlst(t_pfdata *head);
void					pf_flagzero(t_flags *flags);
//libft functions
int						ft_isdigit(int c);
size_t					ft_strlen(const char *s);

#endif
