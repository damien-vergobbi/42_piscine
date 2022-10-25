/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 13:20:03 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/24 19:21:42 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINT_H
# define FT_POINT_H
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
void	set_point(t_point *point);
#endif
