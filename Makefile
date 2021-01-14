# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2021/01/14 06:08:22 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ft_printf.h

SRCS =	ft_printf.c \
		srcs/pf_split.c \
		srcs/pf_setlst.c \
		srcs/ft_printf_utils.c \
		srcs/ft_printf_utils_2.c \
		srcs/ft_printf_libft.c \
		srcs/pf_flag_utils.c \
		srcs/pf_setflags.c \
		srcs/pf_setformat.c \
		srcs/pf_setstring.c \
		srcs/pf_flagargs.c \
		srcs/pf_setargs.c \
		srcs/pf_convert.c \
		srcs/pf_setreturn.c \
		srcs/pf_printstr.c \
		srcs/pf_print.c \
		srcs/pf_printint.c \
		srcs/pf_printuint.c \
		srcs/pf_printint_utils.c

TEST = tests/test_final.c

TEST1 =	srcs/pf_split.c tests/test_pfsplit.c

TEST2 = srcs/pf_setflags.c tests/test_setflags.c srcs/ft_printf_utils.c \
		srcs/ft_printf_libft.c

TEST3 = srcs/pf_setstring.c tests/test_setstring.c srcs/ft_printf_utils.c \
		srcs/ft_printf_libft.c

TESTLST = tests/test_setlst2.c srcs/pf_split.c srcs/pf_setlst.c \
		  srcs/pf_setflags.c srcs/pf_setformat.c srcs/pf_setstring.c \
		  srcs/ft_printf_utils.c srcs/ft_printf_libft.c \
		  srcs/pf_flagargs.c srcs/pf_setargs.c srcs/pf_flag_utils.c \
		  srcs/pf_print_utils.c

TESTPF = tests/test_printf.c

TESTMYPF = tests/test_mypf.c

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

MEM = -fsanitize=address

test:
	${CC} ${CFLAGS} ${INCLUDE} ${SRCS} ${TEST} && ./a.out > mypf
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTPF} && ./a.out > pf
	diff -a pf mypf

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

testmypf:
	${CC} ${CFLAGS} ${INCLUDE} ${SRCS} ${TESTMYPF} && ./a.out

norm :
	~/.norminette/norminette.rb ${SRCS} ${INCLUDE}

.PHONY : all norm test3 test2 test1

