/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:23:58 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/13 10:42:32 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lenDest;

	i = 0;
	lenDest = ft_strlen(dest);
	if ((size == 0) || (lenDest > size))
		return (size + lenDest);
	while (src[i] && lenDest + i < size - 1)
	{
		dest[lenDest + i] = src[i];
		i++;
	}
	dest[lenDest + i] = '\0';
	return (lenDest + ft_strlen(src));
}
