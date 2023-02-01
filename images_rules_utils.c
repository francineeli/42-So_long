/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_rules_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:32:01 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/01 13:19:35 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_count_lines(int fd, char *temp, t_mlx *window)
{
	int		count_line_break;

	count_line_break = 0;
	window->line = 0;
	window->col = ft_count_col (temp);
	while (temp != NULL)
	{
		if (temp[0] != '\n' && count_line_break == 0)
			window->line++;
		else if (temp[0] != '\n' && count_line_break != 0)
			return (ft_close_and_free(fd, temp));
		else if (temp[0] == '\n')
			count_line_break++;
		free(temp);
		temp = get_next_line(fd);
		if (temp && temp[0] != '\n' && window->col != ft_count_col(temp))
			return (ft_close_and_free(fd, temp));
	}
	close (fd);
	return (0);
}

int	ft_count_col(char *temp)
{
	int	i;

	i = 0;
	while (temp != NULL && temp[i] != 0 && temp[i] != '\n' && temp[i] != '\r')
		i++;
	return (i);
}

int	ft_count_collectibles(t_mlx *window)
{
	int	x;
	int	y;

	window->stars = 0;
	y = 0;
	while (window->map[y] != NULL)
	{
		x = 0;
		while (window->map[y][x] != '\0')
		{
			if (window->map[y][x] == 'C')
			{
				window->stars = window->stars + 1;
			}
			x++;
		}
		y++;
	}
	if (window->stars == 0)
		return (1);
	else
		return (0);
}

int	ft_check_exit(int exit, int collec)
{
	if (exit != 0)
		ft_print_error(ERROR_5"\n");
	if (collec != 0)
		ft_print_error(ERROR_6"\n");
	if (exit != 0 || collec != 0)
		return (1);
	return (0);
}

int	ft_close_and_free(int fd, char *temp)
{
	ft_print_error(ERROR_3"\n");
	free(temp);
	close(fd);
	return (1);
}
