/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:13:18 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/10 12:26:54 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_rush(int x, char a, char b, char c)
{
	write(1, &a, 1);
	if (x > 1)
	{
		while (x > 2)
		{
			write(1, &b, 1);
			x--;
		}
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	rush(int x, int y)
{
	int	a;
	int	b;
	int	c;

	a = x - 2;
	c = y;
	b = 0;
	print_rush(x, '/', '*', '\\');
	while (y > 2)
	{
		write(1, "*", 1);
		while (b < a)
		{
			write(1, " ", 1);
			b++;
		}
		if (a + 2 > 1)
			write(1, "*", 1);
		write(1, "\n", 1);
		b = 0;
		y--;
	}
	if (c > 1)
		print_rush(x, '\\', '*', '/');
}
