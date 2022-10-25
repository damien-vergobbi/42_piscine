/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 08:37:00 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/12 19:54:26 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		k = 0;
		while (str[i + k] && str[i + k] == to_find[k])
		{
			if (!(to_find[k + 1]))
				return (&str[i]);
			++k;
		}
		++i;
	}
	return (0);
}
