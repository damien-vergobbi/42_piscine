/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 07:59:42 by mapontil          #+#    #+#             */
/*   Updated: 2021/07/10 10:16:21 by mapontil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printrush(int x, char l, char m, char r)
{
	write(1, &l, 1);
	while (x > 2)
	{
		write(1, &m, 1);
		x--;
	}
	if (x == 2)
		write(1, &r, 1);
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
		return ;
	ft_printrush(x, 'A', 'B', 'C');
	while (y > 2)
	{
		ft_printrush(x, 'B', ' ', 'B');
		y--;
	}
	if (y == 2)
		ft_printrush(x, 'A', 'B', 'C');
}
