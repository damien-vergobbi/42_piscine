/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:42:43 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/25 16:59:09 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str);
int	ft_base_invalid(char *base);
int	ft_exists(char c, char *base);
int	ft_nb_len(int nb, char *base);

long int	ft_atoi_base(char *str, char *base, long int baseSize)
{
	long int	i;
	long int	nbr;
	long int	signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] != '\0' && ft_exists(str[i], base) != -1)
	{
		nbr = nbr * baseSize + ft_exists(str[i], base);
		i++;
	}
	return (nbr * signe);
}

char	*ft_putnbr_base(long int nb, char *base, long int baseLen)
{
	long int	i;
	long int	res;
	long int	factor;
	char		*str;

	i = -1;
	res = 0;
	factor = 1;
	str = malloc(ft_nb_len(nb, base) * sizeof(int));
	if (str == 0)
		return (0);
	if (nb < 0)
	{
		nb = -nb;
		str[++i] = '-';
	}
	while (nb / factor >= baseLen)
		factor = factor * baseLen;
	while (factor > 0)
	{
		res = (nb / factor) % baseLen;
		factor = factor / baseLen;
		str[++i] = base[res];
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	atoi;

	if (ft_base_invalid(base_from) || ft_base_invalid(base_to))
		return (0);
	atoi = ft_atoi_base(nbr, base_from, ft_strlen(base_from));
	return (ft_putnbr_base(atoi, base_to, ft_strlen(base_to)));
}
