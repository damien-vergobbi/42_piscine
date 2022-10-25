/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 02:09:20 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/28 02:09:22 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
# define FCT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_itoa(int nb);
char			*ft_strdup(char *src);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
typedef struct s_solution	t_solution;
t_solution		*ft_find_square(char **map, int rows, int columns);

#endif
