# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2020/12/18 07:15:45 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ft_printf.h

SRCS =	ft_printf.c \
		ft_pfsplit.c \
		ft_pfsetlst.c \
		ft_printf_utils.c \
		ft_setflags.c

TEST1 =	ft_pfsplit.c test_pfsplit.c

TEST2 = ft_setflags.c test_setflags.c ft_printf_utils.c

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

test1:
	${CC} ${CFLAGS} ${TEST1} && ./a.out

test2: 
	${CC} ${CFLAGS} ${TEST2} ${INCLUDE} && ./a.out

norm :
	~/.norminette/norminette.rb ${SRCS} ${INCLUDE}

.PHONY : all norm test2 test1

