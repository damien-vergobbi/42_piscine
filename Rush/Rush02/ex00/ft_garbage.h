/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_garbage.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:45:05 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/24 12:58:09 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGE_H
# define FT_GARBAGE_H

typedef struct s_garbage
{
	void				*data;
	struct s_garbage	*next;
}						t_garbage;

void	ft_garbage_init(void);
void	*ft_malloc(int size);
void	ft_garbage_clear(void);

#endif
