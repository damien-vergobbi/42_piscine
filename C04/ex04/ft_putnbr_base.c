/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:19:41 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/20 14:48:51 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	base_valid(char *base)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		k = i + 1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[k])
		{
			if (base[k] == base[i])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	res;
	long int	baseLen;
	long int	factor;
	long int	nb;

	nb = nbr;
	factor = 1;
	baseLen = ft_strlen(base);
	if (base_valid(base))
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar('-');
		}
		while (nb / factor >= baseLen)
			factor = factor * baseLen;
		while (factor > 0)
		{
			res = (nb / factor) % baseLen;
			factor = factor / baseLen;
			ft_putchar(base[res]);
		}
	}
}
