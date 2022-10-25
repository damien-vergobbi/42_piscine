/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberdrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 13:43:15 by mberdrin          #+#    #+#             */
/*   Updated: 2021/07/25 16:19:50 by mberdrin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "key_val.h"
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	x = 0;
	if (n < 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] && s2[x] && x < n - 1)
		x++;
	if (s1[x] != 0)
	{
		if (s1[x + 1] != 0)
			return (1);
	}
	return (s1[x] - s2[x]);
}

char	*ft_to_find(t_key_val *tab, char *str, int n)
{
	int	i;

	i = 0;
	while (tab[i].key)
	{
		if (ft_strncmp(tab[i].key, str, n) == 0)
			return (tab[i].val);
		++i;
	}
	return (0);
}
