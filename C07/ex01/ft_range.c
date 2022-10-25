/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:12:16 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/19 17:06:08 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	length;
	int	*tab;
	int	i;
	int	k;

	i = min - 1;
	k = 0;
	length = max - min;
	tab = (int *)malloc(length * sizeof(int));
	if (length <= 0)
	{
		tab = 0;
		return (tab);
	}
	while (++i < max)
	{
		tab[k] = i;
		k++;
	}
	return (tab);
}
