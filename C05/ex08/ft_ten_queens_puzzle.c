/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 21:23:06 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/15 22:33:29 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(int tab[10], int x, int y)
{
	int	i;
	int	a;

	i = 0;
	a = 1;
	while (i < x)
	{
		if (y == tab[i])
			a = 0;
		if (i + tab[i] == x + y)
			a = 0;
		if (i - tab[i] == x - y)
			a = 0;
		if (a == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_recurrence(int tab[10], int *k, int b)
{
	int	i;
	int	j;

	if (b == 10)
	{
		*k = *k + 1;
		j = -1;
		while (++j < 10)
			ft_putchar(tab[j] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			if (ft_check(tab, b, i))
			{
				tab[b] = i;
				ft_recurrence(tab, k, b + 1);
			}
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10];
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < 10)
	{
		tab[i] = -1;
		i++;
	}
	ft_recurrence(tab, &k, 0);
	return (k);
}
