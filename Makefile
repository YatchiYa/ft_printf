# **************************************************************************** #
#                                                                      		   #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 02:13:23 by dhaouhao          #+#    #+#              #
#    Updated: 2019/12/27 03:08:42 by dhaouhao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_parse_c.c ft_parse_point.c ft_strdup.c ft_parse_digits.c ft_parse_prc.c ft_putadr.c ft_strlen.c ft_atoi.c ft_parse_format.c ft_parse_ptr.c  ft_putadr_len.c  ft_strlen_args.c ft_fill_width_precision.c  ft_parse_hexa.c ft_parse_stars.c  ft_putchar.c ft_struct_parse.c ft_hexalen.c  ft_parse_hexa_maj.c  ft_parse_str.c  ft_putnbr.c ft_isnum.c ft_parse_id.c ft_parse_u.c ft_putnbr_u.c pftft_numlen.c ft_parse_id_extends.c ft_parse_zero.c ft_putstr.c testsft_parse_adr.c ft_parse_minus.c ft_printf.c ft_strchr.c utils.c

HEADER		=	ft_printf.h

OBJS		=	${SRCS:.c=.o}

NAME		=	libftprintf.a

.c.o:
			gcc -Wall -Wextra -Werror -c -I./${HEADER} $< -o ${<:.c=.o}
			@echo "\033[92mstatus ${<:.c=.o} is [OK]\033[0m"

${NAME}:	${OBJS} ${HEADER}
			ar rc $@ $^
			ranlib ${NAME}
			@echo "\033[92mstatus ${NAME} is [OK]\033[0m"

all:		${NAME}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

clean:
			rm -f ${OBJS}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

fclean:		clean
			rm -f ${NAME}
			@echo "\033[92mstatus $@ [OK]\033[0m"

re:			fclean all
			@echo "\033[92mstatus $@ [OK]\033[0m"

.PHONY:		fclean clean re all
