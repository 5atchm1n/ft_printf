/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:04 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/13 00:23:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "# +-0.*"
# define FORMAT "%cspiduxX"

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

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
	uintptr_t			ptr;
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

int						ft_printf(const char *str, ...);
/*
** SPLIT STRING
*/
char					**pf_split(char const *str);
void					pf_cleartab(char **tab);
/*
** CREATE LIST FUNCTIONS
*/
t_pfdata				*pf_setlist(char **strlist, va_list args);
t_arg					pf_setargs(t_arg arg, va_list args, signed char f);
void					pf_flagargs(t_flags *flags, va_list args, char *str);
char					*pf_setstring(char *str, char **string);
t_flags					*pf_setflags(char *str, t_flags *flags, va_list args);
signed char				pf_setformat(char *str, signed char *format);
void					pf_clearlst(t_pfdata *head);
/*
** SET_RETURN UTILS
*/
void					pf_print(t_pfdata *pfdata, char **strlist);
char					*pf_addpwidth(char *str, int pwidth, int start);
void					pf_putstr(char *str);
void					pf_putstrl(char *str, int pwidth);
void					pf_putstrs(char *str, int width, int left);
void					pf_setreturn(t_pfdata pfdata);
/*
** CONVERT UTILS
*/
char					*pf_convert(int number, signed char format,
	t_flags flags);
/*
**FLAG UTILS
*/
int						pf_precision(char *str);
int						pf_asterisk(char *str);
int						pf_pwidth(char *str);
int						pf_fwidth(char *str);
int						pf_flagtrue(char *str, int n);
int						pf_isflag(char c);
int						pf_isformat(char c);
void					pf_flagzero(t_flags *flags);
/*
**libft functions
*/
int						ft_isdigit(int c);
size_t					ft_strlen(const char *s);

#endif
