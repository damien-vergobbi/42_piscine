/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:06:28 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/28 04:42:39 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fct.h"

int		ft_size_fl(char *tab);
int		ft_get_col(char *file);
int		ft_get_lines(int size, int nb_col);
char	ft_get_empty(char *file);
char	ft_get_obstacle(char *file);
char	ft_get_replace(char *file);
t_solution	*ft_find_square(char **map, int rows, int columns);

char	*ft_read_file(int ar)
{
	int		fd;
	int		size;
	char	*file_tab;

	file_tab = malloc((2048 * 15000) * sizeof(char));
	if (file_tab == 0)
		exit(1);
	fd = open("grid.txt", O_RDONLY);
	if (fd == -1)
	{
		free(file_tab);
		exit(1);
	}
	size = read(fd, file_tab, 2048 * 15000);
	if (size <= 4)
	{
		free(file_tab);
		exit(1);
	}
	close(fd);
	if (ar == 0)
		return (file_tab);
	else
		return (ft_itoa(size));
}

char	**ft_tab_malloc(int nb_col, int nb_lines)
{
	char	**file_tab;

	file_tab = malloc((nb_col * nb_lines * 2048) * sizeof(char));
	file_tab[0] = malloc((nb_col + 1) * sizeof(char));
	if (file_tab == 0 || file_tab[0] == 0)
	{
		free(file_tab);
		exit(1);
	}
	return (file_tab);
}

char	ft_put_elt(char c, char *tab)
{
	if (c == ft_get_empty(tab))
		return ('0');
	else if (c == ft_get_obstacle(tab))
		return ('1');
	else if (c == '\n')
		return ('\n');
	else
	{
		ft_putstr("Map error.\n");
		exit(2);
	}
}

char	**ft_tab_to_line(int nb_col, int nb_lines)
{
	int		i;
	int		a;
	int		k;
	char	*tab;
	char	**file_tab;

	tab = ft_read_file(0);
	file_tab = ft_tab_malloc(nb_col, nb_lines);
	i = ft_size_fl(tab);
	a = -1;
	k = 0;
	while (tab[++i])
	{
		if (tab[i] == '\n' && a == nb_col)
		{
			file_tab[k][++a] = '\0';
			a = -1;
			file_tab[++k] = malloc(2048 * sizeof(char));
		}
		else
			file_tab[k][++a] = ft_put_elt(tab[i], tab);
	}
	file_tab[k][a] = 0;
	return (file_tab);
}
/*
char	**ft_get_map(void)
{
	int		nb_col;
	int		nb_lines;
	int		size;
	char	*tab;
	char	**map;

	size = ft_atoi(ft_read_file(1));
	tab = ft_read_file(0);
	nb_col = ft_get_col(tab);
	nb_lines = ft_get_lines(size, nb_col);
	map = ft_tab_to_line(nb_col, nb_lines);
	ft_find_square(map, nb_lines, nb_lines);
	if (map == 0)
	{
		free(map);
		exit(1);
	}
	return (map);
}
*/