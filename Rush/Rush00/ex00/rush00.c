/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:47:39 by mapontil          #+#    #+#             */
/*   Updated: 2021/07/10 10:16:08 by mapontil         ###   ########lyon.fr   */
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
	ft_printrush(x, 'o', '-', 'o');
	while (y > 2)
	{
		ft_printrush(x, '|', ' ', '|');
		y--;
	}
	if (y == 2)
		ft_printrush(x, 'o', '-', 'o');
}
