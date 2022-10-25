/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:22:31 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/24 13:31:41 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_garbage.h"

t_garbage	*g_first;

void	ft_garbage_init(void)
{
	g_first = 0;
}

void	*ft_malloc(int size)
{
	t_garbage	*new;

	new = malloc(sizeof(t_garbage));
	if (new == 0)
		return (0);
	new->data = malloc(size);
	if (new->data == 0)
	{
		free (new);
		return (0);
	}
	new->next = g_first;
	g_first = new;
	return (new->data);
}

void	ft_garbage_clear(void)
{
	t_garbage	*curr;

	while (g_first)
	{
		curr = g_first;
		g_first = curr->next;
		free(curr->data);
		free(curr);
	}
}
