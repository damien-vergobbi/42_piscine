/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:37:47 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/25 18:04:59 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "key_val.h"
#include "ft_garbage.h"

/*
 *	ft_get_key : get the key of an element (ex: 10)
 *
 *	ft_get_val : get the value of an element (ex: ten)
 *
 *	ft_get_file_content : open and read the file "numbers.dict" and return 
 *			the content in an array named 'buf'. 
 *
 *	ft_get_tab : return an array named 'tab' which contains the file 
 *			"numbers.dict" line by line.
 *
 *	ft_key_val : sort the array named 'tab' (ft_get_tab) and return the final
 *			array named 'array'; this array is split with two variables : the
 *			'key' and the 'val' (value) of each lines.
 *			 
*/

int	ft_get_key(t_key_val *final, char *str, int k)
{
	int		i;
	char	*key;

	i = 0;
	key = ft_malloc(2048 * sizeof(char));
	if (key == 0)
		return (1);
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		key[i] = str[i];
		i++;
	}
	final[k].key = key;
	return (0);
}

int	ft_get_val(t_key_val *final, char *str, int k)
{
	int		i;
	int		a;
	char	*val;

	i = 0;
	a = 0;
	val = ft_malloc(2048 * sizeof(char));
	if (val == 0)
		return (1);
	while (str[i] != '\0' && str[i] != ':')
		i++;
	while (str[i] == ' ' || str[i] == ':')
		i++;
	while (str[i])
	{
		val[a++] = str[i];
		i++;
	}
	final[k].val = val;
	return (0);
}

int	ft_get_file_content(char *dict_file, char *file_content)
{
	int		fd;
	int		size;
	int		file_len;

	file_len = 0;
	if (file_content == 0)
		return (1);
	fd = open(dict_file, O_RDONLY);
	if (fd == -1)
		return (1);
	size = read(fd, file_content, 2048);
	file_content[size] = 0;
	while (file_content[file_len])
		file_len++;
	close(fd);
	return (0);
}

int	ft_get_tab(char *dict_file, char **tab, char *file_content)
{
	int		i;
	int		a;
	int		k;

	i = -1;
	a = -1;
	k = 0;
	ft_get_file_content(dict_file, file_content);
	tab[0] = ft_malloc(2048 * sizeof(char));
	if (tab == 0 || tab[0] == 0)
		return (1);
	while (file_content[++i])
	{
		if (file_content[i] == '\n' || file_content[i] == '\r')
		{
			tab[k][++a] = '\0';
			a = -1;
			tab[++k] = ft_malloc(2048 * sizeof(char));
		}
		else
			tab[k][++a] = file_content[i];
	}
	tab[k] = 0;
	return (0);
}

int	ft_key_val(char *dict_file, t_key_val **ret)
{
	int			i;
	int			k;
	char		*file_content;
	char		**tab;
	t_key_val	*final;

	i = 0;
	k = -1;
	tab = ft_malloc(512 * sizeof(char *));
	final = ft_malloc(2048 * sizeof(t_key_val));
	file_content = ft_malloc(2048 * sizeof(char));
	if (final == 0 || tab == 0 || file_content == 0)
		return (1);
	if (ft_get_tab(dict_file, tab, file_content))
		return (0);
	while (tab[++k] != 0)
	{
		ft_get_key(final, tab[k], k);
		ft_get_val(final, tab[k], k);
	}
	*ret = final;
	return (0);
}
