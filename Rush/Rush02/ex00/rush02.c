/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:22:37 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/25 14:40:59 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_garbage.h"
#include "key_val.h"

#include <stdio.h>

int			ft_key_val(char *dict_file, t_key_val **ret);

int	ft_atoi(char *str)
{
	int	result;
	int	signe;
	int	i;

	result = 0;
	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * signe);
}

void	ft_main(int argc, char **argv)
{
	char		*file;
	t_key_val	*dict;

	if (argc == 1 || argc >= 4)
	{
		write (1, "ERROR", 5);
		write (1, "\n", 1);
		return ;
	}
	file = "numbers.dict";
	if (argc == 3)
		file = argv[2];
	if (ft_key_val(file, &dict))
		return ;
	printf("%s is written %s\n", dict[ft_atoi(argv[1])].key,
		dict[ft_atoi(argv[1])].val);
}

int	main(int argc, char **argv)
{
	ft_garbage_init();
	ft_main(argc, argv);
	ft_garbage_clear();
}
