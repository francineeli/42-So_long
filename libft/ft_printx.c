/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:32:20 by feli-bar          #+#    #+#             */
/*   Updated: 2022/10/25 11:09:50 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned long nb, int flag)
{
	int	counter;

	counter = 0;
	if (nb >= 16)
	{
		counter += ft_printx((nb / 16), flag);
		counter += ft_printx((nb % 16), flag);
	}
	else
	{
		if (flag == 'x')
			return (ft_printc(BASISLW[nb]));
		else
			return (ft_printc(BASISUP[nb]));
	}
	return (counter);
}
