/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:07:36 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/18 15:29:22 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_up(int *tab, int current, int size, int *hint)
{
	int i;
	int view;
	int max_height;

	i = 0;
	view = 1;
	max_height = 0;
	while (tab[i * size + current] != size)
	{
		if(tab[i * size + current] > max_height)
		{
			max_height = tab[i * size + current];
			++view;
		}
		++i;
	}
	if (view != hint[current])
		return (0);
	return (1);
}

int	ft_down(int *tab, int current, int size, int *hint)
{
	int i;
	int view;
	int max_height;

	i = size - 1;
	view = 1;
	max_height = 0;
	while (tab[i * size + current] != size)
	{
		if(tab[i * size + current] > max_height)
		{
			max_height = tab[i * size + current];
			++view;
		}
		--i;
	}
	if (view != hint[size + current])
		return (0);
	return (1);
}

int	ft_left(int *tab, int current, int size, int *hint)
{
	int i;
	int view;
	int max_height;

	i = 0;
	view = 1;
	max_height = 0;
	while (tab[current * size + i] != size)
	{
		if(tab[current * size + i] > max_height)
		{
			max_height = tab[current * size + i];
			++view;
		}
		++i;
	}
	if (view != hint[size * 2 + current])
		return (0);
	return (1);
}

int	ft_right(int *tab, int current, int size, int *hint)
{
	int i;
	int view;
	int max_height;

	i = size - 1;
	view = 1;
	max_height = 0;
	while (tab[current * size + i] != size)
	{
		if(tab[current * size + i] > max_height)
		{
			max_height = tab[current * size + i];
			++view;
		}
		--i;
	}
	if (view != hint[size * 3 + current])
		return (0);
	return (1);
}

int	ft_check_hint(int *tab, int current, int size, int *hint)
{
	if (tab[current] == size)
	{
		if (ft_up(tab, current % size, size, hint) == 0)
			return (0);
		if (ft_left(tab, current / size, size, hint) == 0)
			return (0);
	}
	if (current % size == size - 1)
		if (ft_right(tab, current / size, size, hint) == 0)
			return (0);
	if (current / size == size - 1)
		if (ft_right(tab, current % size, size, hint) == 0)
			return (0);
	return (1);
}
