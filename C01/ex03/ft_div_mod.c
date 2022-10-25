/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvergobb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 09:46:18 by dvergobb          #+#    #+#             */
/*   Updated: 2021/07/09 10:32:43 by dvergobb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	result;
	int	modulo;

	result = a / b;
	modulo = a % b;
	*div = result;
	*mod = modulo;
}
