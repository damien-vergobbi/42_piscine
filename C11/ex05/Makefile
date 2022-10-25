# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 18:08:58 by dvergobb          #+#    #+#              #
#    Updated: 2021/07/26 21:14:28 by dvergobb         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = do-op.c calc.c
OBJS = ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC   = gcc
FLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	$(CC) $(FLAGS) -o $(NAME) ${OBJS}

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY:	$(NAME) all clean fclean