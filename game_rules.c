/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feli-bar <feli-bar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:32:01 by feli-bar          #+#    #+#             */
/*   Updated: 2023/02/01 11:46:18 by feli-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

int	ft_init_game(t_mlx *window)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == NULL)
	{
		ft_print_error(ERROR_12"\n");
		return (1);
	}
	window->win_ptr = mlx_new_window(window->mlx_ptr, window->col * \
		PIXEL_SIZE, window->line * PIXEL_SIZE, "Tito is hungry!");
	if (window->win_ptr == NULL)
	{
		ft_print_error(ERROR_12"\n");
		return (1);
	}
	window->movements = 0;
	ft_put_sprites(window);
	window->player = window->player_down;
	mlx_hook(window->win_ptr, 2, (1L << 0), &ft_key_input, window);
	mlx_hook(window->win_ptr, 17, 0, &ft_close, window);
	mlx_loop_hook(window->mlx_ptr, &ft_show_map, window);
	mlx_loop(window->mlx_ptr);
	return (0);
}

void	ft_put_sprites(t_mlx *window)
{
	ft_sprites(window, &window->player_down, "images/player_01.xpm");
	ft_sprites(window, &window->player_right, "images/player_02.xpm");
	ft_sprites(window, &window->player_left, "images/player_03.xpm");
	ft_sprites(window, &window->player_up, "images/player_04.xpm");
	ft_sprites(window, &window->wall, "images/wall.xpm");
	ft_sprites(window, &window->collec, "images/collectable.xpm");
	ft_sprites(window, &window->floor, "images/floor.xpm");
	ft_sprites(window, &window->exit_c, "images/door_close.xpm");
	ft_sprites(window, &window->exit_o, "images/door_open.xpm");
}

void	ft_sprites(t_mlx *window, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(window->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{	
		ft_print_error(ERROR_13"\n");
		ft_close(window);
	}
}

int	ft_close(t_mlx *window)
{
	mlx_destroy_image(window->mlx_ptr, window->player_left);
	mlx_destroy_image(window->mlx_ptr, window->player_right);
	mlx_destroy_image(window->mlx_ptr, window->player_down);
	mlx_destroy_image(window->mlx_ptr, window->player_up);
	mlx_destroy_image(window->mlx_ptr, window->collec);
	mlx_destroy_image(window->mlx_ptr, window->exit_c);
	mlx_destroy_image(window->mlx_ptr, window->exit_o);
	mlx_destroy_image(window->mlx_ptr, window->wall);
	mlx_destroy_image(window->mlx_ptr, window->floor);
	ft_free_matrix(window->map);
	mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	mlx_destroy_display(window->mlx_ptr);
	free(window->mlx_ptr);
	exit (0);
	return (0);
}
