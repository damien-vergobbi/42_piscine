/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberdrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:13:31 by mberdrin          #+#    #+#             */
/*   Updated: 2021/07/25 16:46:33 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "key_val.h"

int	ft_morse(char *str, int n, t_key_val *tab)
{
	while (str[n])
	{
		if (str == 0)
		{
			return (1);
		}
		ft_to_find(tab, str, 1);
		++str;
	}
	return (1);
}
