# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2021/01/27 22:03:43 by sshakya          ###   ########.fr        #
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
		srcs/pf_printstr_utils.c \
		srcs/pf_print.c \
		srcs/pf_printint_utils.c

SRCS2 = srcs/pf_setreturn.c \
		srcs/pf_printuint.c \
		srcs/pf_printint.c

BONUS = bonus/pf_printfloat_bonus.c \
		bonus/pf_setreturn_bonus.c \
		bonus/pf_printuint_bonus.c \
		bonus/pf_printint_bonus.c \
		bonus/pf_convert_float_bonus.c \
		bonus/pf_convert_float_utils_bonus.c \
		bonus/pf_float_utils_bonus.c \
		bonus/pf_float_exp_bonus.c \
		bonus/pf_float_utils_2_bonus.c

OBJS = ${SRCS1:.c=.o} ${SRCS2:.c=.o}

BONUSOBJS = ${BONUS:.c=.o}

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

MEM = -fsanitize=address

$(NAME) : ${OBJS} ${INCLUDE}
	ar rcs $@ $?

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

bonus : ${BONUSOBJS} ${OBJS}
	ar rcs ${NAME} $?

clean :
	${RM} ${OBJS} ${BONUSOBJS}

fclean : clean
	${RM} ${NAME}

norm :
	~/.norminette/norminette.rb ${SRCS1} ${SRCS2} ${INCLUDE}

norm-bonus :
	~/.norminette/norminette.rb ${SRCS1} ${BONUS} ${INCLUDE}

.PHONY : all norm  clean re fclean bonus
