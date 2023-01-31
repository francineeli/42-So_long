/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:02:24 by feli-bar          #+#    #+#             */
/*   Updated: 2022/09/26 08:58:41 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(const char *s, char c)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_wlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *str, char c)
{
	int		index;
	int		count;
	int		str_len;
	char	**result;

	index = 0;
	count = ft_counter(str, c);
	result = (char **)malloc(sizeof (char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	while (*str && index < count)
	{
		while (*str == c)
			str++;
		if (*str != c)
		{
			str_len = ft_wlen(str, c);
			*(result + index) = ft_substr(str, 0, str_len);
			index++;
		}
		while (*str != c && *str)
			str++;
	}
	*(result + count) = NULL;
	return (result);
}
