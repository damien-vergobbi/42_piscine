/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 12:21:47 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/23 11:26:14 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_check(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (str[++i])
	{
		if (ft_check(str[i], charset) && !ft_check(str[i - 1], charset))
			k++;
	}
	return (k);
}

char	**final_tab(char **tab, int k)
{
	if (ft_strlen(tab[k]) > 0)
		k++;
	tab[k] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = -1;
	j = 0;
	k = 0;
	tab = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	tab[0] = malloc(sizeof(char *) * (1 + ft_strlen(str + i + 1)));
	while (str[++i])
	{
		if (!ft_check(str[i], charset) && str[i])
			tab[k][j++] = str[i];
		if (ft_check(str[i], charset) && !ft_check(str[i + 1], charset))
		{
			tab[k][j] = '\0';
			j = 0;
			if (ft_strlen(tab[k]) >= 1)
				k++;
			tab[k] = malloc(sizeof(char *) * (1 + ft_strlen(str + i)));
		}
		tab[k][j] = '\0';
	}
	return (final_tab(tab, k));
}
