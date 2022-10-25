/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:19:41 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/13 09:28:30 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	c += 48;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	b;

	b = nb;
	if (nb < 0 )
	{
		b = -b;
		write(1, "-", 1);
	}
	if (b >= 10)
	{
		ft_putnbr(b / 10);
	}
	ft_putchar(b % 10);
}
