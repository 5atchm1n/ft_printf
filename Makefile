# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2020/12/20 06:06:35 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ft_printf.h

SRCS =	ft_printf.c \
		srcs/ft_pfsplit.c \
		srcs/ft_pfsetlst.c \
		srcs/ft_printf_utils.c \
		srcs/ft_setflags.c \
		srcs/ft_setformat.c \
		srcs/ft_setstring.c

TEST1 =	srcs/ft_pfsplit.c tests/test_pfsplit.c

TEST2 = srcs/ft_setflags.c tests/test_setflags.c srcs/ft_printf_utils.c \
		srcs/ft_printf_libft.c

TEST3 = srcs/ft_setstring.c tests/test_setstring.c srcs/ft_printf_utils.c \
		srcs/ft_printf_libft.c

TESTLST = tests/test_setlst2.c srcs/ft_pfsplit.c srcs/ft_pfsetlst.c \
		  srcs/ft_setflags.c srcs/ft_setformat.c srcs/ft_setstring.c \
		  srcs/ft_printf_utils.c srcs/ft_printf_libft.c

TESTPF = tests/test_printf.c 

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

MEM = -fsanitize=address

testsplit:
	${CC} ${CFLAGS} ${MEM} ${TEST1} && ./a.out

testflags: 
	${CC} ${CFLAGS} ${MEM} ${TEST2} ${INCLUDE} && ./a.out

teststr:
	${CC} ${CFLAGS} ${MEM} ${TEST3} ${INCLUDE} && ./a.out

testlst:
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTLST} && ./a.out

testpf:
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTPF} && ./a.out

norm :
	~/.norminette/norminette.rb ${SRCS} ${INCLUDE}

.PHONY : all norm test3 test2 test1

