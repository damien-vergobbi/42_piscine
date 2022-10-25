/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 07:56:16 by mapontil          #+#    #+#             */
/*   Updated: 2021/07/10 10:15:55 by mapontil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int	res;
	int	neg;

	res = 0;
	neg = 1;
	while (*str)
	{
		while (*str == 32 || (*str >= 8 && *str <= 13))
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				neg *= -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			res = res * 10 + (*str - 48);
			str++;
		}
		return (res * neg);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	if (argc < 3)
		write(1, "Arguments insuffisants\n", 23);
	if (argc > 3)
		write(1, "Arguments trop nombreux\n", 24);
	return (0);
}
