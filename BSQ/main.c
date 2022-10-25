/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:07:46 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/28 02:08:51 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/fct.h"

char	**ft_get_map(void);
int		ft_size_fl(char *tab);
int		ft_get_col(char *file);
int		ft_get_lines(int size, int nb_col);
char	ft_get_empty(char *file);
char	ft_get_obstacle(char *file);
char	ft_get_replace(char *file);
char	*ft_read_file(int ar);
char	**ft_tab_malloc(int nb_col, int nb_lines);
char	ft_put_elt(char c, char *tab);
char	**ft_tab_to_line(int nb_col, int nb_lines);

void testPrintMap(char ** map)
{
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[0]);
		i++;
	}
}

int	main(void)
{
	char	**map;
	int		nb_col;
	int		nb_lines;
	int		size;
	char	*tab;

	size = ft_atoi(ft_read_file(1));
	tab = ft_read_file(0);
	nb_col = ft_get_col(tab);
	nb_lines = ft_get_lines(size, nb_col);
	map = ft_tab_to_line(nb_col, nb_lines);
	ft_find_square(map, nb_lines, nb_lines);

	if (map == 0)
		exit(1);
	testPrintMap(map);
	return (0);
}
