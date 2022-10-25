# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 23:05:54 by dvergobb          #+#    #+#              #
#    Updated: 2021/07/28 02:30:33 by vsandre          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SOURCE  = ./ressources/
SRCS    = ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_strcmp.c ft_atoi.c ft_itoa.c ft_strdup.c
OBJS    = ${addprefix ${SOURCE},${SRCS:.c=.o}}
HEAD    = ./fct.h
SCRIPTS = get_map.c get_stats_fct.c get_stats_fct2.c
SOBJS   = ${addprefix ./scripts/,${SCRIPTS}}
MAIN    = ./main.c 
CC      = gcc

CFLAGS  = -Wall -Wextra -Werror 

NAME    = bsq

l = 10
c = 10
d = 2
args = $(foreach a,$($(subst -,_,$1)_args),$(if $(value $a),$a="$($a)"))

.c.o:
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${CC} ${CFLAGS} ${MAIN} ${SOBJS} -o ${NAME} ${OBJS}
		make grid 

all: ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) grid.txt

re: fclean all

git: re
	norminette
	make fclean

grid:
	perl ./ressources/map_gen.pl ${l} ${c} ${d} $(call args,$@) > grid.txt

grid-s:
	perl ./ressources/map_gen.pl 100 100 3 > grid.txt

grid-m:
	perl ./ressources/map_gen.pl 150 150 5 > grid.txt

grid-l:
	perl ./ressources/map_gen.pl 1000 1000 30 > grid.txt


.PHONY: all clean fclean re git grid grid-s grid-m grid-l
