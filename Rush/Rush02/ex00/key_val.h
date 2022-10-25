/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_val.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:28:16 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/25 16:05:32 by mberdrin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_VAL_H
# define KEY_VAL_H
typedef struct s_key_val
{
	char	*key;
	char	*val;
}	t_key_val;

char	*ft_to_find(t_key_val *tab, char *str, int n);

#endif
