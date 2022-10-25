/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_manager.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:03:29 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/17 17:36:27 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_MANAGER_H
# define PM_MANAGER_H

typedef struct s_pencil_mark
{
	char	*pm;
	char	*mc;
	int		size;
}			t_pencil_mark;

void	ft_delete_mark(t_pencil_mark *pm, int l, int c, int nb);
void	ft_reduce_count(t_pencil_mark *pm, int l, int c, int nb);
void	ft_set_cell(t_pencil_mark *pm, int l, int c, int nb);
void	ft_check_cell(t_pencil_mark *pm, int l, int c);

#endif
