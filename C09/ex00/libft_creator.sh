# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 17:48:40 by dvergobb          #+#    #+#              #
#    Updated: 2021/07/25 18:07:08 by dvergobb         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

gcc -c -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c  ft_strcmp.c && ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o  ft_strcmp.o && ranlib libft.a 
