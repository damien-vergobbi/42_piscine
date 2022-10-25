/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolbox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 13:57:31 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/18 14:03:22 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_res(int *tab, int size)
{
	int		i;
	char	c;

	i = 0;
	while (i < size * size)
	{
		c = '0' + tab[i];
		write(1, &c, 1);
		if ((i + 1) % size)
			write(1, " ", 1);
		else
			write(1, "\n", 1);
		++i;
	}
}
