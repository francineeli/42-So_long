/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>     #+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:53:55 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/25 11:09:15 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	len_nbr(char *strn, unsigned int n, size_t size)
{
	strn[size] = '\0';
	size--;
	if (n >= 0)
	{
		while (size)
		{
			strn[size] = (n % 10) + '0';
			n = n / 10;
			size--;
		}
		strn[size] = n + '0';
	}
	else
	{
		while (size)
		{
			strn[size] = (n % 10) * -1 + '0';
			n = n / 10;
			size--;
		}
		strn[size] = '-';
	}
}

int	ft_printu(unsigned int nb)
{
	size_t	size;
	char	*result;
	int		aux;

	if (nb >= 0)
	{
		size = 1;
		aux = nb / 10;
	}
	else
		return (ft_prints("(null)"));
	while (aux)
	{
		size++;
		aux = aux / 10;
	}
	result = (char *)malloc(size + 1);
	if (!result)
		return (0x0);
	len_nbr(result, nb, size);
	ft_prints(result);
	free (result);
	return (size);
}
