# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 18:08:58 by dvergobb          #+#    #+#              #
#    Updated: 2021/07/26 17:20:09 by dvergobb         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SOURCE = srcs/
SRCS   = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS   = ${addprefix ${SOURCE},${SRCS:.c=.o}}
HEAD   = includes
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
NAME   = libft.a

.c.o:
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		ar -rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIB)

re: fclean all
.PHONY: all clean fclean re
