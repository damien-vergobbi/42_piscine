/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:39:38 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/18 10:25:43 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pm_manager.h"

void	ft_delete_mark(t_pencil_mark *spm, int l, int c, int nb)
{
	if (spm->pm[spm->size * (l * spm->size + c) + nb])
	{
		spm->pm[spm->size * (l * spm->size + c) + nb] = 0;
		ft_reduce_count(spm, l, c, nb);
		ft_check_cell(spm, l, c);
	}
}

void	ft_reduce_count(t_pencil_mark *spm, int l, int c, int nb)
{
	int		i;

	i = 0;
	if (--(spm->mc[l * spm->size + nb]) == 1)
	{
		while (i < spm->size
			&& spm->pm[spm->size * (l * spm->size + i) + nb] == 0)
			++i;
		ft_set_cell(spm, l, i, nb);
	}
	i = 0;
	if (--(spm->mc[spm->size * (c + spm->size) + nb]) == 1)
	{
		while (i < spm->size
			&& spm->pm[spm->size * (i * spm->size + c) + nb] == 0)
			++i;
		ft_set_cell(spm, i, c, nb);
	}
}

void	ft_set_cell(t_pencil_mark *spm, int l, int c, int nb)
{
	int		i;

	i = 0;
	while (i < spm->size)
	{
		if (i != l)
			ft_delete_mark(spm, i, c, nb);
		if (i != c)
			ft_delete_mark(spm, l, i, nb);
		if (i != nb)
			ft_delete_mark(spm, l, c, i);
		++i;
	}
}

void	ft_check_cell(t_pencil_mark *spm, int l, int c)
{
	int		i;
	int		nb;

	i = 0;
	nb = -1;
	while (i < spm->size)
	{
		if (spm->pm[spm->size * (l * spm->size + c) + i])
		{
			if (nb == -1)
				nb = i;
			else
				return ;
		}
		++i;
	}
	if (nb >= 0)
		ft_set_cell(spm, l, c, nb);
}
