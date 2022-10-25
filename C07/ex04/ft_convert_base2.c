/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:42:57 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/21 15:03:56 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
			if (base[i] == '-' || base[i] == '+' || base[i] == 32
				|| (base[i] >= 9 && base[i] <= 13))
				return (1);
			i++;
		}
		k++;
	}
	return (0);
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

int	ft_nb_len(int nb, char *base)
{
	int	baseLen;
	int	len;

	baseLen = 0;
	while (base[baseLen])
		baseLen++;
	len = 0;
	while (nb > baseLen)
	{
		++len;
		nb /= baseLen;
	}
	if (nb < 0)
		len++;
	return (len);
}
