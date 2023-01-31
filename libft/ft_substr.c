/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:34:57 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 09:01:43 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	len_s;
	size_t	i;

	i = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		start = len_s;
	if (len > len_s - start)
		len = len_s - start;
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (len_s > start)
	{
		while (s[start + i] && i < len)
		{
			dst[i] = s[start + i];
			i++;
		}	
	}		
	dst[i] = '\0';
	return (dst);
}
