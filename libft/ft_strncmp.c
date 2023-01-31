/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:43:32 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 09:00:55 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			s;
	unsigned char	*cmp1;
	unsigned char	*cmp2;

	cmp1 = ((unsigned char *)s1);
	cmp2 = ((unsigned char *)s2);
	s = 0;
	if (n == 0)
		return (0);
	while (cmp1[s] != '\0' && cmp2[s] != '\0' && n > s + 1)
	{
		if (cmp1[s] != cmp2[s])
			return (cmp1[s] - cmp2[s]);
		s++;
	}
	return (cmp1[s] - cmp2[s]);
}
