/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:25:23 by jalamell          #+#    #+#             */
/*   Updated: 2021/07/25 18:17:08 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "key_val.h"
#include "ft_garbage.h"
typedef t_garbage	t_list;

int	ft_list_add(t_list ***list, char *str)
{
	if (str == 0)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	**list = ft_malloc(sizeof(t_list));
	if (**list == 0)
		return (1);
	(**list)->data = str;
	*list = &((**list)->next);
	return (0);
}

char	*ft_gen_str(char s, int pow)
{
	char	*ret;

	ret = ft_malloc((pow + 1) * sizeof(char));
	if (ret)
	{
		ret[0] = s;
		while (pow)
			ret[pow--] = '0';
	}
	return (ret);
}

int	ft_setup_value(char *str, t_key_val *dict, t_list **ret, int len)
{
	int		lcur;

	while (len)
	{
		if (*str == '0')
		{
			++str;
			--len;
		}
		else
		{
			lcur = (len - 1) % 3 + 1;
			len -= lcur;
			while (lcur)
			{
				if (lcur == 3)
				{
					if (ft_list_add(&ret, ft_to_find(dict, str, 1)))
						return (1);
					if (ft_list_add(&ret, ft_to_find(dict, ft_gen_str('1', 2), 3)))
						return (1);
				}
				else if (lcur == 2 && *str >= '2')
				{
					if (ft_list_add(&ret, ft_to_find(dict, ft_gen_str(*str, 1), 2)))
						return (1);
				}
				else
				{
					if (ft_list_add(&ret, ft_to_find(dict, str, lcur)))
						return (1);
					if (lcur == 2)
					{
						++str;
						--lcur;
					}
				}
				++str;
				--lcur;
			}
			if (ft_list_add(&ret, ft_to_find(dict, ft_gen_str('1', len), len + 1)))
				return (1);
		}
	}
	return (0);
}

int	ft_print_value(char *str, t_key_val *dict)
{
	t_list	*list;
	int		len;

	len = 0;
	while (str[len])
		++len;
	list = 0;
	if (ft_setup_value(str, dict, &list, len))
		return (1);
	while (list)
	{
		len = 0;
		while (((char *)(list->data))[len])
			++len;
		write(1, list->data, len);
		list = list->next;
		if (list)
			write(1, " ", 1);
	}
	return (0);
}
