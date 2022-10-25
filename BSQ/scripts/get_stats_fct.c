/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 02:14:31 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/28 02:14:40 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_fl(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\n')
		i++;
	return (i);
}

int	ft_get_col(char *file)
{
	int	i;
	int	a;
	int	nb_col;

	i = 0;
	while (file[i] != '\n')
		i++;
	a = i + 1;
	while (file[a] != '\n')
		a++;
	nb_col = a - i - 1;
	if (nb_col < 1)
		exit(1);
	else
		return (nb_col);
}

int	ft_get_lines(int size, int nb_col)
{
	int	nb_lines;

	nb_lines = size / nb_col;
	if (nb_lines < 1)
		exit(1);
	else
		return (nb_lines);
}
