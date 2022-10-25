/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 23:56:23 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/27 00:06:08 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

int	ft_nbr_del(int n)
{
	int		d;

	d = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++d;
	}
	return (d);
}

char	*ft_plus_int(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 1));
	if (ss != 0)
	{
		ss[len] = '\0';
		len--;
		while (len >= 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (NULL);
}

char	*ft_mius_int(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 2));
	if (ss != 0)
	{
		len++;
		ss[len] = '\0';
		len--;
		ss[0] = '-';
		while (len > 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*ss;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbr_del(n);
	if (n >= 0)
		return (ss = ft_plus_int(n, len));
	return (ss = ft_mius_int((n * -1), len));
}
