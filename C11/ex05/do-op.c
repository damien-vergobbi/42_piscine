/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 09:59:22 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/26 12:33:38 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_add(int a, int b);
int	ft_sub(int a, int b);
int	ft_div(int a, int b);
int	ft_mul(int a, int b);
int	ft_mod(int a, int b);

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	result;
	int	signe;
	int	i;

	result = 0;
	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * signe);
}

void	ft_putnbr(int nb)
{
	long int	b;

	b = nb;
	if (b < 0)
	{
		ft_putchar('-');
		b = -b;
	}
	if (b >= 10)
		ft_putnbr(b / 10);
	ft_putchar(b % 10 + 48);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (ft_strcmp(argv[2], "+") == 0)
		ft_putnbr(ft_add(ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (ft_strcmp(argv[2], "-") == 0)
		ft_putnbr(ft_sub(ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (ft_strcmp(argv[2], "/") == 0)
	{
		if (ft_strcmp(argv[3], "0") == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(ft_div(ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	else if (ft_strcmp(argv[2], "*") == 0)
		ft_putnbr(ft_mul(ft_atoi(argv[1]), ft_atoi(argv[3])));
	else if (ft_strcmp(argv[2], "%") == 0)
	{
		if (ft_strcmp(argv[3], "0") == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(ft_mod(ft_atoi(argv[1]), ft_atoi(argv[3])));
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
}
