# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2021/02/09 02:58:49 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = ft_printf.h

SRCS =	ft_printf.c \
		srcs/pf_split.c \
		srcs/pf_split_utils.c \
		srcs/pf_setlst.c \
		srcs/ft_printf_utils.c \
		srcs/ft_printf_utils_2.c \
		srcs/pf_flag_utils.c \
		srcs/pf_setflags.c \
		srcs/pf_setformat.c \
		srcs/pf_setstring.c \
		srcs/pf_flagargs.c \
		srcs/pf_setargs.c \
		srcs/pf_convert.c \
		srcs/pf_printstr.c \
		srcs/pf_printchar.c \
		srcs/pf_printstr_utils.c \
		srcs/pf_print.c \
		srcs/pf_printint_utils.c \
		srcs/pf_printint_utils_2.c \
		srcs/pf_setreturn.c \
		srcs/pf_printuint.c \
		srcs/pf_printint.c

BONUS = bonus/pf_printfloat_bonus.c \
		bonus/pf_convertfloat_fg_bonus.c \
		bonus/pf_convertfloat_eg_bonus.c \
		bonus/pf_convert_f_bonus.c \
		bonus/pf_convert_g_bonus.c \
		bonus/pf_convert_e_bonus.c \
		bonus/pf_float_utils_bonus.c \
		bonus/pf_float_utils_bonus_2.c \
		bonus/pf_float_exp_bonus.c \
		bonus/pf_float_utils_2_bonus.c

OBJS = ${SRCS:.c=.o} 


BONUSOBJS = ${BONUS:.c=.o}

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

MEM = -fsanitize=address

$(NAME) : ${OBJS} ${BONUSOBJS} ${INCLUDE}
	ar rcs $@ $?

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

clean :
	${RM} ${OBJS} ${BONUSOBJS}

fclean : clean
	${RM} ${NAME}

bonus : all

norm :
	~/.norminette/norminette.rb ${SRCS} ${INCLUDE}

norm-bonus :
	~/.norminette/norminette.rb ${BONUS} ${INCLUDE}

.PHONY : all norm  clean re fclean bonus
