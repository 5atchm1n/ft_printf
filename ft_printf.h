/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:13:04 by sshakya           #+#    #+#             */
/*   Updated: 2021/01/18 01:52:04 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "# +-0.*"
# define FORMAT "%cspiduxXfge"

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
	intmax_t			nbr;
	uintmax_t			unbr;
	intptr_t			ptr;
	double				dbl;
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
/*
** CREATE LIST FUNCTIONS
*/
t_pfdata				*pf_setlist(char **strlist, va_list args);
t_arg					pf_setargs(t_arg arg, va_list args, signed char f);
void					pf_flagargs(t_flags *flags, va_list args, char *str);
char					*pf_setstring(char *str, char **string);
t_flags					*pf_setflags(char *str, t_flags *flags, va_list args);
signed char				pf_setformat(char *str, signed char *format);
/*
** PRINTF RETURN FUNCTIONS
*/
int						pf_print(t_pfdata *pfdata, char **strlist, char *str);
int						pf_putstr(char *str);
int						pf_setreturn(t_pfdata *pfdata);
int						pf_putchar(char c);
int						pf_printstr(char *str, t_flags flags);
int						pf_printint(intmax_t num, t_flags flags,
		signed char format);
int						pf_printuint(uintmax_t num, t_flags flags,
		signed char format);

int						pf_printfloat(double number, t_flags flags,
		signed char format);
char					*pf_putflag(char *str, char flag);
char					*pf_putzero(char *str, int width);
char					*pf_putspace(char *str, int width);
char					*pf_putleft(char *str, int width);
char					*pf_putfwidth(char *str, int width, int left);
/*
** CONVERT INT, UINT, DOUBLE UTILS
*/
char					*pf_convert(uintmax_t number, signed char format);
char					*pf_revstr(char *str);
char					*pf_convertbase(uintmax_t num, char *base);
char					*pf_joinfloat(char *s1, char *s2);
char					*pf_joinstr(char *s1, char *s2);
char					*pf_convertfloat(double number, int pwidth);
double					pf_isnegdouble(double num, int *neg);
char					*pf_convertexp(double number, int pwidth);
double					pf_exp(double pow, int *exp);
double					pf_pow(double pow, int pwidth);
char					*pf_addexp(char *str, int exp);
char					*pf_addpow(char *str, int exp, int pwidth);
/*
** PARSE FORMAT STRING - FLAG UTILS
*/
int						pf_precision(char *str);
int						pf_asterisk(char *str);
int						pf_pwidth(char *str);
int						pf_fwidth(char *str);
int						pf_flagtrue(char *str, int n);
int						pf_isflag(char c);
int						pf_isformat(char c);
void					pf_flagzero(t_flags *flags);

int						pf_isdigit(int c);
int						pf_strlen(char *s);
int						pf_isneg(int *exp);
int						pf_putstr_wl(char *str, int pwidth, int fwidth,
		int left);
int						pf_putstr_w(char *str, int pwidth, int fwidth,
		int left);

#endif
