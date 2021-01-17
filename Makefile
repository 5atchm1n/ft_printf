# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/18 06:45:17 by sshakya           #+#    #+#              #
#    Updated: 2021/01/17 23:35:29 by sshakya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = ft_printf.h

SRCS =	ft_printf.c \
		srcs/pf_split.c \
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
		srcs/pf_setreturn.c \
		srcs/pf_printstr.c \
		srcs/pf_printstr_utils.c \
		srcs/pf_print.c \
		srcs/pf_printint.c \
		srcs/pf_printuint.c \
		srcs/pf_printfloat.c \
		srcs/pf_convert_float.c \
		srcs/pf_float_utils.c \
		srcs/pf_float_utils_2.c \
		srcs/pf_printint_utils.c

TEST1 = tests/test_mypf_int.c

TEST4 = tests/test_mypf_str.c

TEST2 = tests/test_mypf_hexp.c

TEST3 = tests/test_mypf_fge.c

TESTSPLT =	srcs/pf_split.c tests/test_pfsplit.c

TESTFLAGS = srcs/pf_setflags.c tests/test_setflags.c srcs/ft_printf_utils.c \
		srcs/ft_printf_libft.c

TESTSTR = srcs/pf_setstring.c tests/test_setstring.c srcs/ft_printf_utils.c \
		srcs/ft_printf_libft.c

TESTLST = tests/test_setlst2.c srcs/pf_split.c srcs/pf_setlst.c \
		  srcs/pf_setflags.c srcs/pf_setformat.c srcs/pf_setstring.c \
		  srcs/ft_printf_utils.c srcs/ft_printf_libft.c \
		  srcs/pf_flagargs.c srcs/pf_setargs.c srcs/pf_flag_utils.c \
		  srcs/pf_print_utils.c

TESTPF = tests/test_printf.c

TESTPF2 = tests/test_printf2.c

TESTPF3 = tests/test_printf3.c

TESTPF4 = tests/test_printf4.c

TESTMYPF = tests/test_mypf.c

CC = clang

CFLAGS	= -Wall -Wextra -Werror -g

MEM = -fsanitize=address

test-int:
	${CC} ${CFLAGS} ${INCLUDE} ${SRCS} ${TEST1} && ./a.out

test-str:
	${CC} ${CFLAGS} ${INCLUDE} ${SRCS} ${TEST4} && ./a.out

test-hexp:
	${CC} ${CFLAGS} ${INCLUDE} ${SRCS} ${TEST2} && ./a.out

test-fge:
	${CC} ${CFLAGS} ${INCLUDE} ${SRCS} ${TEST3} && ./a.out

testsplit:
	${CC} ${CFLAGS} ${MEM} ${TESTSPLT} && ./a.out

testflags: 
	${CC} ${CFLAGS} ${MEM} ${TESTFLAGS} ${INCLUDE} && ./a.out

teststr:
	${CC} ${CFLAGS} ${MEM} ${TESTSTR} ${INCLUDE} && ./a.out

testlst:
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTLST} && ./a.out

testpf-int:
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTPF} && ./a.out
testpf-lenmod:
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTPF2} && ./a.out
testpf-fge:
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTPF3} && ./a.out
testpf-hex:
	${CC} ${CFLAGS} ${MEM} ${INCLUDE} ${TESTPF4} && ./a.out


testmypf:
	${CC} ${CFLAGS} ${INCLUDE} ${SRCS} ${TESTMYPF} && ./a.out

norm :
	~/.norminette/norminette.rb ${SRCS} ${INCLUDE}

.PHONY : all norm test3 test2 test1

