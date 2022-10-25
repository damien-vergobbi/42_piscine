/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 08:48:48 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/08 18:29:53 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_value(char a, char b, char c)
{
	if (a == '7' && b == '8' && c == '9')
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	k;
	char	i;
	char	j;

	k = '0';
	i = '0';
	j = '0';
	while (k <= '7')
	{
		i = k + 1;
		while (i <= '8')
		{
			j = i + 1;
			while (j <= '9')
			{
				 print_value(k, i, j);
				j++;
			}
			i++;
		}
		k++;
	}
}
