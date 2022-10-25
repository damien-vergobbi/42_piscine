/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:48:45 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/20 15:28:08 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_len(char *base)
{
	int	i;

	i = 0;
	while (*base != '\0')
	{
		i++;
		base++;
	}
	return (i);
}

int	ft_exists(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_base_invalid(char *base)
{
	int	i;
	int	k;

	k = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[k] != '\0')
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == base[k] && i != k)
				return (1);
			if (base[i] == '-' || base[i] == '+' || base[i] == 32 || (base[i] >= 9 && base[i] <= 13))
				return (1);
			i++;
		}
		k++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	i;
	long int	nbr;
	long int	signe;
	int			baseSize;

	i = 0;
	nbr = 0;
	signe = 1;
	baseSize = ft_base_len(base);
	if (ft_base_invalid(base))
		return (0);
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
