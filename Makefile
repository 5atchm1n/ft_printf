# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2020/12/19 03:38:37 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ft_printf.h

SRCS =	ft_printf.c \
		ft_pfsplit.c \
		ft_pfsetlst.c \
		ft_printf_utils.c \
		ft_setflags.c \
		ft_setformat.c \
		ft_setstring.c

TEST1 =	ft_pfsplit.c test_pfsplit.c

TEST2 = ft_setflags.c test_setflags.c ft_printf_utils.c

TEST3 = ft_setstring.c test_setstring.c ft_printf_utils.c

TESTLST = test_setlst.c ft_pfsplit.c ft_pfsetlst.c \
		  ft_setflags.c ft_setformat.c ft_setstring.c \
		  ft_printf_utils.c

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

testsplit:
	${CC} ${CFLAGS} ${TEST1} && ./a.out

testflags: 
	${CC} ${CFLAGS} ${TEST2} ${INCLUDE} && ./a.out

teststr:
	${CC} ${CFLAGS} ${TEST3} ${INCLUDE} && ./a.out

testlst:
	${CC} ${CFLAGS} ${TESTLST} ${INCLUDE} && ./a.out

norm :
	~/.norminette/norminette.rb ${SRCS} ${INCLUDE}

.PHONY : all norm test3 test2 test1

