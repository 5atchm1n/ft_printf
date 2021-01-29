# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2021/01/29 03:10:27 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = ft_printf.h

SRCS1 =	ft_printf.c \
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
		srcs/pf_printint_utils_2.c

SRCS2 = srcs/pf_setreturn.c \
		srcs/pf_printuint.c \
		srcs/pf_printint.c

BONUS = bonus/pf_printfloat_bonus.c \
		bonus/pf_setreturn_bonus.c \
		bonus/pf_printuint_bonus.c \
		bonus/pf_printint_bonus.c \
		bonus/pf_convert_f_bonus.c \
		bonus/pf_convert_g_bonus.c \
		bonus/pf_convert_e_bonus.c \
		bonus/pf_float_utils_bonus.c \
		bonus/pf_float_exp_bonus.c \
		bonus/pf_float_utils_2_bonus.c

OBJS1 = ${SRCS1:.c=.o} 

OBJS2 = ${SRCS2:.c=.o}

BONUSOBJS = ${BONUS:.c=.o}

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

MEM = -fsanitize=address

$(NAME) : ${OBJS1} ${OBJS2} ${INCLUDE}
	ar rcs $@ $?

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

clean :
	${RM} ${OBJS1} ${OBJS2} ${BONUSOBJS}

fclean : clean
	${RM} ${NAME}

bonus : ${BONUSOBJS} ${OBJS1} ${INCLUDE}
	ar rcs ${NAME} $?

norm :
	~/.norminette/norminette.rb ${SRCS1} ${SRCS2} ${INCLUDE}

norm-bonus :
	~/.norminette/norminette.rb ${BONUS} ${INCLUDE}

.PHONY : all norm  clean re fclean bonus
