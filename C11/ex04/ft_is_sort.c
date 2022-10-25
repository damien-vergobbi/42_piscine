/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 09:20:36 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/26 09:56:13 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	croi;
	int	decr;

	i = 0;
	croi = 1;
	decr = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			croi = 0;
		i++;
	}
	while (i > 0)
	{
		if (f(tab[i], tab[i - 1]) > 0)
			decr = 0;
		i--;
	}
	if (croi == 1 || decr == 1)
		return (1);
	return (0);
}
