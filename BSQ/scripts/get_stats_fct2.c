/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stats_fct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 04:47:13 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/28 04:47:18 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_size_fl(char *tab);

char	ft_get_empty(char *file)
{
	int		i;
	char	c;

	i = ft_size_fl(file);
	c = file[i - 3];
	return (c);
}

char	ft_get_obstacle(char *file)
{
	int		i;
	char	c;

	i = ft_size_fl(file);
	c = file[i - 2];
	return (c);
}

char	ft_get_replace(char *file)
{
	int		i;
	char	c;

	i = ft_size_fl(file);
	c = file[i - 1];
	return (c);
}
