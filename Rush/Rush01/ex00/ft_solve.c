/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kestucke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:34:50 by kestucke          #+#    #+#             */
/*   Updated: 2021/07/18 15:33:01 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pm_manager.h"

void	ft_print_res(int *tab, int size);
int		ft_check_hint(int *tab, int current, int size, int *hint);

int	ft_check_dup(int *tab, int current, int size)
{
	int			i;
	const int	cur = tab[current];

	i = 1;
	while (i < size)
	{
		if (current - i * size >= 0)
			if (cur == tab[current - i * size])
				return (0);
		if (current - i >= 0 && current / size == (current - i) / size)
			if (cur == tab[current - i])
				return (0);
		++i;
	}
	return (1);
}

int	*ft_backtrack(t_pencil_mark *spm, int *hint, int *ret, int current)
{
	int		i;

//ft_print_res(ret, spm->size);
//write(1, "\n", 1);
	if (current == spm->size * spm->size)
		return (ret);
	i = 0;
	while (i < spm->size)
	{
		ret[current] = i + 1;
		if (spm->pm[current * spm->size + i] &&
			ft_check_dup(ret, current, spm->size) &&
			ft_check_hint(ret, current, spm->size, hint))
		{
			if (ft_backtrack(spm, hint, ret, current + 1))
				return (ret);
		}
		++i;
	}
	ret[current] = 0;
	if (current == 0)
		free(ret);
	return (0);
}
