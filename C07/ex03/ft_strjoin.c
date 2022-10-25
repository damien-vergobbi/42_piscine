/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 19:14:59 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/24 17:54:38 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strs_length(int size, char **strs)
{
	int	i;
	int	k;
	int	a;

	i = -1;
	k = 0;
	a = 0;
	while (k < size)
	{
		while (strs[k][++i] != '\0')
			a++;
		i = -1;
		k++;
	}
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = ft_strs_length(size, strs);
	k = -1;
	str = (char *)malloc((1 + j + ft_strlen(sep) * size) * sizeof(char *));
	j = 0;
	if (str == 0)
		return (0);
	while (++k < size)
	{
		while (i++ < ft_strlen(strs[k]) && strs[k][i])
			str[j++] = strs[k][i];
		i = -1;
		if (k < size - 1 && ft_strlen(strs[k]) > 0)
			while (sep[++i])
				str[j++] = sep[i];
		i = -1;
	}
	str[j] = '\0';
	return (str);
}
