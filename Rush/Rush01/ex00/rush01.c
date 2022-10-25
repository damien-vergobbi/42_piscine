/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:46:45 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/18 17:36:26 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pm_manager.h"

void	ft_print_res(int *tab, int size);
int		*ft_backtrack(t_pencil_mark *spm, int *hint, int *ret, int current);
void	ft_pm_init(t_pencil_mark *spm, int *tab, int size);
int		ft_strlen(char *str);
/*
*
*	ft_read : retourne 4 si 16 valeurs sont entrées
*	
*	ft_read_n : retourne n correspondant à la taille d'un côté, ou erreur
*				si impossible
*
*	ft_test_possible : analyse les valeurs entrées et regarde si le calcul 
*					   est possible
*
*/

int	ft_read(int i)
{
	if (i != 16)
	{
		write(1, "Error5\n", 7);
		return (-1);
	}
	else
		return (4);
}

int	ft_read_n(int i)
{
	if (i / 4 >= 4 && i / 4 <= 9 && i % 4 == 0)
		return (i / 4);
	else
	{
		write(1, "Error6\n", 7);
		return (-1);
	}
}

void	ft_test_possible(int *tab, int size)
{
	int	k;

	k = 0;
	while (k < size)
	{
		if (tab[k] + tab[k + size] < 3 || tab[k] + tab[k + size] > size + 1)
		{
			write(1, "Error4\n", 7);
			return ;
		}
		if (tab[k + (2 * size)] + tab[k + (3 * size)] < 3
			|| tab[k + (2 * size)] + tab[k + (3 * size)] > size + 1)
		{
			write(1, "Error3\n", 7);
			return ;
		}
		k++;
	}
}

int	ft_attribute(char *str, int *tab)
{
	int	k;
	int	i;

	i = 0;
	k = -1;
	while (str[++k])
	{
		if (str[k] == 32 && (str[k + 1] == 32 || k == 0 || str[k + 1] == 0))
		{
			write(1, "Error9\n", 7);
			return (-1);
		}
		if (str[k] != 32)
		{
			if (str[k] >= 48 && str[k] <= 57)
				tab[i++] = str[k] - 48;
			else
			{
				write(1, "Error2\n", 7);
				return (-1);
			}
		}
	}
	return (i);
}

void	ft_print_res2(char *tab, int size)
{
	int		l;
	int		c;
	char	m;
	char	o;

	l = 0;
	while (l < size)
	{
		c = 0;
		while (c < size)
		{
			m = 49;
			while (m < 49 + size)
			{
				o = tab[size * (size * l + c) + m - 49];
				if (o)
					write(1, &m, 1);
				else
					write(1, ".", 1);
				++m;
			}
			write(1, "|", 1);
			++c;
		}
		write(1, "\n", 1);
		++l;
	}
}

int	main(int argc, char *argv[])
{
	t_pencil_mark	spm;
	int				*tab;
	int				size;
	int				*solved;

	if (argc != 2)
	{
		write(1, "Error1\n", 7);
		return (0);
	}
	size = 0;
	tab = malloc(sizeof(int) * ft_strlen(argv[1]) / 2);
	size = ft_read_n(ft_attribute(argv[1], tab));
	if (size == -1)
		return (0);
	else
		ft_test_possible(tab, size);
	ft_pm_init(&spm, tab, size);
	solved = malloc(sizeof (int) * size * size);
	ft_print_res2(spm.pm, spm.size);
	solved = ft_backtrack(&spm, tab, solved, 0);
	if (solved == 0)
		write(1, "Error8\n", 7);
	else
		ft_print_res(solved, size);
	free(solved);
}
