/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:32:43 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/18 11:38:12 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pm_manager.h"
#include <stdlib.h>

void	ft_init_all(char *t1, char *t2, int size)
{
	int		i;
	int		lim;

	lim = size * size * 2;
	i = 0;
	while (i < lim)
		t2[i++] = size;
	lim = size * size * size;
	i = 0;
	while (i < lim)
		t1[i++] = 1;
}

void	ft_hint_c(t_pencil_mark *p, int val, int loc, char dir)
{
	int		i;
	int		j;

	if (val == 1)
	{
		if (dir)
			ft_set_cell(p, 0, loc, p->size - 1);
		else
			ft_set_cell(p, p->size - 1, loc, p->size - 1);
	}
	else
	{
		i = val;
		while (--i)
		{
			j = i + 1;
			while (--j)
			{
				if (dir)
					ft_delete_mark(p, val - i - 1, loc, p->size - j);
				else
					ft_delete_mark(p, p->size - val + i, loc, p->size - j);
			}
		}
	}
}

void	ft_hint_l(t_pencil_mark *p, int val, int loc, char dir)
{
	int		i;
	int		j;

	if (val == 1)
	{
		if (dir)
			ft_set_cell(p, loc, 0, p->size - 1);
		else
			ft_set_cell(p, loc, p->size - 1, p->size - 1);
	}
	else
	{
		i = val;
		while (--i)
		{
			j = i + 1;
			while (--j)
			{
				if (dir)
					ft_delete_mark(p, loc, val - i - 1, p->size - j);
				else
					ft_delete_mark(p, loc, p->size - val + i, p->size - j);
			}
		}
	}
}

void	ft_check_hints(t_pencil_mark *spm, int *tab)
{
	int		i;

	i = 0;
	while (i < spm->size)
	{
		ft_hint_c(spm, tab[i], i, 1);
		ft_hint_c(spm, tab[i + spm->size], i, 0);
		ft_hint_l(spm, tab[i + spm->size * 2], i, 1);
		ft_hint_l(spm, tab[i + spm->size * 3], i, 0);
		++i;
	}
}

void	ft_pm_init(t_pencil_mark *spm, int *tab, int size)
{
	spm->size = size;
	spm->pm = malloc(size * size * size * sizeof (char));
	spm->mc = malloc(2 * size * size * sizeof (char));
	ft_init_all(spm->pm, spm->mc, size);
	ft_check_hints(spm, tab);
}
