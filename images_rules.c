/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:32:01 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/01 13:18:43 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_valid_walls(t_mlx *window)
{
	int	x;
	int	max;

	x = 0;
	max = window->col;
	if (window->col < window->line)
		max = window->line;
	while (x < max)
	{
		if (window->col - x > 0)
			if (window->map[0][x] != '1' || \
				window->map[window->line - 1][x] != '1')
				break ;
		if (window->line - x > 0)
			if (window->map[x][0] != '1' || \
				window->map[x][window->col - 1] != '1')
				break ;
		x++;
	}
	if (x != max)
	{
		ft_print_error(ERROR_4"\n");
		return (1);
	}
	return (0);
}

int	ft_check_characters(t_mlx *window, int e, int p, int invalid)
{
	if (ft_count_collectibles(window) == 1)
		ft_print_error(ERROR_9"\n");
	if (e != 1)
		ft_print_error(ERROR_8"\n");
	if (p != 1)
		ft_print_error(ERROR_7"\n");
	if (invalid > 0)
		ft_print_error(ERROR_10"\n");
	if (window->stars == 0 || e != 1 || p != 1 || invalid > 0)
		return (1);
	return (0);
}

int	ft_valid_character(t_mlx *window)
{
	int	y;
	int	x;
	int	p;
	int	e;
	int	invalid;

	p = 0;
	e = 0;
	invalid = 0;
	y = -1;
	while (window->map[++y] != NULL)
	{
		x = -1;
		while (++x < window->col)
		{
			if (window->map[y][x] == 'P')
				p++;
			else if (window->map[y][x] == 'E')
				e++;
			else if (window->map[y][x] != 'C' && window->map[y][x] != '0' \
				&& window->map[y][x] != '1')
				invalid++;
		}
	}
	return (ft_check_characters(window, e, p, invalid));
}

int	ft_check_path(char **copy, t_mlx *window)
{
	int	line;
	int	col;
	int	exit;
	int	collec;

	line = 0;
	exit = 0;
	collec = 0;
	col = 0;
	while (copy[line] != NULL)
	{
		col = 0;
		while (col < window->col)
		{
			if (copy[line][col] == 'E' && exit == 0)
				exit = 1;
			if (copy[line][col] == 'C' && collec == 0)
				collec = 1;
			col++;
		}
		line++;
	}
	return (ft_check_exit(exit, collec));
}

void	ft_test_path(char **copy, int line, int col, t_mlx *window)
{
	if (copy[line][col] == 'X' || copy[line][col] == '1' || \
	copy[line][col] == 'S')
		return ;
	if (copy[line][col] == 'E')
	{
		copy[line][col] = 'S';
		return ;
	}
	else
		copy[line][col] = 'X';
	ft_test_path(copy, line - 1, col, window);
	ft_test_path(copy, line + 1, col, window);
	ft_test_path(copy, line, col - 1, window);
	ft_test_path(copy, line, col + 1, window);
}
